#include <wx/wx.h>
#include "menu.h"
#include "fenetre.h"

enum {ID_Start=1};

Menu::Menu(const wxString& title) 
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 500),wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER) {
    Centre();
    menu = new wxStaticBitmap( this, wxID_ANY, wxBitmap("../Images/menu_v2.png", wxBITMAP_TYPE_PNG), wxPoint(0,0), wxSize(500, 500));
    Start_Button = new wxButton(this,
                            ID_Start,
                            wxString("Start Game"),
                            wxPoint(230, 300),
                            wxSize(100, 50));
    wxImage::AddHandler(handler);
    
    
}

BEGIN_EVENT_TABLE(Menu, wxFrame)
    EVT_BUTTON(ID_Start,Menu::On_Start)
END_EVENT_TABLE()

void Menu::On_Start(wxCommandEvent& event){
    Fenetre *fenetre = new Fenetre("PablOthello");
    fenetre->Show(true);
    this->Close(true);
}

void Menu::OnQuit(wxCommandEvent& event){
    Close(true);
}