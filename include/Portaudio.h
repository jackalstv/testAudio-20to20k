//Jackalstv 11/03/2024

#ifndef EGALISEUR_AUDIO_ADAPTATIF_PORTAUDIO_H
#define EGALISEUR_AUDIO_ADAPTATIF_PORTAUDIO_H

#include <stdio.h>
#include <portaudio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include "kaybordact.h"
#include "global.h"

int paCallback(const void *inputBuffer,
               void *outputBuffer,
               unsigned long framesPerBuffer,
               const PaStreamCallbackTimeInfo* timeInfo,
               PaStreamCallbackFlags statusFlags, void *userData);

#endif //EGALISEUR_AUDIO_ADAPTATIF_PORTAUDIO_H
