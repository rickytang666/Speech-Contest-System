#include "speechManager.h"

// Constructor

SpeechManager::SpeechManager()
{
	// Initialize containers and attributes

	this->init_speech();
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