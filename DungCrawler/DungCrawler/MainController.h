#pragma once
#include "MainView.h"
#include "Dungeon.h"
#include <iostream>
#include <string>
#include "InputHandler.h"

class MainController
{
public:
	MainController();
	~MainController();
	void CreateNewDung(int);
	void Run();
private:
	MainView* mv;
	Dungeon* dg;
	InputHandler handler;
};