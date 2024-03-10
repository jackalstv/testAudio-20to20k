//
// Created by User on 2/19/2024.
//

#ifndef EGALISEUR_AUDIO_ADAPTATIF_KAYBORDACT_H
#define EGALISEUR_AUDIO_ADAPTATIF_KAYBORDACT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h> // pour le mode canonique
#include <stdbool.h> // pour les booléens
#include <fcntl.h> // pour le mode non bloquant

#include "global.h"

int kbhit(void);

void *keyboardInput(void* arg);




#endif //EGALISEUR_AUDIO_ADAPTATIF_KAYBORDACT_H
