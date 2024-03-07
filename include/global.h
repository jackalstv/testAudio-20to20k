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

volatile int keyPressed =0;
int isPress[(int)END_FREQ- (int)START_FREQ + 1]= {0};
#endif //EGALISEUR_AUDIO_ADAPTATIF_GLOBAL_H
