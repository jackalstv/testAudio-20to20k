//
// Created by User on 09/03/2024.
//

#include "../include/traitement.h"

#include <stdio.h>

void traitementGraph(int *liste, int taille) {
    int i, j, count;

    for (i = 0; i < taille; i++) {
        if (liste[i] == -1 || liste[i] == -2 || liste[i] == -3) {
            count = 0;

            // Rechercher les zéros suivants
            for (j = i + 1; j < taille; j++) {
                if (liste[j] == 0) {
                    count++;
                } else if (liste[j] == -1 || liste[j] == -2 || liste[j] == -3) {
                    if (count <= 40) {
                        // Remplacer les zéros par la valeur limite
                        while (count > 0) {
                            liste[j - count] = liste[i];
                            count--;
                        }
                    }
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

            // Si la boucle se termine sans rencontrer de limite,
            // remplacer les zéros jusqu'à la fin de la liste
            if (j == taille) {
                if (count <= 40) {
                    while (count > 0 && j - count >= 0) {
                        liste[j - count] = liste[i];
                        count--;
                    }
                }
            }
        }
    }
}
