// ADDED for Ambiente-02: Setup for ST7789 240x320
#define USER_SETUP_ID 702

#define ST7789_DRIVER

#define TFT_WIDTH 240
#define TFT_HEIGHT 320

#define TFT_MOSI PIN_SPI_MOSI
#define TFT_SCLK PIN_SPI_SCK
#define TFT_CS   PIN_TFT_CS
#define TFT_DC   PIN_TFT_DC
#define TFT_RST  PIN_TFT_RST
#define TFT_BL   PIN_TFT_BL

// Touch controller (if present on the module)
#define TOUCH_CS PIN_TOUCH_CS
#define TOUCH_IRQ -1

#define LOAD_GFXFF
#define SMOOTH_FONT

#define SPI_FREQUENCY  40000000
