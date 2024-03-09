//
// Created by User on 07/03/2024.
//

#include "../include/graphe.h"

void generate_graph(int *data) {
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe == NULL) {
        printf("Erreur lors de l'ouverture du pipe vers Gnuplot.\n");
        exit(1);
    }

    fprintf(gnuplotPipe, "set title 'Détection de pression de touche'\n");
    fprintf(gnuplotPipe, "plot '-' with linespoints\n");

    for(int i = 0; i < ARRAY_SIZE; i++) {
        fprintf(gnuplotPipe, "%d %d\n", i, data[i]);
    }

    fprintf(gnuplotPipe, "e\n");
    fflush(gnuplotPipe);

    pclose(gnuplotPipe);
}