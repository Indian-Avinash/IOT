#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include <DallasTemperature.h>
#include SoftwareSerial.h
#define REPORTING_PERIOD_MS     1000
#define ONE_WIRE_BUS 7 
 
SoftwareSerial gsm(11,12);
// Create a PulseOximeter object
PulseOximeter pox;
#define Switch 7
int value_switch;
// Time at which the last beat occurred
uint32_t tsLastReport = 0;
OneWire oneWire(ONE_WIRE_BUS); 
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
// Callback routine is executed when a pulse is detected
void onBeatDetected() {
    Serial.println("♥ Beat!");
}

void setup() {
    Serial.begin(9600);
    gsm.begin(9600);
    pinMode(Switch,INPUT);
    Serial.print("Initializing pulse oximeter..");
   sensors.begin();
   pinMode(Switch,INPUT_PULLUP); 

    // Initialize sensor
    if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
        Serial.println("SUCCESS");
    }

  // Configure sensor to use 7.6mA for LED drive
  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);

    // Register a callback routine
    pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop() {
    // Read from the sensor

// sensors.requestTemperatures(); // Send the command to get temperature readings 
/********************************************************************/
 Serial.print("Temperature is: "); 
 Serial.println(sensors.getTempCByIndex(0));
    pox.update();
    value_switch = digitalRead(Switch);

    // Grab the updated heart rate and SpO2 levels
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        Serial.print("Heart rate:");
        Serial.print(pox.getHeartRate());
        Serial.print("bpm / SpO2:");
        Serial.print(pox.getSpO2());
        Serial.println("%");

        tsLastReport = millis();
    }

value_switch = digitalRead(Switch);
if (value_switch==0){
    gsm.println("AT+CMGS=\"+919390291253\"\r");
    delay(1000);
    gsm.println("I am in danger save me");
    delay(100);
    Serial.println("SMS Sent");
}
}
