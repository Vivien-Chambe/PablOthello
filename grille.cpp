#include "grille.h"
#include "vector"
#include "iostream"
using namespace std;


// classe grille
void Grille::afficherGrille(){  
    for(int i = 0; i<=7; i++)
    {
        for(int j = 0; j<=7; j++)
        {
            if (grille[i][j] == Vide)
                cout << "🟩"<< " ";
            else if (grille[i][j] == Noir)
                cout << "⬛" << " ";
            else if (grille[i][j] == Blanc)
                cout << "⬜"<< " ";
            else
                cout << "Erreur" << " ";
        }
        cout << endl;
    }
}
void Grille::ajouterPion(int ligne,int colonne, Joueur J){
    if (J == J1)
        grille[ligne][colonne] = Blanc;
    if (J == J2)
        grille[ligne][colonne] = Noir;
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
enum Direction {Nord, NordEst, Est, SudEst, Sud, SudOuest, Ouest, NordOuest};
class Coordonnees{
    public:
    int x = 0;
    int y = 0;
    Coordonnees(int x,int y): x(x),y(y){}
    int getx(){return x;}
    int gety(){return y;}
};

bool Jeu::est_valide(int ligne, int colonne, Joueur joueur){
    Etat adv;
    Etat couleur;
    int i = 0;
    int j = 0;
    if (joueur==J1){adv = Noir;couleur = Blanc;}
    else if (joueur==J2){adv = Blanc;couleur = Noir;}
        
   
    
    vector<Coordonnees> a_retourner;
    bool valide=false;
    for (int dx=-1;dx<=1;dx++){
        for(int dy = -1;dy<=1;dy++){
            if (dx==0 && dy==0)
                continue;
            
            i = ligne+dy;
            j = colonne+dx;

            while(i>=0 && i<=7 && j>=0 && j<=7 && g.getEtat(i,j)==adv){
                a_retourner.push_back(Coordonnees(i,j));
                i+=dy;
                j+=dx;
            }
            if(a_retourner.size() >= 1 && i>=0 && i<=7 && j>=0 && j<=7 && g.getEtat(i,j)==couleur){
                // Afficher le contenu du vecteur a_retourner

                for (int k=0;k<a_retourner.size();k++){
                    cout << a_retourner[k].getx() << " " << a_retourner[k].gety() << endl;
                }
                g.ajouterPion(ligne,colonne,joueur);
                for(int k = 0; k<a_retourner.size(); k++)
                {   
                    g.ajouterPion(a_retourner[k].getx(),a_retourner[k].gety(),joueur);
                }
                valide=true;
                
            }
            a_retourner.clear();
        }
    }
    a_retourner.clear();
    
    return valide;
}



bool Jeu::jouerBlanc(int ligne,int colonne){
    if (g.getEtat(ligne,colonne) == Vide)
    {
        bool valide = est_valide(ligne,colonne,J1);
        return valide;
    }
    else
        return false;
}
bool Jeu::jouerNoir(int ligne,int colonne){
    if (g.getEtat(ligne,colonne) == Vide)
    {
        bool valide = est_valide(ligne,colonne,J2);
        return valide;
    }
    else
        return false;
}
bool Jeu::fini(){
    for(int i = 0; i<=7; i++)
    {
        for(int j = 0; j<=7; j++)
        {
            if (g.getEtat(i,j) == Vide)
                return false;
        }
    }
    return true;
}
void Jeu::executer(){
    int ligne, colonne;
    bool fin = false;
    g.afficherGrille();
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
            else
                cout << "Erreur J1" << endl;
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
            else
                cout << "Erreur J2" << endl;
        }
        g.afficherGrille();
    }
}