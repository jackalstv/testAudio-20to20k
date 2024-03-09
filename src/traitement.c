//
// Created by User on 09/03/2024.
//

#include "../include/traitement.h"

void traitementGraph(int * data){

    int v;

    for(int i = 0; i < ARRAY_SIZE; i++) {
        if(data[i]==-1) {
            for (int j = i; j < ARRAY_SIZE; j++) {
                if (data[j] == -1 && (j - i) > 14) {
                    v = j;
                    break;
                }
            }
            for (int j = 1; j < v; j++) {
                if (data[j] == 0) {
                    data[j] = -1;
                }
            }
        }
    }
    printf("Donnee formater \n");
}