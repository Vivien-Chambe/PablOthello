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
    Jeu(){
        g.ajouterPion(3,3,J1);
        g.ajouterPion(4,4,J1);
        g.ajouterPion(3,4,J2);
        g.ajouterPion(4,3,J2);
    };
    bool est_valide(int ligne, int colonne, Joueur joueur);
    bool jouerBlanc(int ligne,int colonne);
    bool jouerNoir(int ligne,int colonne);
    bool fini();
    void executer();
};
