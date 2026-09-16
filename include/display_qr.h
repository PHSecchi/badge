#ifndef DISPLAY_QR_H
#define DISPLAY_QR_H

#include <Arduino.h>
#include <U8g2lib.h>
#include <qrcode.h>

void displayQRInit();

void displayQRCodeScreen(QRCode qrcode);

#endif