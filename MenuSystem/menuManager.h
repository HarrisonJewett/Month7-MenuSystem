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
};