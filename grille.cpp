#include "grille.h"
using namespace std;


// classe grille
void Grille::afficherGrille(){  
    for(int i = 0; i<=7; i++)
    {
        for(int j = 0; j<=7; j++)
        {
            if (grille[i][j] == Vide)
                cout << "🤠";
            else if (grille[i][j] == Noir)
                cout << "⬛" << " ";
            else if (grille[i][j] == Blanc)
                cout << "⬜";
            else
                cout << "Erreur" << " ";
        }
        cout << endl;
    }
}
void Grille::ajouterPion(int ligne,int colonne, Joueur J){
    if (J == J1)
        grille[ligne][colonne] = Noir;
    else if (J == J2)
        grille[ligne][colonne] = Blanc;
    else
        cout << "Erreur" << endl;
}
int Grille::getEtat(int ligne, int colonne){return grille[ligne][colonne];}
int Grille::getScore(){
    int score = 0;
    for(int i = 0; i<=7; i++)
    {
        for(int j = 0; j<=7; j++)
        {
            if (getEtat(i,j) == Noir)
                score++;
            else if (getEtat(i,j) == Blanc)
                score--;
        }
    }
    return score;
}


// classe jeu

bool Jeu::jouerBlanc(int ligne,int colonne){
    if (g.getEtat(ligne,colonne) == Vide)
    {
        g.ajouterPion(ligne,colonne,J1);
        return true;
    }
    else
        return false;
}
bool Jeu::jouerNoir(int ligne,int colonne){
    if (g.getEtat(ligne,colonne) == Vide)
    {
        g.ajouterPion(ligne,colonne,J2);
        return true;
    }
    else
        return false;
}
Etat Jeu::fini(){
    return Vide;
}
void Jeu::executer(){
    int ligne, colonne;
    bool fin = false;
    while (fin == false)
    {
        if (J == J1)
        {
            cout << "Joueur 1 (blanc) : " << endl;
            cout << "Ligne : ";
            cin >> ligne;
            cout << "Colonne : ";
            cin >> colonne;
            if (jouerBlanc(ligne,colonne) == true)
                J = J2;
        }
        else
        {
            cout << "Joueur 2 (noir) : " << endl;
            cout << "Ligne : ";
            cin >> ligne;
            cout << "Colonne : ";
            cin >> colonne;
            if (jouerNoir(ligne,colonne) == true)
                J = J1;
        }
        g.afficherGrille();
    }
}