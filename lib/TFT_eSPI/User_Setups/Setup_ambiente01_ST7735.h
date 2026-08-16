// ADDED for Ambiente-01: Setup for 1.8" ST7735-like display
#define USER_SETUP_ID 701

#define ST7735_DRIVER

#define TFT_WIDTH 128
#define TFT_HEIGHT 160

#define TFT_MOSI PIN_SPI_MOSI
#define TFT_SCLK PIN_SPI_SCK
#define TFT_CS   PIN_TFT_CS
#define TFT_DC   PIN_TFT_DC
#define TFT_RST  PIN_TFT_RST
#define TFT_BL   PIN_TFT_BL

// Touch controller (if present on the module)
#define TOUCH_CS PIN_TOUCH_CS
#define TOUCH_IRQ PIN_TOUCH_IRQ

#define LOAD_GFXFF
#define SMOOTH_FONT

#define SPI_FREQUENCY  27000000
