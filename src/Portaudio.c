//
// Created by User on 2/13/2024.
//

#include "../include/Portaudio.h"

typedef struct {
    double currentTime;           // Temps actuel dans la progression de la fréquence
    unsigned long lastPrintTime;  // Dernier temps où la fréquence a été imprimée
    double left_phase;
    double right_phase;
    double phase;
} paUserData;

int paCallback(const void *inputBuffer,
               void *outputBuffer, // Pointeur vers le buffer de sortie (stéréo)
               unsigned long framesPerBuffer, // Nombre d'échantillons par buffer
               const PaStreamCallbackTimeInfo* timeInfo, // Informations temporelles
               PaStreamCallbackFlags statusFlags, void *userData) {
    paUserData *data = (paUserData*)userData; // Récupérer les données utilisateur
    float *out = (float*)outputBuffer; // Pointeur vers le buffer de sortie (stéréo)
    double timeStep = 1.0 / SAMPLING_RATE; // Temps par échantillon

    for(unsigned long i = 0; i < framesPerBuffer; i++) { // Parcours de chaque échantillon
        double progress = data->currentTime / DURATION; // Progression normalisée dans le temps [0, 1]
        double expProgress = progress * progress * progress; // Accélération plus rapide avec la progression cubique

        double currentFreq = START_FREQ + (END_FREQ - START_FREQ) * expProgress;
        double phaseIncrement = (currentFreq * 2.0 * PI) * timeStep;

        int freqIndex=(int)currentFreq;

        laFreq[0]=freqIndex;



        data->phase += phaseIncrement;
        data->right_phase += phaseIncrement;
        data->left_phase += phaseIncrement;
        while(data->phase >= 2.0 * PI) data->phase -= 2.0 * PI; // data
        *out++ = (float)sin(data->right_phase); // Générer le signal sinusoïdal
        *out++ = (float)sin(data->left_phase); // Générer le signal sinusoïdal
        data->currentTime += timeStep;
        if(data->currentTime > DURATION) data->currentTime = DURATION; // Empêcher le dépassement
/*
        // Afficher la fréquence environ toutes les secondes
        if((unsigned long)data->currentTime != data->lastPrintTime && (unsigned long)data->currentTime % 1 == 0) {
            printf("Current Frequency: %.2f Hz\n", currentFreq);
            data->lastPrintTime = (unsigned long)data->currentTime;
        }*/
    }

    return paContinue;
}

