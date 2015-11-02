#include "stdafx.h"
#include "MainController.h"


MainController::MainController()
{
	mv = new MainView;
	CreateNewDung(1000);
	handler = InputHandler();
	Run();
}

void MainController::Run(){
	while (true){
		string inputString;
		cout << "Please tell me what to do\n";
		getline(cin, inputString);
		handler.Handle(inputString);
	}
	//Run();
}

void MainController::CreateNewDung(int chambers){
	dg = new Dungeon(chambers);
	
}

MainController::~MainController()
{

}
