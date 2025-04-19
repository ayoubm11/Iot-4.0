#include <DHT.h>

#define DHTPIN 2         // Broche DATA du DHT22, conforme au schéma
#define DHTTYPE DHT22    // Type de capteur
#define VIBRATION_PIN 3  // Bouton poussoir = vibration

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(VIBRATION_PIN, INPUT_PULLUP);
}

void loop() {
  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("Erreur lecture température !");
  } else {
    Serial.print("Température : ");
    Serial.print(temp);
    Serial.println(" °C");
  }

  if (digitalRead(VIBRATION_PIN) == LOW) {
    Serial.println("Vibration détectée !");
  } else {
    Serial.println("Aucune vibration.");
  }

  delay(2000);
}
