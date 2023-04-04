#include <wx/wx.h>

class Menu:public wxFrame{
    public:
    Menu(const wxString& title);
    wxButton* Start_Button;
    wxPNGHandler *handler = new wxPNGHandler; // Pour gérer les images PNG
    wxStaticBitmap *menu;
    void On_Start(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
    DECLARE_EVENT_TABLE()
};