#include <wx/wx.h>
#include <wx/grid.h>
#include "grille.h"

class Fenetre : public wxFrame {
public:
    Fenetre(const wxString& title);
    wxPanel *PanelJ1;
    wxPanel *PanelJ2;
    wxPanel *Plateau;

    wxPNGHandler *handler = new wxPNGHandler; // Pour gérer les images PNG
    wxStaticBitmap *cactus_blanc;
    wxStaticBitmap *cactus_noir;

    wxButton *nouvellePartie;
    wxButton *userJ1;
    wxButton *iaJ1;
    wxButton *ia2J1;
    wxButton *userJ2;
    wxButton *iaJ2;
    wxButton *ia2J2;
    int flagJ1 = 0; // Pour savoir contre qui on joue (0 = contre un autre joueur, 1 = contre l'ia random, 2 = contre l'ia minimax)
    int flagJ2 = 0; // Pour savoir contre qui on joue (0 = contre un autre joueur, 1 = contre l'ia random, 2 = contre l'ia minimax)
    wxTimer *timer;

    wxGrid *grid;
    wxStaticText *text;
    wxStaticText *textJ1;
    wxStaticText *textJ2;
    Jeu j;
    void OnQuit(wxCommandEvent& event);
    void OnLeftClick(wxGridEvent& event);
    void OnNewGame(wxCommandEvent& event);
    void ChangePlayerText(wxCommandEvent& event);
    void ChangeScore();
    void OnTimer(wxTimerEvent& event);

    Coordonnees coup_random(Joueur J);

    void OnIA2J1(wxCommandEvent& event);
    void OnIA2J2(wxCommandEvent& event);

    void OnIAJ1(wxCommandEvent& event);
    void OnIAJ2(wxCommandEvent& event);

    void OnUserJ1(wxCommandEvent& event);
    void OnUserJ2(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()
};

enum {};