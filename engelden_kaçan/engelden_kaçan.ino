#include "engelden_kaçan.h"

void setup() {
   Serial.begin(9600);
  // PID kontrolünü başlat
  myPID.SetMode(AUTOMATIC);
  pin_mode();
}

void loop() {

   // Sensör değerini oku
  input = analogRead(A0);

  // PID kontrolünü güncelle
  myPID.Compute();

  // Çıkış değerini kullanarak motorlara sinyal gönder veya başka işlemler yap
  // Örneğin analogWrite(motorPin, output);

  delay(100);

  mesafe_sartlari_1();
  mesafe_sartlari_2();

  ileri();
  geri();
  sag();
  sol();
}
