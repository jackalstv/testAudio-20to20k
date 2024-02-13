#ifndef PORTAUDIO_H
#define PORTAUDIO_H

#include <stdio.h>
#include <portaudio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define PI 3.14159265358979323846
#define START_FREQ 5.0
#define END_FREQ 20000.0
#define DURATION 20.0
#define SAMPLING_RATE 44100.0

void generateSignal(float *signal, double duration, double startFreq, double endFreq, double samplingRate);
int paCallback(const void *inputBuffer, void *outputBuffer,
               unsigned long framesPerBuffer,
               const PaStreamCallbackTimeInfo *timeInfo,
               PaStreamCallbackFlags statusFlags,
               void *userData);
#endif // PORTAUDIO_H
