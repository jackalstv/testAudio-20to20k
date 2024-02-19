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

void configureTerminal(struct termios *orig_term);
void restoreTerminal(struct termios *orig_term);
bool isKeyPressed();



#endif //EGALISEUR_AUDIO_ADAPTATIF_KAYBORDACT_H
