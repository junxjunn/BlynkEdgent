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
#define BLYNK_TEMPLATE_NAME "Relay Controller"

#define BLYNK_FIRMWARE_VERSION "0.1.2"

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
#include "time.h"
#include <WiFi.h>

String firmware_version = "0.1.2";
const char* ntpServer = "pool.ntp.org";
const long gmtOffset = 28800;
const int daylightOffset = 0;

void setup() {
  WiFi.begin();
  Serial.begin(115200);
  delay(100);

  //NTPClient
  configTime(gmtOffset, daylightOffset, ntpServer);
  time_t current_time;
  struct tm* time_info;
  char dateTimeNow[50];
  char dateNow[50];
  char timeNow[50];

  time(&current_time);
  time_info = localtime(&current_time);
  strftime(dateTimeNow, sizeof(dateTimeNow), "%d %B %Y %H:%M:%S", time_info);
  strftime(dateNow, sizeof(dateNow), "%d %B %Y", time_info);
  strftime(timeNow, sizeof(timeNow), "%H:%M:%S", time_info);
  Serial.println(dateTimeNow);
  
  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();

time_t current_time;
  struct tm* time_info;
  char dateTimeNow[50];
  char dateNow[50];
  char timeNow[50];

  time(&current_time);
  time_info = localtime(&current_time);

  strftime(dateTimeNow, sizeof(dateTimeNow), "%d %B %Y %H:%M:%S", time_info);
  strftime(dateNow, sizeof(dateNow), "%d %B %Y", time_info);
  strftime(timeNow, sizeof(timeNow), "%H:%M:%S", time_info);


  Blynk.virtualWrite(V99, firmware_version);
  Blynk.virtualWrite(V70, dateNow);
  Blynk.virtualWrite(V71, timeNow);

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Wifi connected");
  }
}
