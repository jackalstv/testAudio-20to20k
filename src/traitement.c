//
// Created by User on 09/03/2024.
//

#include "../include/traitement.h"

void traitementGraph(int *data) {
    int v = 0; // Initialisez v pour éviter un comportement indéterminé
    for (int i = 0; i < ARRAY_SIZE - 15; i++) {
        if(data[i]==-1 || data[i]==-2 || data[i]==-3){
            for (int w = -1; w > -4; w--) {
                for (int u = 0; u < 13; u++) {
                    if (data[i] == w) {
                        for (int j = i + 1; j < ARRAY_SIZE; j++) { // Corrigez la limite de tableau
                            if (data[j] == w) {
                                v = j;
                                for (int o = i; o < j; o++) {
                                    data[o] = w;
                                }
                                break; // Quittez la boucle une fois que la valeur est trouvée
                            }
                        }
                    }
                }
            }
        }
        i = v; // Utilisez v après avoir terminé la boucle interne

    }
    printf("Donnee formater \n");
}

