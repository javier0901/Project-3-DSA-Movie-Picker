#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "MoviePicker", wxPoint(30, 30), wxSize(800,600))
{
	wxFont font(18, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	m_btn1 = new wxButton(this, 10001, "Top 10", wxPoint(10, 10), wxSize(100, 50));
	m_btn1->SetFont(font);

	instructions = new wxStaticText(this, wxID_ANY, "Enter a movie genre below", wxPoint(125, 20), wxSize(100, 50));
	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
	
	const wxString movieGenres = "Genres: \n";
	genres = new wxStaticText(this, wxID_ANY, movieGenres, wxPoint(350, 130), wxSize(300, 300));

}

cMain::~cMain()
{
}

void cMain::OnButtonClicked(wxCommandEvent& evt)
{
	m_list1->AppendString(m_txt1->GetValue());
	evt.Skip();
}


