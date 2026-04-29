# Bluetooth-RC-Car-L9110 🏎️

Bu proje, Arduino Nano ve HC-06 Bluetooth modülü kullanılarak geliştirilmiş, akıllı telefon üzerinden kontrol edilebilen bir robot araç projesidir.

## 🛠️ Malzeme Listesi
- Arduino Nano
- HC-06 Bluetooth Modülü
- L9110 Motor Sürücü
- 2x 6V DC Motor & Tekerlek
- 2x 18650 Li-ion Pil
- Mini Breadboard & Şase

## 👨‍💻 Geliştirici
- Murat Kamilçelebi - Marmara Üniversitesi Mekatronik Mühendisliği

## 🔌 Bağlantı Şeması

1. ARDUINO NANO -> HC-06 BLUETOOTH
   5V  -> VCC
   GND -> GND
   D10 -> TXD
   D11 -> RXD

2. ARDUINO NANO -> L9110 MOTOR SÜRÜCÜ
   D3  -> IA1 (PWM)
   D4  -> IA2
   D5  -> IB1 (PWM)
   D6  -> IB2

3. GÜÇ BAĞLANTISI
   Pil (+) -> L9110 VCC & Nano VIN
   Pil (-) -> L9110 GND & Nano GND (Ortak Şase!)
