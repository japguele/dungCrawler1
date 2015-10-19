#pragma once
#include "MainView.h"
#include "Dungeon.h"
class MainController
{
public:
	MainController();
	~MainController();
	void CreateNewDung(int);
private:
	MainView* mv;
	Dungeon* dg;

};