# egaliseur_audio_adaptatif
Pour mon projet de M1 j'ai a realiser un egaliseur audio adaptatif, je mes mon code au file de l'avancement du projet

Le projet se fais sur une Rspaberry pi 4 avec la version du 5 decembre 2023.
J'utilise une carte son audio injector-stereo.
Un casque ATH-AD900X de chez Audiotechnica.

 21/12/2023
 J'ai pour l'instant un main.c
 pour le compiler il faut insaller portaudio 

sudo apt-get install portaudio19-dev

Pour compiler :

gcc -o generate_and_play main.c -lportaudio -lm

Pour lancver le code :

./generate_and_play
