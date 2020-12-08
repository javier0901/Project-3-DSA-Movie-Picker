#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "MoviePicker", wxPoint(30, 30), wxSize(750,500))
{

	SetBackgroundColour(*wxLIGHT_GREY);
	
	m_btn1 = new wxButton(this, 10001, "Top 10", wxPoint(10, 10), wxSize(100, 50));
	wxFont font(18, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	m_btn1->SetFont(font);
	m_btn1->SetBackgroundColour(*wxWHITE);

	instructions = new wxStaticText(this, wxID_ANY, "Enter a movie genre below", wxPoint(125, 20), wxSize(100, 50));
	wxFont instFont(15, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
	instructions->SetFont(instFont);

	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(215, 30));
	wxFont font2(16, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
	m_txt1->SetFont(font2);

	m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(350, 300));
	
	
	wxFont font3(14,wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);

	m_list1->SetFont(font3);
	const wxString movieGenres = "Genres: \n\nAction,  Adventure,  Animation\nComedy,  Crime,  Documentary\nDrama,  Family,  Fantasy\nHistory,  Horror,  Music\nMystery,  Romance,  Science Fiction\nTV Movie,  Thriller,  War,  Western";
	genres = new wxStaticText(this, wxID_ANY, movieGenres, wxPoint(375, 120), wxSize(300, 300));
	genres->SetFont(font3);

}

cMain::~cMain()
{
}

void cMain::OnButtonClicked(wxCommandEvent& evt)
{
	
	evt.Skip();
}

void cMain::initMap()
{
	ifstream file;
	string adult;
	string belongs_to_collect;
	string budget;
	string genres;
	string homepage;
	string id;
	string imdb_id;
	string original_language;
	string original_title;
	string overview;

	file.open("Resource Files/movies_metadata.csv");
	while (!file.eof()) {
		getline(file, adult, ',');
		getline(file, belongs_to_collect, ',');
		getline(file, budget, ',');
		getline(file, genres, ',');
		getline(file, homepage, ',');
		getline(file, id, ',');
		getline(file, imdb_id, ',');
		getline(file, original_language, ',');
		getline(file, original_title, ',');
		file >> overview;

		movies.insert(pair<string, string>(original_title, genres));
	}
}


