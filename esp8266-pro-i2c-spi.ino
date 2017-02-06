/* 
* RobotDyn ESP8266-PRO with I2C and SPI connections
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include <ESP8266WiFi.h>
#include <SSD1306AsciiWire.h>

#include "myssid.h"
#include "esp8266-pro-pins.h"

// GPIO15 -> GND with 4.7k resistor
// EN -> 3.3v with 10k resistor
// GPIO0 -> GND to flash/program
// GPIO0 -> 3.3v to run normally

// OLED SDA -> GPIO4
// OLED SCK -> GPIO5
SSD1306AsciiWire oled;

// RF SCK  -> GPIO14
// RF MISO -> GPIO12
// RF MOSI -> GPIO13
#define CEPIN GPIO16
#define CSPIN GPIO15 // to GND with 4.7k resistor

RF24 radio(CEPIN, CSPIN);
byte addresses[][6] = { "1Node" };

WiFiServer server(80);

void initDisplay()
{
    Serial.println(F("Init OLED"));
    Wire.begin(GPIO4, GPIO5);
    oled.begin(&Adafruit128x64, 0x3C);
    oled.setFont(Adafruit5x7);
    oled.clear();
    oled.setCursor(0, 0);
}

void initWiFi()
{
    // Connect to WiFi network
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(MYSSID);

    WiFi.begin(MYSSID, MYPASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");

    // Start the server
    server.begin();
    Serial.println("Server started");

    // Print the IP address
    Serial.println(WiFi.localIP());
    oled.println(WiFi.localIP());
}

void initRadio()
{
    radio.begin();
    radio.setPALevel(RF24_PA_MIN);
    radio.setAutoAck(1);
    radio.setRetries(15, 15);
    radio.openReadingPipe(0, addresses[0]);
    radio.startListening();
}

void checkRadio()
{
    if (radio.available())
    {
        uint8_t buffer;
        radio.read((uint8_t*)&buffer, sizeof(uint8_t));
        Serial.print(F("Receiver: "));
        Serial.println(buffer);
        oled.setCursor(0, 1);
        oled.print(F("Receiver: "));
        oled.print(buffer);
    }
}

void setup()
{
    Serial.begin(9600);
    initDisplay();
    initRadio();
    initWiFi();
}

void loop()
{
    checkRadio();
}
