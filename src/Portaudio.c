//Jackalstv 11/03/2024

#include "../include/Portaudio.h"

typedef struct {
    double currentTime;
    unsigned long lastPrintTime;
    double left_phase;
    double right_phase;
    double phase;
} paUserData;

int paCallback(const void *inputBuffer,
               void *outputBuffer,
               unsigned long framesPerBuffer, // Nombre d'échantillons par buffer
               const PaStreamCallbackTimeInfo* timeInfo,
               PaStreamCallbackFlags statusFlags, void *userData) {
    paUserData *data = (paUserData*)userData;
    float *out = (float*)outputBuffer;
    double timeStep = 1.0 / SAMPLING_RATE; // Temps par échantillon

    for(unsigned long i = 0; i < framesPerBuffer; i++) {
        double progress = data->currentTime / DURATION; // Progression normalisée dans le temps [0, 1]
        double expProgress = progress * progress * progress;

        double currentFreq = START_FREQ + (END_FREQ - START_FREQ) * expProgress;
        double phaseIncrement = (currentFreq * 2.0 * PI) * timeStep;

        int freqIndex=(int)currentFreq;

        laFreq[0]=freqIndex;

        data->phase += phaseIncrement;

        while(data->phase >= 2.0 * PI) data->phase -= 2.0 * PI;
            *out++ = (float)sin(data->phase);
        data->currentTime += timeStep;
        if(data->currentTime > DURATION) data->currentTime = DURATION; // Empêcher le dépassement

       /* // Afficher la fréquence environ toutes les secondes
        if((unsigned long)data->currentTime != data->lastPrintTime && (unsigned long)data->currentTime % 1 == 0) {
            printf("Current Frequency: %.2f Hz\n", currentFreq);
            data->lastPrintTime = (unsigned long)data->currentTime;
        }*/
    }

    return paContinue;
}

