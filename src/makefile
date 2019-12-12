CC = gcc
CFLAGS = -Wall
CTESTFLAGS = -g

# Détermine où se trouvent les headers
IDIR = ../include

# Répertoire pour les objets
ODIR = obj

# Ajouter les .h dans _DEPS puis décommenter les 2 lignes
_DEPS = liste.h liste_ext.h arbre.h encodage.h file.h interface.h menu_action.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

LIBS=-lm	

# Les fichiers objets
_OBJ = main.o file.o encodage.o liste.o liste_ext.o arbre.o encodage.o interface.o menu_action.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_ENC_TEST_OBJ = encodage.o liste.o liste_ext.o arbre.o file.o interface.o
ENC_TEST_OBJ = $(patsubst %,$(ODIR)/%,$(_ENC_TEST_OBJ))

_FILE_TEST_OBJ = file.o liste.o liste_ext.o arbre.o interface.o
FILE_TEST_OBJ = $(patsubst %,$(ODIR)/%,$(_FILE_TEST_OBJ))

# Compile tous les fichiers sources 
$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Le fichier éxécutable
test_encodage: $(ENC_TEST_OBJ)
	$(CC) -o $@ $^ $(CTESTFLAGS) $(CFLAGS) $(LIBS)

test_file: $(FILE_TEST_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -fv $(ODIR)/*.o *~ core $(INCDIR)/*~