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


// Start Contest -> The whole process control

void SpeechManager::start_speech()
{
	// ROUND 1

	// 1. Draw

	this->speech_draw();


	// 2. Speeches

	this->speech_contest();


	// 3. Display advanced to final


	/************************************************************/


	// ROUND 2

	// 1. Draw


	// 2. Speeches


	// 3. Show final results


	// 4. Record the results into the file

}


// Draw

void SpeechManager::speech_draw()
{
	cout << "This is round <" << this->m_Index << "> competitors taking draws" << endl;

	cout << "-------------------------------------------------" << endl;

	cout << "The decided speech order as shown below: " << endl;


	if (this->m_Index == 1)
	{
		// Round 1

		random_shuffle(this->v1.begin(), this->v1.end());

		for (const int& num : v1)
		{
			cout << num << " ";
		}
		cout << endl;

	}
	else
	{
		// Round 2

		random_shuffle(this->v2.begin(), this->v2.end());

		for (const int& num : v2)
		{
			cout << num << " ";
		}
		cout << endl;

	}

	cout << "-------------------------------------------------" << endl;

	system("pause");
	cout << endl;

}


// Actual contest

void SpeechManager::speech_contest()
{
	cout << "---------- Contest Round <" << this->m_Index << "> begins! ----------" << endl;

	// prepare a temporary container to store the group results

	multimap<double, int, greater<double>> group_score;

	int num = 0; // record the people's number -> 6 people/group


	vector<int> v_Src; // Competitors' container

	v_Src = (this->m_Index == 1) ? this->v1 : this->v2; // Use ternary operator to determine the competitors' container

	// Iterate through competitors

	for (int& it : v_Src)
	{
		++num;

		// GIVE MARKS

		//  Put 10 marks, sort, remove highest and lowest

		deque<double> d; // Used to store all the scores on 1 person

		for (int i = 0; i < 10; ++i)
		{
			double score = (rand() % 401 + 600) / 10.0;
			/*cout << score << " ";*/
			d.push_back(score);
		}
		/*cout << endl;*/

		sort(d.begin(), d.end(), greater<double>()); // sort the 10 marks
		d.pop_front(); // remove highest
		d.pop_back(); // remove lowest

		double sum = accumulate(d.begin(), d.end(), 0.0); // total mark
		double avg = sum / (double)d.size(); // average mark

		// print the average mark

		/*cout << "Number " << it << " Name: " << this->m_Speakers[it].m_Name << " Mark: " << avg << endl;*/


		// put the average mark into the map

		this->m_Speakers[it].m_Score[this->m_Index - 1] = avg;

		// put the marking data into the group container

		group_score.insert(make_pair(avg, it)); // KEY is mark; VALUE is competitor id


		// Pick 3 people in every 6 people (6 people/group)

		if (num % 6 == 0)
		{
			cout << "Group " << int(num / 6) << " results: " << endl;

			for (const pair<double, int>& value : group_score)
			{
				cout << "Number: " << value.second << " Name: " << this->m_Speakers[value.second].m_Name << " Mark: " << value.first << endl;

			}

			// Pick out the top3 in the group and put them in next round

			int count = 0; // tell how many I've picked in each group

			for (const pair<double, int>& value : group_score)
			{
				if (this->m_Index == 1)
				{
					v2.push_back(value.second);
				}
				else
				{
					vPodium.push_back(value.second);
				}

			}

			group_score.clear(); // This group finished, so we clear it
			cout << endl; // separation

		}

	}

	cout << "---------- Contest Round < " << this->m_Index << " > Finished ----------" << endl;
	system("pause");

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