#include "doSomething.h"

#define CURSOR_ADD 2

doSomething::doSomething(){}
doSomething::~doSomething(){}

void doSomething::start()
{
	run = true;
	maxSelection = 0;
	numPossibleMenus = 0;
	loadMenu("main.mnu");
	curSelection = 0;
	while (run)
	{
		Update();
		Render();
	}
}

void doSomething::Update()
{
	if (GetAsyncKeyState(VK_UP))
	{
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD position = { 0, (int)(CURSOR_ADD + curSelection) };
		SetConsoleCursorPosition(output, position);
		cout << ' ';
		if (curSelection == 0)
			curSelection = maxSelection;
		else
			curSelection--;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD position = { 0, (int)(CURSOR_ADD + curSelection) };
		SetConsoleCursorPosition(output, position);
		cout << ' ';
		if (curSelection == maxSelection)
			curSelection = 0;
		else
			curSelection++;
	}
	if (GetAsyncKeyState(VK_RETURN))
	{
		if (curSelection <= numPossibleMenus)
		{
			system("cls");
			loadMenu(newSubMenu.choices[curSelection].subMenuPath);
			menuStack.activeMenus.addHead(newSubMenu.choices[curSelection]);
		}
	}
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		if (newSubMenu.choices.size() > 1)
		{
			//menuStack.activeMenus.deleteHead();
			//menuStack.activeMenus.remove(menuStack.thisisathing());
			//loadMenu(menuStack.activeMenus);
		}
		else
		{
			run = false;
			return;
		}
	}
}

void doSomething::Render()
{

	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { 0, (int)(CURSOR_ADD + curSelection) };
	SetConsoleCursorPosition(output, position);
	cout << '>';
	Sleep(120);
}

void doSomething::loadMenu(string file)
{
	ifstream loading;

	loading.open(file);

	if (loading.is_open())
	{
		string name;
		string readLine;
		string subMenu;
		string size;
		int i = 0;

		getline(loading, name);
		cout << name << '\n';
		getline(loading, size);
		cout << "---------------------------" << '\n';

		int lines = stoi(size);
		maxSelection = lines - 1;

		while (i < lines)
		{
			loading >> readLine;
			if (readLine == "MENU")
			{
				numPossibleMenus++;
				loading.ignore(INT_MAX, '"');
				getline(loading, readLine, '"');
				loading.ignore(INT_MAX, '"');
				getline(loading, subMenu, '"');
				newSubMenu.addMenuItem(readLine, true, subMenu);
			}
			else
			{
				loading.ignore(INT_MAX, '"');
				getline(loading, readLine, '"');
				newSubMenu.addOption(readLine, false);
			}
			
			cout << "  " << readLine << '\n';
			

			if (loading.eof())
				break;
			i++;
		}
		loading.close();
	}
}