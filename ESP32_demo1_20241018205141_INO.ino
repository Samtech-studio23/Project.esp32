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
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  NOTE: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYN#K_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6nCtY60BR"
#define BLYNK_TEMPLATE_NAME "home automation demo"
#define BLYNK_AUTH_TOKEN "5EN2zoEzRuIE6occCyyj3K94nttxsIQj"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
char ssid[] = "B&S Fashion Store";
char pass[] = "weldingtig200";

const int relayPin = 2;  // GPIO 2 for the relay
const int switchPin = 22; // GPIO 4 for the manual switch

bool bulbState = false; // Track the state of the bulb

void setup() {
  Serial.begin(9600);
  
  pinMode(relayPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP); // Use internal pull-up resistor

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();

  // Read the state of the manual switch
  if (digitalRead(switchPin) == LOW) { // Switch is pressed
    bulbState = !bulbState; // Toggle bulb state
    digitalWrite(relayPin, bulbState ? HIGH : LOW); // Control relay
    Blynk.virtualWrite(V0, bulbState); // Update Blynk UI (virtual pin V0)
    delay(500); // Debounce delay
  }
}
