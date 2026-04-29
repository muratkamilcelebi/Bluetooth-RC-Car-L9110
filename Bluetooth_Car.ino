#include <SoftwareSerial.h>

// Motor Pinleri (L9110)
const int motorA1 = 3; 
const int motorA2 = 4; 
const int motorB1 = 5; 
const int motorB2 = 6; 

// Bluetooth Pinleri (TX->10, RX->11)
SoftwareSerial bluetooth(10, 11); 

const int arabaHizi = 200; 

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  
  bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Yonler takas edildi! Hahovvv hazır!");
}

void loop() {
  if (bluetooth.available()) {
    char gelenVeri = bluetooth.read();

    if (gelenVeri == 'F') ileri();
    else if (gelenVeri == 'B') geri();
    else if (gelenVeri == 'L') sola(); // L gelince sola() fonksiyonuna git
    else if (gelenVeri == 'R') saga(); // R gelince saga() fonksiyonuna git
    else if (gelenVeri == 'S') dur();
  }
}

// --- HAREKET FONKSİYONLARI (SAĞ-SOL TAKAS EDİLDİ) ---

void ileri() {
  analogWrite(motorA1, arabaHizi); digitalWrite(motorA2, LOW);
  analogWrite(motorB1, arabaHizi); digitalWrite(motorB2, LOW);
}

void geri() {
  digitalWrite(motorA1, LOW); analogWrite(motorA2, arabaHizi);
  digitalWrite(motorB1, LOW); analogWrite(motorB2, arabaHizi);
}

void saga() {
  // Burayı SOLA dönüş yapacak şekilde güncelledim
  digitalWrite(motorA1, LOW); analogWrite(motorA2, 230);
  analogWrite(motorB1, 230); digitalWrite(motorB2, LOW);
}

void sola() {
  // Burayı SAĞA dönüş yapacak şekilde güncelledim
  analogWrite(motorA1, 230); digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW); analogWrite(motorB2, 230);
}

void dur() {
  digitalWrite(motorA1, LOW); digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW); digitalWrite(motorB2, LOW);
}