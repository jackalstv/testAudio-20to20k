//
// Created by User on 09/03/2024.
//

#include "../include/traitement.h"

void traitementGraph(int * data){

    int v;

    for(int i = 0; i < ARRAY_SIZE; i++) {
        if((data[i]==-1 || data[i]==-2 || data[i]==-3) && i<ARRAY_SIZE-13){
            for (int j = i; j < 14; j++) {
                if (data[j]==-1 || data[j]==-2 || data[j]==-3){
                    v = j;
                    break;
                }
            }
            for (int w=i;w < v;w++) {
                switch (data[w]) {
                    case -1:
                        data[w] = -1;
                        break;
                    case -2:
                        data[w] = -2;
                        break;
                    case -3:
                        data[w] = -3;
                        break;
                    default:
                        break;
                }
            }
        }
        i=v;
    }
    printf("Donnee formater \n");
}