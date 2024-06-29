#include "speechManager.h"

// Constructor

SpeechManager::SpeechManager()
{
	// Initialize containers and attributes

	this->init_speech();

	// Create 12 speakers

	this->create_speakers();

	// Load past records

	this->load_record();

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

	this->show_advanced_results();


	/************************************************************/


	// ROUND 2

	++this->m_Index; // update the current round number

	// 1. Draw

	this->speech_draw();

	// 2. Speeches

	this->speech_contest();

	// 3. Show final results

	this->show_advanced_results();

	// 4. Record the results into the file

	this->save_record();


	cout << "The whole competition is completed!" << endl;
	system("pause");
	system("cls");

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

			for (multimap<double, int, greater<int>>::iterator it = group_score.begin(); it != group_score.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vPodium.push_back((*it).second);
				}
			}

			group_score.clear(); // This group finished, so we clear it
			cout << endl; // separation

		}

	}

	cout << "---------- Contest Round < " << this->m_Index << " > Finished ----------" << endl;
	system("pause");

}


// Display scores

void SpeechManager::show_advanced_results()
{
	cout << "---------- Contest Round < " << this->m_Index << " > Competitors who Advanced to Final: -----------" << endl;

	vector<int> v;

	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vPodium;
	}

	for (const int& value : v)
	{
		cout << "Number: " << value << "  Name: " << this->m_Speakers[value].m_Name << "  Score: " << this->m_Speakers[value].m_Score[this->m_Index - 1] << endl;

	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_menu();

}


// Save contest results

void SpeechManager::save_record()
{
	ofstream ofs;

	ofs.open("speech_records.csv", ios::out | ios::app); // Using appending method to output the file

	// Output everyone's data into the file

	for (int& it : vPodium)
	{
		ofs << it << "," << this->m_Speakers[it].m_Score[1] << ",";
	}

	ofs << endl;

	// Close the file after outputting

	ofs.close();

	cout << "Records have been saved!" << endl;

}


// Search and check the past contest record

void SpeechManager::load_record()
{
	ifstream ifs("speech_records.csv", ios::in); // Input the file

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "File is not existing!" << endl;
		ifs.close();
		return;
	}

	// Case when the file is empty

	char ch;

	ifs >> ch;

	if (ifs.eof())
	{
		cout << "File is empty!" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}


	// Case when the file is NOT empty

	this->fileIsEmpty = false;

	ifs.putback(ch); // Put back the character which we inputted before

	string data;

	int edition = 1;

	while (ifs >> data)
	{

		vector<string> v; // container which stores the 6 strings (represent the result data)


		int pos = -1; // Variable for locating comma's position

		int start = 0;
		

		while (true)
		{
			pos = data.find(',', start);

			if (pos == -1)
			{
				// Did not find, exit the loop

				break;
			}

			// If found, obtain the substring (data as a "word")

			string temp = data.substr(start, pos - start);

			v.push_back(temp);

			// update the starting position

			start = pos + 1;
		}

		
		this->m_Record.insert(make_pair(edition, v));

		++edition;


	}

	ifs.close();

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