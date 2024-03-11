//
// Created by User on 07/03/2024.
//

#include "../include/graphe.h"

void generate_graph(int *data) {
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w"); // Ouverture du pipe vers Gnuplot
    if (gnuplotPipe == NULL) { // Si l'ouverture du pipe a échoué
        printf("Erreur lors de l'ouverture du pipe vers Gnuplot.\n");
        exit(1);
    }

    fprintf(gnuplotPipe, "set title 'Détection de weqewqeqweqwewqewq de touche'\n"); // Titre du graphique
    fprintf(gnuplotPipe, "plot '-' with linespoints\n"); // Commande pour tracer le graphique

    for(int i = 0; i < ARRAY_SIZE; i++) { // Parcours du tableau
        fprintf(gnuplotPipe, "%d %d\n", i, data[i]); // Écriture des données dans le pipe
    }

    fprintf(gnuplotPipe, "e\n"); // Fin de l'écriture des données
    fflush(gnuplotPipe); // Vidage du buffer

    pclose(gnuplotPipe); // Fermeture du pipe
}