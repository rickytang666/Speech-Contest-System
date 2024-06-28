#include "speechManager.h"

// Constructor

SpeechManager::SpeechManager()
{
	// Initialize containers and attributes

	this->init_speech();

	// Create 12 speakers

	this->create_speakers();
}


// Initialize the containers and attributes

void SpeechManager::init_speech()
{
	// Clear all containers

	this->v1.clear();
	this->v2.clear();
	this->vPodium.clear();
	this->m_Speakers.clear();


	// Initialize rounds

	this->m_Index = 1;
}


// Create 12 competitors

void SpeechManager::create_speakers()
{
	string nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSeed.size(); ++i)
	{
		string name = string("Player") + nameSeed[i];

		Speaker sp;
		sp.m_Name = name;

		// All the scores are 0

		for (int j = 0; j < 2; ++j)
		{
			sp.m_Score[j] = 0;
		}

		// Create numbers for competitors and put them into v1 container

		this->v1.push_back(i + 10001);

		// put the numbers and according competitors into the map container

		this->m_Speakers.insert(make_pair(i + 10001, sp));

	}
}


// Show Menu

void SpeechManager::show_menu()
{
	cout << "********************************************************" << endl;
	cout << "*************  Welcome to Speech Contest ***************" << endl;
	cout << "*************  1.Start Contest  ************************" << endl;
	cout << "*************  2.See Past Records  *********************" << endl;
	cout << "*************  3.Clear Contest Records  ****************" << endl;
	cout << "*************  0.Quit Contest Application  *************" << endl;
	cout << "********************************************************" << endl;
	cout << endl;
}


// Quit application

void SpeechManager::exit_system()
{
	cout << "See you next time :)" << endl;
	system("pause");
	exit(0);
}


// Destructor

SpeechManager::~SpeechManager()
{

}