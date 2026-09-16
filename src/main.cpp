#include <Arduino.h>
#include <qrcode.h>
#include "display_qr.h"

QRCode qrcode;
const char* qrTexto = "https://phsecchi.github.io/";

void setup() {
  Serial.begin(115200);
  displayQRInit();

  uint8_t qrcodeData[qrcode_getBufferSize(3)];
  qrcode_initText(&qrcode, qrcodeData, 3, ECC_LOW, qrTexto);
  displayQRCodeScreen(qrcode);
}

void loop() {
}