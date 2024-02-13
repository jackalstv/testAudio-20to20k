#include "../include/Audio.h"
#include <portaudio.h>


void generateSignal(float *signal, double duration, double startFreq, double endFreq, double samplingRate) {
    double timeStep = 1.0 / samplingRate;
    double currentTime = 0.0;
    int numSamples = (int)(duration * samplingRate);

    for (int i = 0; i < numSamples; ++i) {
        double currentFreq = startFreq + (endFreq - startFreq) * (currentTime / duration);
        signal[i] = (float)sin(2.0 * PI * currentFreq * currentTime);
        currentTime += timeStep;
    }
}

int paCallback(const void *inputBuffer, void *outputBuffer,
               unsigned long framesPerBuffer,
               const PaStreamCallbackTimeInfo *timeInfo,
               PaStreamCallbackFlags statusFlags,
               void *userData) {
    float *out = (float *)outputBuffer;
    float *signal = (float *)userData;
    static unsigned long signalIndex = 0;

    for (unsigned long i = 0; i < framesPerBuffer; i++) {
        if (signalIndex < SAMPLING_RATE * DURATION) {
            *out++ = signal[signalIndex++];
        } else {
            *out++ = 0.0f; // Fill with zeros if signal is finished
        }
    }

    return signalIndex < SAMPLING_RATE * DURATION ? paContinue : paComplete;
}
