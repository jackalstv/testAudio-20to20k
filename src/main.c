#include <stdlib.h>
#include <stdio.h>
#include "../include/Portaudio.h"
extern int isPress;
extern float x[];
int main() {
    FILE *gnuplot = popen("gnuplot", "w");
    PaError err;
    PaStream *stream;
   int size = (int)END_FREQ- (int)START_FREQ + 1;
    int numSamples = (int)(DURATION * SAMPLING_RATE);
    double *signal = (double *)malloc(numSamples * sizeof(double));

    generateSignal(signal, numSamples);

    // Initialiser PortAudio
    err = Pa_Initialize();
    if (err != paNoError) {
        fprintf(stderr, "Erreur d'initialisation de PortAudio: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    if (!gnuplot) {
        perror("popen");
        exit(EXIT_FAILURE);
    }
    // Ouvrir le flux audio
    err = Pa_OpenDefaultStream(&stream, 0, // no input channels
                               1, // mono output 2 for stereo
                               paFloat32, // 32-bit floating-point output
                               SAMPLING_RATE, // sample rate in Hz (44100.0)
                               paFramesPerBufferUnspecified, // frames per buffer
                               paCallback, // callback function
                               signal // pointer to data passed to callback
                               );

    fprintf(gnuplot, "plot '-' u 1:2 t 'Price' w lp\n");
    for (int i = 0; i < size; ++i) {
        fprintf(gnuplot, "%f %d\n", x[i], 0);
    }
    fprintf(gnuplot, "e\n");

    if (err != paNoError) {
        fprintf(stderr, "Erreur lors de l'ouverture du flux audio: %s\n", Pa_GetErrorText(err));
        Pa_Terminate();
        return 1;
    }

    // Démarrer le flux audio
    err = Pa_StartStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Erreur lors du démarrage du flux audio: %s\n", Pa_GetErrorText(err));
        Pa_CloseStream(stream);
        Pa_Terminate();
        return 1;
    }

    printf("Enregistrement en cours...\n");

    // Attendre la fin de l'enregistrement
    Pa_Sleep((unsigned long)(DURATION * 1000));

    // Arrêter et fermer le flux audio
    err = Pa_StopStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Erreur lors de l'arrêt du flux audio: %s\n", Pa_GetErrorText(err));
    }

    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Erreur lors de la fermeture du flux audio: %s\n", Pa_GetErrorText(err));
    }

    // Terminer PortAudio
    Pa_Terminate();

    printf("Enregistrement terminé.\n");

    // Libérer la mémoire
    free(signal);

    return 0;
}
