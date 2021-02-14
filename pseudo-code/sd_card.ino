//music
#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>

//sd card
#include <SD.h> 
#include <SPI.h>
#define SD_ChipSelectPin 10

TMRpcm tmrpcm;

//note: music should be in WAV format (http://audio.online-convert.com/convert-to-wav)


void setup()
{
  Serial.begin(9600);
  tmrpcm.speakerPin=9;
  if(!SD.begin(SD_ChipSelectPin))
  {
    Serial.println("SD fail");
    return;
  }

  tmrpcm.setVolume(6);
  tmrpcm.play("test.wav"); //power on sound
}


void loop(){
  play (); // continous rhymes
}



void play(){
  tmrpcm.stopPlayback();

  tmrpcm.play("test.wav"); //rhym 1
  delay(240000);

  tmrpcm.play("test.wav"); //rhym 2
  delay(240000);

  delay(100);
  return;

}
