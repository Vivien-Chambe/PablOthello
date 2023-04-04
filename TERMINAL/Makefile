# Makefile pour le projet wxWidgets

# Compilateur C++
CXX = g++

# Flags de compilation
CXXFLAGS = -Wall -std=c++11 `wx-config --cxxflags` 

# Flags de linkage
LDFLAGS = `wx-config --libs`

# Fichiers source du projet
SRCS = main.cpp grille.cpp

# Nom de l'exécutable
EXE = PablOthello_TERM

all: $(EXE)

$(EXE): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(EXE) $(LDFLAGS)

clean:
	rm -f $(EXE)

run:clean all
	./$(EXE)