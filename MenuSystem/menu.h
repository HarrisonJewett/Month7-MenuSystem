#pragma once
#include "stdIncludes.h"
#include "DynArray.h"

struct menuItem
{
	string name;
	bool is_subMenu;
	string subMenuPath;
};

class menu
{
public:
	string title;
	DynArray<menuItem> choices;
	unsigned int currSelection;

	menu();
	~menu();

	void addMenuItem(string _name, bool _subMenu, string _path)
	{
		menuItem newMenu;
		newMenu.name = _name;
		newMenu.is_subMenu = true;
		newMenu.subMenuPath = _path;

		choices.append(newMenu);
	}

	void addOption(string _name, bool _subMenu)
	{
		menuItem newOption;

		newOption.name = _name;
		newOption.is_subMenu = false;
		newOption.subMenuPath = "";

		choices.append(newOption);
	}

	unsigned int getCurrentSelection() { return currSelection; }
};

