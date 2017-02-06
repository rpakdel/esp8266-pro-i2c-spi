#pragma once

// ESP8266-PRO uses ESP8266EX chip
// http://www.liot.io/hardware/planning/


#define GPIO0 0
#define GPIO1 1
#define GPIO2 2
#define GPIO3 3
#define GPIO4 4
#define GPIO5 5
#define GPIO6 6
#define GPIO7 7
#define GPIO8 8
#define GPIO9 9
#define GPIO10 10
#define GPIO11 11
#define GPIO12 12
#define GPIO13 13
#define GPIO14 14
#define GPIO15 15
#define GPIO16 16

#define RX0 GPIO3
#define TX0 GPIO1

#define RX1 GPIO8
#define TX1 GPIO2

#define SDIO_CLK GPIO6
#define SDIO_D0 GPIO7
#define SDIO_D1 GPIO8
#define SDIO_D2 GPIO9
#define SDIO_D3 GPIO10
#define SDIO_CMD GPIO11

#define HSPI_CLK GPIO14
#define HSPI_MISO GPIO12
#define HSPI_MOSI GPIO13
#define HSPI_CS GPIO15

#define SPI_CLK GPIO6
#define SPI_MISO GPIO7
#define SPI_MOSI GPIO8
#define SPI_CS GPIO11

#define I2C_SCL GPIO14
#define I2C_SDA GPIO2

#define XPD_DCDC GPIO16

#define WIFI_LED GPIO0
#define LINK_LED GPIO12