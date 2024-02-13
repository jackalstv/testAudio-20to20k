
#include "../include/Portaudio.h"

int main() {
    FILE *gnuplot = popen("gnuplot", "w");
    PaError err;
    PaStream *stream;
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
    err = Pa_OpenDefaultStream(&stream, 0,
                               1,
                               paFloat32,
                               SAMPLING_RATE,
                               paFramesPerBufferUnspecified,
                               paCallback,
                               signal
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
