#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "../include/Portaudio.h"

int main(void) {
    FILE *gnuplot = popen("gnuplot", "w");
    PaError err;
    PaStream *stream;
    int size = (int)END_FREQ- (int)START_FREQ + 1;
    int numSamples = (int)(DURATION * SAMPLING_RATE);
    double *signal = (double *)malloc(numSamples * sizeof(double));

    pthread_t thread_id;

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
    pthread_create(&thread_id, NULL, keyboardInput, NULL);

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
    pthread_cancel(thread_id);
    pthread_join(thread_id, NULL);

    fprintf(gnuplot, "plot '-' u 1:2 t 'Price' w lp\n");
    for (int i = 0; i < size; ++i) {
        fprintf(gnuplot, "%d %d\n", x[i], isPress[i]);
    }
    // Libérer la mémoire
    free(signal);


    fprintf(gnuplot, "e\n");
    fprintf(stdout, "Click Ctrl+d to quit...\n");
    fflush(gnuplot);
    getchar();

    pclose(gnuplot);
    exit(EXIT_SUCCESS);

}
