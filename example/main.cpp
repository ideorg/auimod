#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "../auibook.h"
#include <wx/stc/stc.h>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame();
private:
    wxAuiManager manager;
    wxAuiNotebook* auiNotebook;
    void OnExit(wxCommandEvent& event);
};
enum
{
    ID_Wx = 1,
    ID_New = 2
};
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    wxInitAllImageHandlers();
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}
MyFrame::MyFrame()
        : wxFrame(NULL, wxID_ANY, "Hello World")
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    manager.SetManagedWindow(this);
    manager.SetFlags(wxAUI_MGR_DEFAULT);
    auiNotebook = new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize );
    manager.AddPane(auiNotebook, wxAuiPaneInfo().Left().Caption(wxT("Edytor")).MaximizeButton(true).MinimizeButton(true).PinButton(true).PaneBorder(false).Dock().Resizable().FloatingSize(wxDefaultSize).CentrePane().DefaultPane());
    sizer->Add(auiNotebook, 1, wxEXPAND | wxALL, 0);

    SetSizer(sizer);
    auiNotebook->AddPage(new wxStyledTextCtrl(auiNotebook,wxID_ANY), "1111");
    auiNotebook->AddPage(new wxStyledTextCtrl(auiNotebook,wxID_ANY), "2222");
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
