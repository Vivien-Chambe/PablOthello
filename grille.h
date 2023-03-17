#include <vector>
#include <iostream>
using namespace std;

enum Joueur {J1, J2};
enum Etat {Vide, Noir, Blanc};

class Grille{
    private:
    vector<vector<int>> grille;
    public:
    Grille(){
        vector<int> myvector;
        for(int i = 0; i<=7; i++)
        {
            for(int j = 0; j<=7; j++)
            {
                myvector.push_back(Vide);
            }
            grille.push_back(myvector);
        }
    }
    void afficherGrille();
    void ajouterPion(int ligne,int colonne, Joueur J);
    int getEtat(int ligne, int colonne);
    int getScore(); // Différence entre le nombre de pions noirs et blancs
};

class Jeu{
    private:
    Grille g;
    Joueur J=J1;
    public:
    Jeu(){};
    bool jouerBlanc(int ligne,int colonne);
    bool jouerNoir(int ligne,int colonne);
    Etat fini();
    void executer();
};
