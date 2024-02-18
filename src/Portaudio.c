//
// Created by User on 2/13/2024.
//
#include "../include/Portaudio.h"
#include <pthread.h>

int x[(int)END_FREQ- (int)START_FREQ + 1];
int isPress[(int)END_FREQ- (int)START_FREQ + 1];
bool boutonPress;

void* keyboardInput(void* arg) {
    char input[100];
    while (1) {
        if(scanf("%99s", input)){boutonPress=true;}

    }
    return NULL;
}

int paCallback(const void *inputBuffer, void *outputBuffer,
               unsigned long framesPerBuffer,
               const PaStreamCallbackTimeInfo *timeInfo,
               PaStreamCallbackFlags statusFlags,
               void *userData) {
    //double *signal = (double *)userData;
    float *out = (float *)outputBuffer;
    static unsigned long frameIndex = 0;

    // Calculer la fréquence actuelle
    double currentFreq = START_FREQ + (END_FREQ - START_FREQ) * frameIndex / (SAMPLING_RATE * DURATION); // 5 to 20000
    //printf("Frequency: %.2f Hz\n", currentFreq);

    int freq = (int)currentFreq;
    // Générer le signal
    for (unsigned long i = 0; i < framesPerBuffer; ++i) { // 0 to 44100
        *out++ = (float)(sin(2.0 * PI * currentFreq * i / SAMPLING_RATE));
        if(x[i]!=freq){
            x[i]=freq;
            if(boutonPress){
                isPress[i]=-1;
            }
        }
    }

    frameIndex += framesPerBuffer;

    return paContinue;
}
