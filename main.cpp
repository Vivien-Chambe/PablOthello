#include <wx/wx.h>

#include "fenetre.h"
#include "menu.h"
#include "main.h"

bool MyApp::OnInit() {
    Menu *menu = new Menu("Menu PablOthello");
    menu->Show(true);
    return true;
}

wxIMPLEMENT_APP(MyApp);
