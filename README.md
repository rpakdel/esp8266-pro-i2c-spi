# RobotDyn ESP8266-PRO I2C (oled) and SPI (nrf24l01) test

## Wiring

**ESP8266**

1. GPIO15 -> GND with 4.7k resistor
2. EN -> 3.3v with 10k resistor
3. GPIO0 -> GND to flash/program
4. GPIO0 -> 3.3v to run normally

**I2C OLED**

1. OLED SDA -> GPIO4
2. OLED SCK -> GPIO5

**NRF24L01**

1. RF SCK  -> GPIO14
2. RF MISO -> GPIO12
3. RF MOSI -> GPIO13
4. RF CE -> GPIO16
5. RF CSN -> GPIO15 (and to GND via 4.7k resistor) 

Use https://github.com/rpakdel/arduino-nrf24-basic/tree/master/sender for sender