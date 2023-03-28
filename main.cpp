#include <wx/wx.h>

#include "fenetre.h"
#include "main.h"

bool MyApp::OnInit() {
    Fenetre *fenetre = new Fenetre("PablOthello");
    fenetre->Show(true);
    return true;
}

wxIMPLEMENT_APP(MyApp);
