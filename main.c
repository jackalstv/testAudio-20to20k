#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <portaudio.h>

#define PI 3.14159265358979323846

#define START_FREQ 5.0
#define END_FREQ 21000.0
#define DURATION 20.0
#define SAMPLING_RATE 44100.0

void generateSignal(double *signal, int numSamples) {
    double deltaFreq = (END_FREQ - START_FREQ) / DURATION;
    double timeStep = 1.0 / SAMPLING_RATE;
    double currentTime = 0.0;

    for (int i = 0; i < numSamples; ++i) {
        signal[i] = sin(2.0 * PI * currentTime);
        currentTime += deltaFreq * timeStep;
    }
}

// Fonction de rappel (callback) pour PortAudio
int paCallback(const void *inputBuffer, void *outputBuffer,
               unsigned long framesPerBuffer,
               const PaStreamCallbackTimeInfo *timeInfo,
               PaStreamCallbackFlags statusFlags,
               void *userData) {
    double *signal = (double *)userData;
    float *out = (float *)outputBuffer;

    static unsigned long frameIndex = 0;

    // Calculer la fréquence actuelle
    double currentFreq = START_FREQ + (END_FREQ - START_FREQ) * frameIndex / (SAMPLING_RATE * DURATION);
    printf("Frequency: %.2f Hz\n", currentFreq);

    // Générer le signal
    for (unsigned long i = 0; i < framesPerBuffer; ++i) {
        *out++ = (float)(sin(2.0 * PI * currentFreq * i / SAMPLING_RATE));
    }

    frameIndex += framesPerBuffer;

    return paContinue;
}

int main() {
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

    // Ouvrir le flux audio
    err = Pa_OpenDefaultStream(&stream, 0, 1, paFloat32, SAMPLING_RATE, paFramesPerBufferUnspecified,
                               paCallback, signal);
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
