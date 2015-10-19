#include "stdafx.h"
#include "MainController.h"


MainController::MainController()
{
	mv = new MainView;
}
void MainController::CreateNewDung(int chambers){
	dg = new Dungeon(chambers);
}

MainController::~MainController()
{
}
