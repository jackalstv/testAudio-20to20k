# egaliseur_audio_adaptatif
Pour mon projet de M1, j'ai à réaliser un égaliseur audio adaptatif. Je mets mon code au fil de l'avancement du projet.

Le projet se fait sur un Raspberry Pi 4 avec la version du 5 décembre 2023.
J'utilise une carte son Audio Injector Stereo.
Un casque ATH-AD900X de chez Audio-Technica.

21/12/2023
J'ai pour l'instant un fichier main.c.
Pour le compiler, il faut installer PortAudio :

sudo apt-get install portaudio19-dev

Pour compiler :

gcc -o generate_and_play main.c -lportaudio -lm

./generate_and_play

-> Pour la suite, je vais modifier le système de calcul de la fréquence.
