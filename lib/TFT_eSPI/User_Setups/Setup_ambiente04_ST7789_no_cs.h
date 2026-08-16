// ADDED for Ambiente-04: Setup for ST7789 240x240 with no CS
#define USER_SETUP_ID 704

#define ST7789_DRIVER

#define TFT_WIDTH 240
#define TFT_HEIGHT 240

#define TFT_MOSI PIN_SPI_MOSI
#define TFT_SCLK PIN_SPI_SCK
#define TFT_CS   -1
#define TFT_DC   PIN_TFT_DC
#define TFT_RST  PIN_TFT_RST
#define TFT_BL   PIN_TFT_BL

#define LOAD_GFXFF
#define SMOOTH_FONT

#define SPI_FREQUENCY  40000000
