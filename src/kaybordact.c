//
// Created by User on 2/19/2024.
//

#include "../include/kaybordact.h"

void configureTerminal(struct termios *orig_term) {
    struct termios new_term;
    tcgetattr(STDIN_FILENO, orig_term); // Sauvegarde les paramètres originaux
    new_term = *orig_term;
    new_term.c_lflag &= ~(ICANON | ECHO); // Désactive l'entrée canonique et l'écho
    new_term.c_cc[VMIN] = 0;
    new_term.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
}

void restoreTerminal(struct termios *orig_term) {
    tcsetattr(STDIN_FILENO, TCSANOW, orig_term); // Restaure les paramètres originaux
}


bool isKeyPressed() {
    unsigned char touche;
    int nbChars = read(STDIN_FILENO, &touche, 1); // Lit un caractère sans bloquer
    return nbChars > 0; // Retourne true s'il y a un caractère, sinon false
}