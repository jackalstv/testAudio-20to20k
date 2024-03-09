//
// Created by User on 09/03/2024.
//

#include "../include/traitement.h"

void traitementGraph(int * data){

    for(int i = 0; i < ARRAY_SIZE; i++) {
        if(i<ARRAY_SIZE-13){

            if(data[i]==-1 && data[i+1]==0 && data[i+2]==0 && data[i+3]==0 && data[i+4]==0 && data[i+5]==0 && data[i+6]==0 && data[i+7]==0 && data[i+8]==0 && data[i+9]==0 && data[i+10]==0 && data[i+11]==0 && data[i+12]==-1){
                data[i+1]=-1;
                data[i+2]=-1;
                data[i+3]=-1;
                data[i+4]=-1;
                data[i+5]=-1;
                data[i+6]=-1;
                data[i+7]=-1;
                data[i+8]=-1;
                data[i+9]=-1;
                data[i+10]=-1;
                data[i+11]=-1;
                i=i+12;
            }
        }
        if(i<ARRAY_SIZE-9){
            if(data[i]==-1 && data[i+1]==0 && data[i+2]==0 && data[i+3]==0 && data[i+4]==0 && data[i+5]==0 && data[i+6]==0 && data[i+7]==0 && data[i+8]==0 && data[i+9]==-1){
                data[i+1]=-1;
                data[i+2]=-1;
                data[i+3]=-1;
                data[i+4]=-1;
                data[i+5]=-1;
                data[i+6]=-1;
                data[i+7]=-1;
                data[i+8]=-1;
                i=i+9;
            }
        }
        if(i<ARRAY_SIZE-5){
            if(data[i]==-1 && data[i+1]==0 && data[i+2]==0 && data[i+3]==0 && data[i+4]==0 && data[i+5]==-1){
                data[i+1]=-1;
                data[i+2]=-1;
                data[i+3]=-1;
                data[i+4]=-1;
                i=i+5;
            }
        }
        printf("Donnee formater \n");
        }
}