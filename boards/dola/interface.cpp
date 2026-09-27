#ifndef JOY_X
#define JOY_X 12
#endif
#ifndef JOY_Y
#define JOY_Y 13
#endif
#ifndef TFT_BL
#define TFT_BL 4
#endif

volatile bool upPress_flag = false;
volatile bool downPress_flag = false;
volatile bool leftPress_flag = false;
volatile bool rightPress_flag = false;
volatile bool slPress_flag = false;

enum JoyDirection { JOY_NONE, JOY_LEFT, JOY_RIGHT, JOY_UP, JOY_DOWN };
JoyDirection currentDirection = JOY_NONE;

unsigned long lastReadTime = 0;
unsigned long lastMoveTime = 0;
bool firstRepeat = true;

bool lastButtonReading = HIGH;
bool stableButtonState = HIGH;
unsigned long lastDebounceTime = 0;

// Variáveis do ENCODER
volatile long encoderPosition = 0;
int lastCLK;
int lastDT;

void _setup_gpio() {
  pinMode(SEL_BTN, INPUT_PULLUP);
  pinMode(JOY_X, INPUT);
  pinMode(JOY_Y, INPUT);
  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);

  // ✅ BACKLIGHT — Método correto para ESP32-S3
  ledcAttach(TFT_BL, 5000, 8);
  ledcWrite(TFT_BL, 255);  // Liga no MÁXIMO ao iniciar

  // ✅ ENCODER
  pinMode(ENCODER_CLK, INPUT_PULLUP);
  pinMode(ENCODER_DT, INPUT_PULLUP);
  pinMode(ENCODER_BTN, INPUT_PULLUP);
  pinMode(ESC_BTN, INPUT_PULLUP);
  lastCLK = digitalRead(ENCODER_CLK);
  lastDT = digitalRead(ENCODER_DT);

  bruceConfig.colorInverted = 0;
  bruceConfigPins.rotation = 0;  // Ajusta depois conforme a tela
}

void _post_setup_gpio() {}

int getBattery() {
  return Battery_information::getBatteryPercent();
}

// ✅ BRILHO — ledcWrite em vez de analogWrite
void _setBrightness(uint8_t brightval) {
  uint32_t duty = brightval;
  if (brightval <= 100) {
    duty = map((long)brightval, 0L, 100L, (long)MINBRIGHT, 255L);
  }
  ledcWrite(TFT_BL, duty);
}

// ✅ LEITURA DO ENCODER
int readEncoder() {
  int currentCLK = digitalRead(ENCODER_CLK);
  int currentDT = digitalRead(ENCODER_DT);
  int mudanca = 0;

  if (currentCLK != lastCLK) {
    if (currentDT != currentCLK) {
      encoderPosition++;
      mudanca = 1;
    } else {
      encoderPosition--;
      mudanca = -1;
    }
    lastCLK = currentCLK;
    lastDT = currentDT;
  }
  return mudanca;
}

int smoothAnalogRead(uint8_t pin) {
  long total = 0;
  for (int i = 0; i < 4; i++) {
    total += analogRead(pin);
  }
  return total / 4;
}
