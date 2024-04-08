#include <Arduino.h>
#include "BluetoothSerial.h"

String device_name = "ESP32-BT-Slave";
String text;
// Check if Bluetooth is available
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
  #error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Check Serial Port Profile
#if !defined(CONFIG_BT_SPP_ENABLED)
  #error Serial Port Profile for Bluetooth is not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

void sendData(String a) {
  uint8_t buf[a.length()];
  memcpy(buf,a.c_str(),a.length());
  SerialBT.write(buf,a.length());
  SerialBT.println(); 
}

int pinComC = 13;
int pinComD = 12;
int pinComE = 14;
int pinComF = 27;

void setup() {
  Serial.begin(115200);
  pinMode(pinComC, OUTPUT);
  pinMode(pinComD, OUTPUT);
  pinMode(pinComE, OUTPUT);
  pinMode(pinComF, OUTPUT);
  SerialBT.begin(device_name); //Bluetooth device name
  //SerialBT.deleteAllBondedDevices(); // Uncomment this to delete paired devices; Must be called after begin
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
}

void loop() {
  if (SerialBT.available()) {
    text = (char)SerialBT.read();
    Serial.println(text);
    if(text == "a") {
      digitalWrite(pinComC, HIGH);
      delay(1000);
      digitalWrite(pinComC, LOW);
      Serial.println("Ho inviato c");
    }
    if(text == "b") {
      digitalWrite(pinComD, HIGH);
      delay(1000);
      digitalWrite(pinComD, LOW);
      Serial.println("Ho inviato d");
    }
    if(text == "c") {
      digitalWrite(pinComE, HIGH);
      delay(1000);
      digitalWrite(pinComE, LOW);
      Serial.println("Ho inviato e");
    }
    if(text == "d") {
      digitalWrite(pinComF, HIGH);
      delay(1000);
      digitalWrite(pinComF, LOW);
      Serial.println("Ho inviato f");
    }
  }
}






