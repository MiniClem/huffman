CC = gcc
CFLAGS = -Wall

# Détermine où se trouvent les headers
IDIR = ../include

# Répertoire pour les objets
ODIR = obj

# Ajouter les .h dans _DEPS puis décommenter les 2 lignes
_DEPS = liste.h liste_ext.h arbre.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# Les fichiers objets
_OBJ = main.o liste.o liste_ext.o arbre.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Compile tous les fichiers sources 
$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Le fichier éxécutable
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~