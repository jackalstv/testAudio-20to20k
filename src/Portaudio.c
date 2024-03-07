//
// Created by User on 2/13/2024.
//
#include "../include/Portaudio.h"
#include <stdio.h>
#include <portaudio.h>
#include <math.h>
#include "../include/global.h"

volatile int keyPressed = 0;

int isPress[(int)END_FREQ- (int)START_FREQ + 1];


int paCallback(const void *inputBuffer, void *outputBuffer,
               unsigned long framesPerBuffer,
               const PaStreamCallbackTimeInfo *timeInfo,
               PaStreamCallbackFlags statusFlags,
               void *userData) {
    //double *signal = (double *)userData;
    float *out = (float *)outputBuffer;
    static unsigned long frameIndex = 0;

    //struct termios orig_term;
    //configureTerminal(&orig_term);

    // Calculer la fréquence actuelle
    double currentFreq = START_FREQ + (END_FREQ - START_FREQ) * frameIndex / (SAMPLING_RATE * DURATION); // 5 to 20000
    printf("Frequency: %.2f Hz\n", currentFreq);

    //int freq = (int)currentFreq;
    // Générer le signal
    for (unsigned long i = 0; i < framesPerBuffer; ++i) { // 0 to 44100
        *out++ = (float)(sin(2.0 * PI * currentFreq * i / SAMPLING_RATE));
        if(keyPressed) {
            isPress[i] = -1;
            // Marquez l'échantillon actuel comme ayant une touche pressée
            keyPressed = 0; // Réinitialiser le flag pour la prochaine pression
        }
    }

    frameIndex += framesPerBuffer;

    return paContinue;
}
