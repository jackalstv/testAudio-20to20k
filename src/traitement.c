//
// Created by User on 09/03/2024.
//

#include "../include/traitement.h"

void traitementGraph(int * data){
    int v;
    for(int i = 0; i < ARRAY_SIZE-15; i++) {
        for(int w= -1; w > -4; w--){
            for(int u = 0; u < 13; u++) {
                if (data[i] == w) {
                    for (int j = i + 1; j < 13; j++) {
                        if (data[j] == w) {
                            v = j;
                            for (int o = i; o < j; o++) {
                                data[o] = w;
                            }
                        }
                    }
                }
            }
        }
        i=v;
    }
    printf("Donnee formater \n");
}
