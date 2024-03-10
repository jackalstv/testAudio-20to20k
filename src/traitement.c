//
// Created by User on 09/03/2024.
//

#include "../include/traitement.h"

void traitementGraph(int *data) {
    int v = 0; // Initialisez v pour éviter un comportement indéterminé
    int w = 0; // Initialisez w pour éviter un comportement indéterminé
    bool found = false; // Utilisez un booléen pour éviter les erreurs de logique
    for (int i = 0; i < ARRAY_SIZE - 40; i++) {
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
            for (int u = i+1; u < 35; u++) {
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


void remplacerZeros(int *liste, int taille) {
    int i, j, count;

    for (i = 0; i < taille; i++) {
        if (liste[i] == -1 || liste[i] == -2 || liste[i] == -3) {
            count = 0;

            // Rechercher les zéros suivants
            for (j = i + 1; j < taille; j++) {
                if (liste[j] == 0) {
                    count++;
                } else if (liste[j] == -1 || liste[j] == -2 || liste[j] == -3) {
                    break; // On a rencontré la limite
                } else {
                    if (count <= 40) {
                        // Remplacer les zéros par la valeur limite
                        while (count > 0) {
                            liste[j - count] = liste[i];
                            count--;
                        }
                    }
                    break;
                }
            }
        }
    }
}