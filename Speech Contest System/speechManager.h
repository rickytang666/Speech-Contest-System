#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<map>
#include<algorithm>
#include<numeric>
#include<functional>
#include "speaker.h"

using namespace std;

// Design Manager class

class SpeechManager
{
public:

	// FUNCTIONS

	// Constructor

	SpeechManager();


	// Initialize the containers and attributes

	void init_speech();


	// Create 12 competitors

	void create_speakers();


	// Start Contest -> The whole process control

	void start_speech();

	
	// Draw

	void speech_draw();


	// Actual contest

	void speech_contest();


	// Display scores

	void show_advanced_results();


	// Save contest results

	void save_record();

	
	// Search and check the past contest record

	void load_record();


	// Display the past records to user

	void show_record();


	// Show Menu

	void show_menu();


	// Quit application

	void exit_system();


	// Destructor

	~SpeechManager();


	/************************************************************************/


	// MEMBER ATTRIBUTES

	// container for storing round1 competitors

	vector<int> v1;

	// container for storing final round competitors
	
	vector<int> v2;

	// container for storing podium competitors

	vector<int> vPodium;

	// container for storing number and competitor accordingly

	map<int, Speaker> m_Speakers;

	// variable for storing current round number

	int m_Index;

	// Boolean to check if the file is empty

	bool fileIsEmpty;

	// Map for storing the past records

	map<int, vector<string>> m_Record;


};