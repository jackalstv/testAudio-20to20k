//
// Created by User on 09/03/2024.
//

#include "../include/traitement.h"

void traitementGraph(int * data){

    for(int i = 0; i < ARRAY_SIZE-15; i++) {
        for(int w= -1; w > -4; w--){
            if(data[i]==w && data[i+1]==0 && data[i+2]==0 && data[i+3]==0 && data[i+4]==0 && data[i+5]==0 && data[i+6]==0 && data[i+7]==0 && data[i+8]==0 && data[i+9]==0 && data[i+10]==0 && data[i+11]==0 && data[i+12]==w){
                for(int j = i; j < 13; j++){
                    data[i+j]=w;
                }
                i=i+12;
            }
            if(data[i]==w && data[i+1]==0 && data[i+2]==0 && data[i+3]==0 && data[i+4]==0 && data[i+5]==0 && data[i+6]==0 && data[i+7]==0 && data[i+8]==0 && data[i+9]==0 && data[i+10]==0 && data[i+11]==w){
                for(int j = i; j < 12; j++){
                    data[i+j]=w;
                }
                i=i+11;
            }
            if(data[i]==w && data[i+1]==0 && data[i+2]==0 && data[i+3]==0 && data[i+4]==0 && data[i+5]==0 && data[i+6]==0 && data[i+7]==0 && data[i+8]==0 && data[i+9]==0 && data[i+10]==w){
                for(int j = i; j < 11; j++){
                    data[i+j]=w;
                }
                i=i+10;
            }
            if(data[i]==w && data[i+1]==0 && data[i+2]==0 && data[i+3]==0 && data[i+4]==0 && data[i+5]==0 && data[i+6]==0 && data[i+7]==0 && data[i+8]==0 && data[i+9]==w){
                for(int j = i; j < 10; j++){
                    data[i+j]=w;
                }
                i=i+9;
                }
            if(data[i]==-1 && data[i+1]==0 && data[i+2]==0 && data[i+3]==0 && data[i+4]==0 && data[i+5]==-1){
                data[i+1]=-1;
                data[i+2]=-1;
                data[i+3]=-1;
                data[i+4]=-1;
                i=i+5;
            }
    }

        }
    printf("Donnee formater \n");
}