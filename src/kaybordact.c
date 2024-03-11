//
// Created by User on 2/19/2024.
//

#include "../include/kaybordact.h"

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

void *keyboardInput(void* arg){
    while(record) {
        if(kbhit()) {
            int ch = getchar(); // Lit la touche pressée
            // Si 'q' ou 'Q' est pressé, pourrait être utilisé pour quitter
            if (laFreq[0] >= 0 && laFreq[0] < sizeof(isPress)/sizeof(isPress[0])) {
                switch(ch){
                    case '1' :
                        isPress[laFreq[0]] = -1;
                        printf("Frequency: %d Hz marquée dans isPress\n", laFreq[0]);
                        break;
                    case '2' :
                        isPress[laFreq[0]] = -2;
                        printf("Frequency: %d Hz marquée dans isPress\n", laFreq[0]);
                        break;
                    case '3' :
                        isPress[laFreq[0]] = -3;
                        printf("Frequency: %d Hz marquée dans isPress\n", laFreq[0]);
                        break;
                    default:
                        break;
                }

            }
        }

    }
    return NULL;
}