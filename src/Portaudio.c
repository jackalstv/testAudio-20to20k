//
// Created by User on 2/13/2024.
//
#include "../include/Portaudio.h"



void generateSignal(double *signal, int numSamples) {
    double deltaFreq = (END_FREQ - START_FREQ) / DURATION;
    double timeStep = 1.0 / SAMPLING_RATE;
    double currentTime = 0.0;

    for (int i = 0; i < numSamples; ++i) {
        signal[i] = sin(2.0 * PI * currentTime);
        currentTime += deltaFreq * timeStep;
    }
}

// Fonction de rappel (callback) pour PortAudio
int paCallback(const void *inputBuffer, void *outputBuffer,
               unsigned long framesPerBuffer,
               const PaStreamCallbackTimeInfo *timeInfo,
               PaStreamCallbackFlags statusFlags,
               void *userData) {
    double *signal = (double *)userData;
    float *out = (float *)outputBuffer;

    static unsigned long frameIndex = 0;

    // Calculer la fréquence actuelle
    double currentFreq = START_FREQ + (END_FREQ - START_FREQ) * frameIndex / (SAMPLING_RATE * DURATION);
    //printf("Frequency: %.2f Hz\n", currentFreq);

    // Générer le signal
    for (unsigned long i = 0; i < framesPerBuffer; ++i) {
        *out++ = (float)(sin(2.0 * PI * currentFreq * i / SAMPLING_RATE));
        x[i]=*out;
        isPress[i]=0;
    }

    frameIndex += framesPerBuffer;

    return paContinue;
}