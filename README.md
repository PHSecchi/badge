# Badge — BSides Curitiba 2026

Crachá eletrônico interativo desenvolvido para a conferência de segurança da informação **BSides Curitiba 2026**.

## 📌 Visão Geral

O dispositivo opera com um microcontrolador ESP32 gerenciando dois displays simultâneos:
- **Display LCD 16x2:** Exibição alfanumérica de credencial (nome do participante, handle e status).
- **Display OLED 0.96" (I2C):** Renderização local de um QR Code apontando para o portfólio pessoal, calculado e gerado em tempo de execução diretamente pelo firmware.

---

## 🛠️ Hardware Utilizado

* **Microcontrolador:** ESP32 DevKit V1 (30 pinos)
* **Display 1:** Módulo LCD 16x2 (Interface paralela / I2C backpack)
* **Display 2:** Módulo OLED 0.96" SSD1306 (Barramento I2C, 128x64)
* **Alimentação:** Bateria Li-Ion 

---

## 💻 Firmware & Bibliotecas

* **Geração de QR Code:** Biblioteca em C/C++ embarcada para cálculo matricial do QR code diretamente na memória do ESP32 (sem dependência de APIs externas ou conexão de rede ativa).
* **Comunicação OLED:** `U8g2`.
* **Controle LCD:** `LiquidCrystal` (ou `LiquidCrystal_I2C`).
