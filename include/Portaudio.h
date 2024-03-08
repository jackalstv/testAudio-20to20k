//
// Created by User on 2/13/2024.
//

#ifndef EGALISEUR_AUDIO_ADAPTATIF_PORTAUDIO_H
#define EGALISEUR_AUDIO_ADAPTATIF_PORTAUDIO_H

#include <stdio.h>
#include <portaudio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include "../include/kaybordact.h"

#define PI 3.14159265358979323846

int paCallback(const void *inputBuffer, void *outputBuffer,
               unsigned long framesPerBuffer,
               const PaStreamCallbackTimeInfo *timeInfo,
               PaStreamCallbackFlags statusFlags,
               void *userData);

#endif //EGALISEUR_AUDIO_ADAPTATIF_PORTAUDIO_H
