//
// Created by User on 09/03/2024.
//

#include "../include/traitement.h"

void traitementGraph(int *data) {
    int v = 0; // Initialisez v pour éviter un comportement indéterminé
    int w = 0; // Initialisez w pour éviter un comportement indéterminé
    bool found = false; // Utilisez un booléen pour éviter les erreurs de logique
    for (int i = 0; i < ARRAY_SIZE - 15; i++) {
        switch(data[i]) {
            case -1:
                w = -1;
                found = true; // Utilisez un booléen pour éviter les erreurs de logique
                break;
            case -2:
                w = -2;
                found = true; // Utilisez un booléen pour éviter les erreurs de logique
                break;
            case -3:
                w = -3;
                found = true; // Utilisez un booléen pour éviter les erreurs de logique
                break;
            default:
                w = 0;
        break;
        }
        if(found) { // Utilisez un booléen pour éviter les erreurs de logique
            for (int u = i+1; u < 13; u++) {
                if (data[i] == w) {
                    for (int j = i + 1; j < u; j++) { // Corrigez la limite de tableau
                                data[j] = w;
                            }
                        }
                i = v; // Utilisez v après avoir terminé la boucle interne
                    }
                }
            }
    printf("Donnee formater \n");
}


