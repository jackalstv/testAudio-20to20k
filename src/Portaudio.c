//
// Created by User on 2/13/2024.
//
#include "../include/Portaudio.h"
#include <stdio.h>
#include <portaudio.h>
#include <math.h>


extern volatile int keyPressed;
<<<<<<< HEAD
extern int isPress[19980];
int freqIndex;

void setfrep(int freq)

typedef struct {
    double currentTime;           // Temps actuel dans la progression de la fréquence
    unsigned long lastPrintTime;  // Dernier temps où la fréquence a été imprimée
    double left_phase;
    double right_phase;  
} paUserData;

int paCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
               const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void *userData) {
    paUserData *data = (paUserData*)userData;
    float *out = (float*)outputBuffer;
    double timeStep = 1.0 / SAMPLING_RATE; // Temps par échantillon

    for(unsigned long i = 0; i < framesPerBuffer; i++) {
        double progress = data->currentTime / DURATION; // Progression normalisée dans le temps [0, 1]
        double expProgress = progress * progress * progress; // Accélération plus rapide avec la progression cubique

        double currentFreq = START_FREQ + (END_FREQ - START_FREQ) * expProgress;
        double phaseIncrement = (currentFreq * 2.0 * PI) * timeStep;

        int freqIndex=(int)currentFreq;

        data->right_phase += phaseIncrement;
        data->left_phase += phaseIncrement;
        while(data->phase >= 2.0 * PI) data->phase -= 2.0 * PI;
            *out++ = (float)sin(data->right_phase); // Générer le signal sinusoïdal
            *out++ = (float)sin(data->left_phase); // Générer le signal sinusoïdal
            data->currentTime += timeStep;
        if(data->currentTime > DURATION) data->currentTime = DURATION; // Empêcher le dépassement

        // Afficher la fréquence environ toutes les secondes
        if((unsigned long)data->currentTime != data->lastPrintTime && (unsigned long)data->currentTime % 1 == 0) {
            printf("Current Frequency: %.2f Hz\n", currentFreq);
            data->lastPrintTime = (unsigned long)data->currentTime;
        }
=======
int isPress[20000]= {0};

/*int paCallback(const void *inputBuffer, void *outputBuffer,
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
    double currentFreq = START_FREQ + ((END_FREQ - START_FREQ) * frameIndex) / (SAMPLING_RATE * DURATION);// 1 to 20000
    //printf("Frequency: %d Hz\n", currentFreq);
    if(keyPressed) {
	isPress[(int)currentFreq] = -1;
	printf("Frequency: %d Hz dans isPress %d : \n",(int)currentFreq,isPress[(int)currentFreq]);
            // Marquez l'échantillon actuel comme ayant une touche pressée
        keyPressed = 0; // Réinitialiser le flag pour la prochaine pression
        }else{isPress[(int)currentFreq]=0;}

    //int freq = (int)currentFreq;
    // Générer le signal
    for (unsigned long i = 0; i < framesPerBuffer; ++i) { // 0 to 44100
        *out++ = (float)(sin(2.0 * PI * currentFreq * i / SAMPLING_RATE));

>>>>>>> b8f5bb2dd26f7f37ea02734e61cacb0cebd7eb10
    }

    return paContinue;
}*/

#include <stdio.h>
#include <portaudio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define START_FREQ 20.0         // Fréquence de départ en Hz
#define END_FREQ 20000.0        // Fréquence de fin en Hz
#define SAMPLING_RATE 44100     // Taux d'échantillonnage
#define DURATION 140.0          // Durée totale en secondes pour parcourir de 20 Hz à 20 kHz

typedef struct {
    double phase;                 // Phase actuelle du signal
    double currentTime;           // Temps actuel dans la progression de la fréquence
    unsigned long lastPrintTime;  // Dernier temps où la fréquence a été imprimée
} paUserData;

int paCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
               const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void *userData) {
    paUserData *data = (paUserData*)userData;
    float *out = (float*)outputBuffer;
    double timeStep = 1.0 / SAMPLING_RATE; // Temps par échantillon

    for(unsigned long i = 0; i < framesPerBuffer; i++) {
        double progress = data->currentTime / DURATION; // Progression normalisée dans le temps [0, 1]
        double expProgress = progress * progress * progress; // Accélération plus rapide avec la progression cubique

        double currentFreq = START_FREQ + (END_FREQ - START_FREQ) * expProgress;
        double phaseIncrement = (currentFreq * 2.0 * PI) * timeStep;

        data->phase += phaseIncrement;
        while(data->phase >= 2.0 * PI) data->phase -= 2.0 * PI;

        *out++ = (float)sin(data->phase); // Générer le signal sinusoïdal

        data->currentTime += timeStep;
        if(data->currentTime > DURATION) data->currentTime = DURATION; // Empêcher le dépassement

        // Afficher la fréquence environ toutes les secondes
        if((unsigned long)data->currentTime != data->lastPrintTime && (unsigned long)data->currentTime % 1 == 0) {
            printf("Current Frequency: %.2f Hz\n", currentFreq);
            data->lastPrintTime = (unsigned long)data->currentTime;
        }
        if(keyPressed) {
            int freqIndex = (int)currentFreq;
            if (freqIndex >= 0 && freqIndex < sizeof(isPress)/sizeof(isPress[0])) { // Vérification de la limite
                isPress[freqIndex] = -1;
                printf("Frequency: %d Hz dans isPress %d : \n", freqIndex, isPress[freqIndex]);
                keyPressed = 0; // Réinitialiser le flag pour la prochaine pression
            }
        } else {
            int freqIndex = (int)currentFreq;
            if (freqIndex >= 0 && freqIndex < sizeof(isPress)/sizeof(isPress[0])) { // Vérification de la limite
                isPress[freqIndex] = 0;
            }
        }
    }

    return paContinue;
}

