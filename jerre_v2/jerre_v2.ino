#include <pcmRF.h>
#include <pcmConfig.h>
#include <TMRpcm.h>

#include <SD.h>
#include <SPI.h>
TMRpcm tmrpcm;
int fileNum = 1;
int button = 0;
String fileNumStr = "";
String abc = "";
String wavStr = ".wav";
#define SD_ChipSelectPin 4
int dingyDongy = 0;

void setup() {
  Serial.begin (9600);
  tmrpcm.speakerPin = 9;
  if (!SD.begin(SD_ChipSelectPin)) {
  Serial.println("SD fail"); 
  }
  pinMode (7, INPUT);
  pinMode (5, INPUT);
}

void loop() { 
   delay(100); 
  //digitalWrite (6, HIGH);
  button = digitalRead(7);
  dingyDongy = digitalRead(5);
  Serial.println(button);
  if ( button == 1) {
    tmrpcm.setVolume(6);
    if (fileNum <= 20){
      fileNum ++;
    }
    else if (fileNum == 21){
    fileNum = 1;
    }
    fileNumStr = String (fileNum);
    abc = fileNumStr + wavStr;
    char abcd[5];
    abc.toCharArray(abcd, 50);
    tmrpcm.play( abcd , 0 );
    delay(15000);
    Serial.println (abc);
    }
    else if (dingyDongy == 1){
     tmrpcm.play( "knock.wav");
     dingyDongy = 0;
     delay (3000);
    }
}
