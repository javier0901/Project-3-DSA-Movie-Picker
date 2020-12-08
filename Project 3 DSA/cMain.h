#pragma once
#include "wx/wx.h"
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:
	wxButton* m_btn1 = nullptr;
	wxTextCtrl* m_txt1 = nullptr;
	wxListBox* m_list1 = nullptr;
	wxStaticText* genres = nullptr;
	wxStaticText* instructions = nullptr;

	map<string, string> movies;

	void OnButtonClicked(wxCommandEvent& evt);
	void initMap();




	wxDECLARE_EVENT_TABLE();
};

