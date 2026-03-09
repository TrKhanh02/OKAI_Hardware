#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include "AudioFileSourceSD.h"
#include "AudioFileSourceBuffer.h"
#include "AudioGeneratorMP3.h"
#include "AudioOutputI2S.h"

#define SD_CS 5     // GPIO5
#define SD_MOSI 13  // GPIO13
#define SD_CLK  14  // GPIO14
#define SD_MISO 19  // GPIO19
#define DAC_PIN 25

AudioGeneratorMP3 *mp3;
AudioFileSourceSD *file;
AudioFileSourceBuffer *buff;
AudioOutputI2S *out;

String songs[20];
int totalSongs = 0;
int currentSong = -1;

SPIClass spiSD(VSPI);  

void StopPlaying()
{
  if (mp3)
  {
    mp3->stop();
    delete mp3;
    mp3 = NULL;
  }
  if (buff)
  {
    buff->close();
    delete buff;
    buff = NULL;
  }
  if (file)
  {
    file->close();
    delete file;
    file = NULL;
  }
  if (out)
  {
    out->stop();
  }
  Serial.println("Stop");
}

void play(String filePath)
{
  file = new AudioFileSourceSD(filePath.c_str());
  if (!file->isOpen())
  {
    Serial.print("Cannot open file: ");
    Serial.println(filePath);
    return;
  }
  buff = new AudioFileSourceBuffer(file, 8192);
  mp3 = new AudioGeneratorMP3();
  mp3->begin(buff, out);
  Serial.print("Playing: ");
  Serial.println(filePath);
}

void mp3Task(int songIndex)
{
  if (songIndex >= 0 && songIndex < totalSongs)
  {
    currentSong = songIndex;
    play(songs[currentSong]);

    if (!file || !file->isOpen())
    {
      currentSong = -1;
      return;
    }
  }
  else
  {
    Serial.println("Invalid song index");
    currentSong = -1;
    return;
  }
}

void mp3_setup()
{
  Serial.begin(115200);
  
  spiSD.begin(SD_CLK, SD_MISO, SD_MOSI, SD_CS); 

  Serial.println("Init SD...");
  if (!SD.begin(SD_CS, spiSD))
  {
    Serial.println("Cannot start SD card!");
    return;
  }

  Serial.println(" SD Ready.");
  File root = SD.open("/");
  while (true)
  {
    File entry = root.openNextFile();
    if (!entry)
      break;
    String name = entry.name();
    if (name.endsWith(".mp3") || name.endsWith(".MP3"))
    {
      songs[totalSongs] = String("/") + name;
      Serial.print(totalSongs);
      Serial.print(": ");
      Serial.println(songs[totalSongs]);
      totalSongs++;
    }
    entry.close();
  }
  root.close();

  if (totalSongs == 0)
  {
    Serial.println(" Cannot find any MP3 files.");
    return;
  }

  out = new AudioOutputI2S(0, AudioOutputI2S::INTERNAL_DAC);
  out->SetPinout(0, 0, DAC_PIN);
  out->SetGain(0.45);
}
