# Nom de l'exécutable à générer
TARGET = mon_programme

# Compilateur
CC = gcc

# Dossiers
SRCDIR = src
OBJDIR = obj
BINDIR = bin
INCDIR = include

# Options de compilation
CFLAGS = -I$(INCDIR) -Wall
LDFLAGS = -lportaudio -lm -pthread

# Trouver tous les fichiers .c dans le dossier src (et sous-dossiers)
SRC = $(wildcard $(SRCDIR)/*.c)

# Nommer les fichiers objets en remplaçant les .c par .o et en changeant le dossier src par obj
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Règle par défaut
all: $(BINDIR)/$(TARGET)

# Lier les objets pour créer l'exécutable, placer dans bin/
$(BINDIR)/$(TARGET): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $^ -o $@ $(LDFLAGS)

# Compiler les fichiers source en objets, placer dans obj/
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyer le projet (supprimer objets et exécutable)
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Pour empêcher les conflits avec un fichier du même nom que ces règles
.PHONY: all clean
