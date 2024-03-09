//
// Created by User on 2/19/2024.
//

#include "../include/kaybordact.h"

volatile int keyPressed=0;

int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt); // sauvegarde les paramètres actuels du terminal
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // désactive le mode canonique et l'écho
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // applique les nouveaux paramètres
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK); // rend la lecture non bloquante

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restaure les paramètres du terminal
    fcntl(STDIN_FILENO, F_SETFL, oldf); // restaure les paramètres de fichier

    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1; // une touche a été pressée
    }

    return 0; // aucune touche n'a été pressée
}

void* checKeyPress(void* arg) {
    int lastState = 0; // État précédent pour détecter les changements
    while(1) {
        int currentState = kbhit(); // Détecte si une touche est actuellement pressée
        if(currentState != lastState) { // Si l'état a changé depuis la dernière vérification
            keyPressed = currentState; // Met à jour l'état global keyPressed
            lastState = currentState; // Met à jour lastState pour la prochaine comparaison
        }
        usleep(10000); // Réduit la charge du CPU
    }
    return NULL;
}
