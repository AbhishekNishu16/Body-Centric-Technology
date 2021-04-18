/*Body Centric Technology
 * TapDance: Final prototype
 * By Clinton & Nishu
  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

int ledpin1 = 3;
int ledpin2 = 5;
int ledpin3 = 7;
int ledpin4 = 9;
int ledpin5 = 11;

//
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

AudioPlaySdWav           playSdWav1;
AudioOutputI2S           i2s1;
AudioConnection          patchCord1(playSdWav1, 0, i2s1, 0);
AudioConnection          patchCord2(playSdWav1, 1, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;

// Use these with the Teensy Audio Shield
#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  
  Serial.begin(9600);

  AudioMemory(8);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
  delay(1000);
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(ledpin3, OUTPUT);
  pinMode(ledpin4, OUTPUT);
  pinMode(ledpin5, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue1 = analogRead(A0); //14, 16, 18, 20, 22
  int sensorValue2 = analogRead (A2);
  int sensorValue3 = analogRead (A4);
  int sensorValue4 = analogRead (A6);
  int sensorValue5 = analogRead (A8);
  
  // print out the value you read:
  Serial.println(sensorValue1);
  //Serial.println(sensorValue2);
  
//Sensor 1
  if(sensorValue1 > 1000 ) {
    
    if (playSdWav1.isPlaying() == false) {
       Serial.println("Start playing");
      playSdWav1.play("kick.WAV");
      delay(10); // wait for library to parse WAV info
    }
    
    digitalWrite(ledpin1, HIGH);
     Serial.print("Value 1"); // send the letter T (for Trigger) once the sensor value is bigger than 200
   
  }
 
 else {
    digitalWrite(ledpin1, LOW);
    }

//Sensor 2
    if(sensorValue2 > 1000) {
          if (playSdWav1.isPlaying() == false) {
       Serial.println("Start playing");
      playSdWav1.play("kick.WAV");
      delay(10); // wait for library to parse WAV info
    }
    
    digitalWrite(ledpin2, HIGH);
    Serial.print("value 2"); // send the letter T (for Trigger) once the sensor value is bigger than 200  
  }

  else {
    digitalWrite(ledpin2, LOW);
    }

//Sensor 3
   if(sensorValue3 > 1000 ) {
    
    if (playSdWav1.isPlaying() == false) {
       Serial.println("Start playing");
      playSdWav1.play("kick.WAV");
      delay(10); // wait for library to parse WAV info
    }
    
    digitalWrite(ledpin3, HIGH);
     Serial.print("Value 1"); // send the letter T (for Trigger) once the sensor value is bigger than 200
   
  }
 
 else {
    digitalWrite(ledpin3, LOW);
    } 

//Sensor 4
  if(sensorValue4 > 1000 ) {
    
    if (playSdWav1.isPlaying() == false) {
       Serial.println("Start playing");
      playSdWav1.play("kick.WAV");
      delay(10); // wait for library to parse WAV info
    }
    
    digitalWrite(ledpin4, HIGH);
     Serial.print("Value 4"); // send the letter T (for Trigger) once the sensor value is bigger than 200
   
  }
 
 else {
    digitalWrite(ledpin4, LOW);
    }

 //Sensor 5
   if(sensorValue5 > 1000 ) {
    
    if (playSdWav1.isPlaying() == false) {
       Serial.println("Start playing");
      playSdWav1.play("kick.WAV");
      delay(10); // wait for library to parse WAV info
    }
    
    digitalWrite(ledpin5, HIGH);
     Serial.print("Value 5"); // send the letter T (for Trigger) once the sensor value is bigger than 200
   
  }
 
 else {
    digitalWrite(ledpin5, LOW);
    }
  
  delay(1);        // delay in between reads for stability
}
