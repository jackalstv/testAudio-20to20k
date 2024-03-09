//
// Created by User on 2/19/2024.
//

#ifndef EGALISEUR_AUDIO_ADAPTATIF_KAYBORDACT_H
#define EGALISEUR_AUDIO_ADAPTATIF_KAYBORDACT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <stdbool.h>
#include <fcntl.h>

#include "global.h"

int kbhit(void);

void *keyboardInput(void* arg);




#endif //EGALISEUR_AUDIO_ADAPTATIF_KAYBORDACT_H
