//
// Created by User on 07/03/2024.
//

#ifndef EGALISEUR_AUDIO_ADAPTATIF_GLOBAL_H
#define EGALISEUR_AUDIO_ADAPTATIF_GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <stdbool.h>
#include <pthread.h>
#include <portaudio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include "../include/kaybordact.h"

#define PI 3.14159265358979323846
#define START_FREQ 20.0         // Fréquence de départ en Hz
#define END_FREQ 20000.0        // Fréquence de fin en Hz
#define SAMPLING_RATE 44100     // Taux d'échantillonnage
#define DURATION 140.0  

volatile  int keyPressed;
int isPress[19980]={0};
volatile int keyPressed =0;


#endif //EGALISEUR_AUDIO_ADAPTATIF_GLOBAL_H