#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "../include/Portaudio.h"
#include "../include/graphe.h"
#include "../include/kaybordact.h"

int numSamples = (int)(DURATION * SAMPLING_RATE);

   
int main(void) {
    int *isPress = NULL;
    FILE *gnuplot = popen("gnuplot", "w");
    isPress=initializeIsPressArray(numSamples);

    if (isPress == NULL) {
        // Gestion d'erreur en cas d'échec de l'allocation
        return 1;
    }

    //volatile int keyPressed = 0; // Définition de la variable globale
    PaError err;
    PaStream *stream;
    //int size = (int)END_FREQ- (int)START_FREQ + 1;
    double *signal = (double *)malloc(numSamples * sizeof(double));

    pthread_t thread_id;
    pthread_create(&thread_id, NULL,checKeyPress, NULL);


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
    //pthread_create(&thread_id, NULL, keyboardInput, NULL);

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

    generate_graph(isPress);

    free(isPress);

    fprintf(gnuplot, "e\n");
    fprintf(stdout, "Click Ctrl+d to quit...\n");
    fflush(gnuplot);
    getchar();

    pclose(gnuplot);
    exit(EXIT_SUCCESS);

}
