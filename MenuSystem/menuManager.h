#pragma once
#include "stdIncludes.h"
#include "SLList.h"
#include "menu.h"


class menuManager
{
public:
	SLList<menuItem> activeMenus;

	menuManager();
	~menuManager();

	void removeHead()
	{
		SLLIter<menuItem> iter(activeMenus);
		iter.begin();
		activeMenus.remove(iter);
	}

	menuItem current()
	{
		SLLIter<menuItem> iter(activeMenus);
		iter.begin();
		return iter.current();
	}
};