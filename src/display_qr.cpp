#include "display_qr.h"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void displayQRInit(){
  u8g2.begin();
}

void displayQRCodeScreen(QRCode qrcode){
  u8g2.clearBuffer();
  u8g2.setDrawColor(1);
  u8g2.setFont(u8g2_font_5x7_tr);
  u8g2.drawStr(4, 14, "PARA MAIS");
  u8g2.drawStr(4, 24, "INFOS");
  u8g2.drawHLine(4, 29, 56);
  u8g2.setFont(u8g2_font_4x6_tr);
  u8g2.drawStr(4, 40, "ESCANEIE");
  u8g2.drawStr(4, 48, "AO LADO");
  // Seta 
  u8g2.drawHLine(10, 57, 16);
  u8g2.drawTriangle(26, 53, 26, 61, 32, 57);

  // QRcode 
  u8g2.setDrawColor(1);
  u8g2.drawBox(64, 0, 64, 64);
  u8g2.setDrawColor(0); 
  const int escala  = 2;
  const int xOffset = 67; 
  const int yOffset = 3; 
  for (uint8_t y = 0; y < qrcode.size; y++) {
    for (uint8_t x = 0; x < qrcode.size; x++) {
      if (qrcode_getModule(&qrcode, x, y)) {
        u8g2.drawBox(xOffset + (x * escala), yOffset + (y * escala), escala, escala);
      }
    }
  }
  u8g2.sendBuffer();
  
}