#include <vector>
#include <iostream>
using namespace std;

enum Joueur {J1, J2};
enum Etat {Vide, Noir, Blanc};

class Grille{
    private:
    vector<vector<int>> grille;
    public:
    int n = 8; // On peut aller jusquà 40 au maximum avant que l'affichage fasses n'importe quoi
    Grille(){
        vector<int> myvector;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                myvector.push_back(Vide);
            }
            grille.push_back(myvector);
        }
    }
    void afficherGrille();
    void ajouterPion(int ligne,int colonne, Joueur J);
    int getEtat(int ligne, int colonne);
    vector<int> getScore(); // Différence entre le nombre de pions noirs et blancs
};

class Jeu{
    private:
    
    Joueur J=J2;
    
    public:
    Grille g;
    bool fini = false;
    Jeu(){
        g.ajouterPion(3,3,J1);
        g.ajouterPion(4,4,J1);
        g.ajouterPion(3,4,J2);
        g.ajouterPion(4,3,J2);
    }
    bool est_valide(int ligne, int colonne, Joueur joueur);
    bool peut_jouer(Joueur joueur);
    bool jouerBlanc(int ligne,int colonne);
    bool jouerNoir(int ligne,int colonne);
    bool is_fini();
    void executer();
    Joueur getJoueur();
    void setJoueur(Joueur joueur);
};

class Coordonnees{
    public:
    int x = 0;
    int y = 0;
    Coordonnees(int x,int y): x(x),y(y){}
    int getx(){return x;}
    int gety(){return y;}
};