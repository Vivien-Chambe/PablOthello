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
vector<int> Grille::getScore(){
    vector<int> score = {0,0};
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if (getEtat(i,j) == Noir)
                score[0]++;
            else if (getEtat(i,j) == Blanc)
                score[1]++;
        }
    }
    return score;
}


// classe jeu
enum Direction {Nord, NordEst, Est, SudEst, Sud, SudOuest, Ouest, NordOuest};


bool Jeu::est_valide(int ligne, int colonne, Joueur joueur){ // Doit seulement vérifier si on peut jouer ici
    Etat adv;
    Etat couleur;
    int i = 0;
    int j = 0;
    int n = g.n;
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

            while(i>=0 && i<n && j>=0 && j<n && g.getEtat(i,j)==adv){
                a_retourner.push_back(Coordonnees(i,j));
                i+=dy;
                j+=dx;
            }
            if(a_retourner.size() >= 1 && i>=0 && i<n && j>=0 && j<n && g.getEtat(i,j)==couleur){
                valide=true;
            }
            a_retourner.clear();
        }
    }
    a_retourner.clear();
    
    return valide;
}



bool Jeu::jouerBlanc(int ligne,int colonne){
    int n = g.n;
    if (g.getEtat(ligne,colonne) == Vide)
    {
        if (est_valide(ligne,colonne,J1)){
            vector<Coordonnees> a_retourner;
            int i,j;
            for (int dx=-1;dx<=1;dx++){
                for(int dy = -1;dy<=1;dy++){
                    if (dx==0 && dy==0)
                        continue;
                
                    i = ligne+dy;
                    j = colonne+dx;

                    while(i>=0 && i<n && j>=0 && j<n && g.getEtat(i,j)==Noir){
                        a_retourner.push_back(Coordonnees(i,j));
                        i+=dy;
                        j+=dx;
                    }
                    if(a_retourner.size() >= 1 && i>=0 && i<n && j>=0 && j<n && g.getEtat(i,j)==Blanc){
                        g.ajouterPion(ligne,colonne,J1);
                        for(long unsigned int k = 0; k<a_retourner.size(); k++){g.ajouterPion(a_retourner[k].getx(),a_retourner[k].gety(),J1);}
                    }
                    a_retourner.clear();
                }
            }
            a_retourner.clear();
            return true;
        }
        else
            return false;
    }
    else
        return false;
}
bool Jeu::jouerNoir(int ligne,int colonne){
    int n = g.n;
    if (g.getEtat(ligne,colonne) == Vide)
    {
        if (est_valide(ligne,colonne,J2)){
            vector<Coordonnees> a_retourner;
            int i,j;
            for (int dx=-1;dx<=1;dx++){
                for(int dy = -1;dy<=1;dy++){
                    if (dx==0 && dy==0)
                        continue;
                
                    i = ligne+dy;
                    j = colonne+dx;

                    while(i>=0 && i<n && j>=0 && j<n && g.getEtat(i,j)==Blanc){
                        a_retourner.push_back(Coordonnees(i,j));
                        i+=dy;
                        j+=dx;
                    }
                    if(a_retourner.size() >= 1 && i>=0 && i<n && j>=0 && j<n && g.getEtat(i,j)==Noir){
                        g.ajouterPion(ligne,colonne,J2);
                        for(long unsigned int k = 0; k<a_retourner.size(); k++){g.ajouterPion(a_retourner[k].getx(),a_retourner[k].gety(),J2);}
                    }
                    a_retourner.clear();
                }
            }
            a_retourner.clear();
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

bool Jeu::is_fini(){
    int n = g.n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g.getEtat(i,j) == Vide)
            {
                if (est_valide(i,j,J1) || est_valide(i,j,J2))
                    return false; // 
            }
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

// Fonction qui renvoie le nombre potentiel de pions que le joueur peut retourner en jouant à la position (ligne,colonne)

int Jeu::nb_pions(int ligne, int colonne, Joueur joueur){
    Etat adv;
    Etat couleur;
    int n = g.n;
    int nb = 0;
    if (joueur==J1){adv = Noir;couleur = Blanc;}
    else if (joueur==J2){adv = Blanc;couleur = Noir;}

    if (g.getEtat(ligne,colonne) == Vide)
    {
        if (est_valide(ligne,colonne,joueur)){
            vector<Coordonnees> a_retourner;
            int i,j;
            for (int dx=-1;dx<=1;dx++){
                for(int dy = -1;dy<=1;dy++){
                    if (dx==0 && dy==0)
                        continue;
                
                    i = ligne+dy;
                    j = colonne+dx;

                    while(i>=0 && i<n && j>=0 && j<n && g.getEtat(i,j)==adv){
                        a_retourner.push_back(Coordonnees(i,j));
                        i+=dy;
                        j+=dx;
                    }
                    if(a_retourner.size() >= 1 && i>=0 && i<n && j>=0 && j<n && g.getEtat(i,j)==couleur){
                        nb += a_retourner.size();
                    }
                    a_retourner.clear();
                }
            }
            a_retourner.clear();
        }
    }
    return nb;
}


Joueur Jeu::getJoueur(){return J;}
void Jeu::setJoueur(Joueur j){J = j;}

bool Jeu::peut_jouer(Joueur joueur){
    int n = g.n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g.getEtat(i,j) == Vide)
            {
                if (est_valide(i,j,joueur))
                    return true;
            }
        }
    }
    return false;
}