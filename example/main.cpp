#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "../auibook.h"
#include <wx/stc/stc.h>
#include <wx/filename.h>
#include "MyTabArt.h"

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
    void OnNew(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
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
    menuFile->Append(wxID_NEW);
    wxMenuItem *open_file = new wxMenuItem(menuFile, wxID_OPEN, "Open file\tCtrl-O", "");
    menuFile->Append(open_file);
    menuFile->Append(wxID_EXIT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
    Bind(wxEVT_MENU, &MyFrame::OnNew, this, wxID_NEW);
    Bind(wxEVT_MENU, &MyFrame::OnOpen, this, wxID_OPEN);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    manager.SetManagedWindow(this);
    manager.SetFlags(wxAUI_MGR_DEFAULT);
    auiNotebook = new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize );
    auiNotebook->GetTabs()->SetWantHomeEnd(true);
    wxAuiTabArt *art = new MyTabArt;
    auiNotebook->SetArtProvider(art);
    manager.AddPane(auiNotebook, wxAuiPaneInfo().Left().Caption(wxT("Edytor")).MaximizeButton(true).MinimizeButton(true).PinButton(true).PaneBorder(false).Dock().Resizable().FloatingSize(wxDefaultSize).CentrePane().DefaultPane());
    sizer->Add(auiNotebook, 1, wxEXPAND | wxALL, 0);
    SetSizer(sizer);
}

void MyFrame::OnNew(wxCommandEvent& event)
{
    auiNotebook->AddPageEx(new wxStyledTextCtrl(auiNotebook,wxID_ANY), nullptr, "Untitled");
}

void MyFrame::OnOpen(wxCommandEvent& event)
{
    wxFileDialog openDialog(this, wxT("Open file"), "..", "", "*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (openDialog.ShowModal() == wxID_CANCEL) return;
    wxStyledTextCtrl* stc = new wxStyledTextCtrl(auiNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0L, "");
    stc->LoadFile(openDialog.GetPath());
    wxFileName file(openDialog.GetPath());
    wxString title = file.GetFullName();
    auiNotebook->AddPageEx(stc, nullptr, title, true);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
