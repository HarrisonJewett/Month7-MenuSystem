#pragma once
#include "menuManager.h"

class doSomething
{
public:
	doSomething();
	~doSomething();

	menu newSubMenu;
	menuManager menuStack;	
	
	bool run;

	bool isNewMenu;
	int curSelection;
	int maxSelection;
	int numPossibleMenus;

	void start();
	void Update();
	void Render();

	void loadMenu(string file);


};
