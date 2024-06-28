#pragma once

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include "speaker.h"

using namespace std;

// Design Manager class

class SpeechManager
{
public:

	// Constructor

	SpeechManager();


	// Initialize the containers and attributes

	void init_speech();


	// Create 12 competitors

	void create_speakers();


	// Show Menu

	void show_menu();


	// Quit application

	void exit_system();


	// Destructor

	~SpeechManager();


	// Member Attributes

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


};