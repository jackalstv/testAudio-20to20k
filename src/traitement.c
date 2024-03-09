//
// Created by User on 09/03/2024.
//

#include "../include/traitement.h"

void traitementGraph(int * data){

    int v;

    for(int i = 0; i < ARRAY_SIZE; i++) {
        if(data[i]==-1) {
            for (int j = i; j < 14; j++) {
                if (data[j] == -1){
                    v = j;
                    break;
                }
            }
            for (int w=i;w < v;w++) {
                if (data[w] == 0) {
                    data[w] = -1;
                }
            }
        }
    }
    printf("Donnee formater \n");
}