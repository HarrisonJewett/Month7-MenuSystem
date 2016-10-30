#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>
#include "DynArray.h"
#include "SLList.h"
#include <fstream>


using namespace std;

//Functions
void loadMenu(string file);

//Ending Functions

struct menuItem
{
	string name;
	bool is_subMenu;
	string subMenuPath;
};

class DTSTimer
{
	unsigned int startTime;
public:
	DTSTimer()
	{
		reset();
	}

	void reset()
	{
		startTime = clock();
	}

	unsigned int getElapsedTime()
	{
		return (clock() - startTime);
	}

	static void delay(const unsigned int milli)
	{
		unsigned int st = clock();
		while (clock() - st < milli) {}
	}

};

class menu
{
	string title;
	DynArray<menuItem> choices;
	unsigned int currSelection;


public:
	menu();
	~menu();
};

class menuManager
{
	SLList<menu> activeMenus;
};

int main(int argc, char ** argv)
{
	DTSTimer bob;
	string userInput;

	while(bob.getElapsedTime() < 15000)
	{

		//1 - get user input
		if(_kbhit())
		{
			char ch = _getch();

			if(-32 == ch)
				_getch();

			// did the user press a-z?
			else if(isalpha(ch))
			{
				userInput += tolower(ch);
			}
		}

		// 2 - act on it


		// 3 - draw the screen
		system("cls");
		cout << 15 - bob.getElapsedTime()/1000;
		cout << '\n' << userInput << '\n';
	}

	loadMenu("main.mnu");

	system("pause");
	return 0;
}

void loadMenu(string file)
{
	ifstream loading;

	loading.open(file);

	if (loading.is_open())
	{
		int numLines = 0;
		while (true)
		{
			string readLine;

			getline(loading, readLine);

			cout << readLine << '\n';

			if (loading.eof())
				break;
			numLines++;
		}
		loading.close();
	}
}