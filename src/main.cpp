#include <Arduino.h>
#include <U8g2lib.h>

// Construtor Software SPI para PCD8544 (84x48)
// Ordem dos pinos: U8G2_PCD8544_84X48_F_4W_SW_SPI(rotacao, clock, data, cs, dc, reset)
U8G2_PCD8544_84X48_F_4W_SW_SPI u8g2(
  U8G2_R0, 
  /* clock=*/ 18, 
  /* data=*/  23, 
  /* cs=*/    4, 
  /* dc=*/    5, 
  /* reset=*/ 22
);

#define PIN_BL 15

void setup() {
  Serial.begin(115200);

  // Backlight
  pinMode(PIN_BL, OUTPUT);
  digitalWrite(PIN_BL, HIGH); // se não acender, troque para LOW

  u8g2.begin();
  u8g2.setContrast(140); // Na U8g2 a escala vai de 0 a 255 (120 a 160 costuma ser ideal)
}

void loop() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 12, "U8G2 TESTE");
  u8g2.drawFrame(0, 16, 84, 30);
  u8g2.drawBox(4, 20, 76, 10);
  u8g2.sendBuffer();

  delay(1000);
}