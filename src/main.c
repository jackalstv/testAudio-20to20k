#include "../include/Audio.h"
#include <portaudio.h>


int main(void) {
    PaError err;
    PaStream *stream;
    int numSamples = (int)(DURATION * SAMPLING_RATE);
    float *signal = (float *)malloc(numSamples * sizeof(float));

    if (signal == NULL) {
        fprintf(stderr, "Could not allocate memory for signal\n");
        return 1;
    }

    generateSignal(signal, DURATION, START_FREQ, END_FREQ, SAMPLING_RATE);

    err = Pa_Initialize();
    if (err != paNoError) goto error;

    err = Pa_OpenDefaultStream(&stream, 0, 1, paFloat32, SAMPLING_RATE, 256, paCallback, signal);
    if (err != paNoError) goto error;

    err = Pa_StartStream(stream);
    if (err != paNoError) goto error;

    printf("Playing...\n");
    while ((err = Pa_IsStreamActive(stream)) == 1) Pa_Sleep(100);
    if (err < 0) goto error;

    err = Pa_CloseStream(stream);
    if (err != paNoError) goto error;

    Pa_Terminate();
    free(signal);
    printf("Done.\n");
    return 0;

    error:
    Pa_Terminate();
    fprintf(stderr, "An error occurred while using the PortAudio stream\n");
    fprintf(stderr, "Error number: %d\n", err);
    fprintf(stderr, "Error message: %s\n", Pa_GetErrorText(err));
    free(signal);
    return -1;
}
