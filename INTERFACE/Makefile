# Makefile pour le projet wxWidgets
ifdef speed
SPEED = -DSPEED=$(speed)
endif
ifdef taille
TAILLE = -DTAILLE=$(taille)
endif

# Compilateur C++
CXX = g++

# Flags de compilation
CXXFLAGS = -Wall -std=c++11 `wx-config --cxxflags` 

# Flags de linkage
LDFLAGS = `wx-config --libs` $(SPEED) $(TAILLE)

# Fichiers source du projet
SRCS = main.cpp fenetre.cpp grille.cpp menu.cpp

# Nom de l'exécutable
EXE = PablOthello

all: $(EXE)

$(EXE): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(EXE) $(LDFLAGS)

clean:
	rm -f $(EXE)

run:clean all
	./$(EXE)