//Jackalstv 11/03/2024

#include "../include/graphe.h"

void generate_graph(int *data) {
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe == NULL) {
        printf("Erreur lors de l'ouverture du pipe vers Gnuplot.\n");
        exit(1);
    }

    fprintf(gnuplotPipe, "set title 'Audiogram de 20hz à 20khz'\n");
    fprintf(gnuplotPipe, "plot '-' with linespoints\n");

    for(int i = 0; i < ARRAY_SIZE-1; i++) { // Parcours du tableau
        fprintf(gnuplotPipe, "%d %d\n", i, data[i]);
    }

    fprintf(gnuplotPipe, "e\n"); // Fin de l'écriture des données
    fflush(gnuplotPipe);

    pclose(gnuplotPipe);
}