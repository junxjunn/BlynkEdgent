/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
 *************************************************************
  Blynk.Edgent implements:
  - Blynk.Inject - Dynamic WiFi credentials provisioning
  - Blynk.Air    - Over The Air firmware updates
  - Device state indication using a physical LED
  - Credentials reset using a physical Button
 *************************************************************/

/* Fill in information from your Blynk Template here */
/* Read more: https://bit.ly/BlynkInject */

#define BLYNK_TEMPLATE_ID "TMPL6Z2K1yh-z"
#define BLYNK_TEMPLATE_NAME "LilyGo Edgent Testing Template"

#define BLYNK_FIRMWARE_VERSION "0.1.2"
String firmware_version = "0.1.2";

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
#define USE_ESP32_DEV_MODULE
//#define USE_ESP32C3_DEV_MODULE
//#define USE_ESP32S2_DEV_KIT
//#define USE_WROVER_BOARD
//#define USE_TTGO_T7
//#define USE_TTGO_T_OI

#include "BlynkEdgent.h"

int R1 = 5; //v0.1.2 changed from pin 21 to pin 5
int R2 = 18; //v0.1.2 changed from pin 19 to pin 18
int R3 = 19; //v0.1.2 changed from pin 18 to pin 19
int R4 = 21; //v0.1.2 changed from pin 5 to pin 21

int S1 = 0;
int S2 = 0;
int S3 = 0;
int S4 = 0;

void setup() {
  Serial.begin(115200);
  delay(100);

  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);

  digitalWrite(R1, 0);
  digitalWrite(R2, 0);
  digitalWrite(R3, 0);
  digitalWrite(R4, 0);

  BlynkEdgent.begin();
  Blynk.connect();
  Blynk.virtualWrite(V99, firmware_version);
}

BLYNK_CONNECTED() {
  Blynk.syncAll();
}

BLYNK_WRITE(V0) {
  int S1z = param.asInt();
  S1 = S1z;
}

BLYNK_WRITE(V1) {
  int S2z = param.asInt();
  S2 = S2z;
}

BLYNK_WRITE(V2) {
  int S3z = param.asInt();
  S3 = S3z;
}

BLYNK_WRITE(V3) {
  int S4z = param.asInt();
  S4 = S4z;
}

void loop() {
  BlynkEdgent.run();
  Blynk.run();

  digitalWrite(R1, S1);
  digitalWrite(R2, S2);
  digitalWrite(R3, S3);
  digitalWrite(R4, S4);
}
