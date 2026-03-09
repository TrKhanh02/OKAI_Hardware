#ifndef MP3_H
#define MP3_H

#include <Arduino.h>
#include <SD.h>
#include "AudioFileSourceSD.h"
#include "AudioFileSourceBuffer.h"
#include "AudioGeneratorMP3.h"
#include "AudioOutputI2S.h"

#define SD_CS 5    
#define DAC_PIN 25 

extern String songs[20]; 
extern int totalSongs;    
extern int currentSong;   

void mp3_setup();
void play(String filePath);
void StopPlaying();
void mp3Task(int songIndex);

#endif 