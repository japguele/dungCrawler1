#include "stdafx.h"
#include "Dungeon.h"
#include <iostream>
#include <fstream>


Dungeon::Dungeon(int chambers) : cf(new ChamberFactory())
{
	hero = new Hero("Jark");
	startChamber = cf->CreateChambers(chambers);
	//hero->SetCurrentChamber(startChamber);
	int x = 0;
	int y = 0;
	//Save("heyo");
	Load("heyo");
}

Hero* Dungeon::GetHero(){
	return hero;
}

ChamberFactory* Dungeon::GetChamberFactory(){
	return cf;
}
void Dungeon::Save(std::string _name){
	ofstream saveFile(_name + ".txt");
	saveFile << cf->GetArray3D()->get_z_size() << "," << hero->GetChamber()->GetXpos() << "," << hero->GetChamber()->GetYpos() << "," << hero->GetChamber()->GetLevel()->GetDepth();
		for (int x = 0; x < cf->GetArray3D()->get_x_size(); x++){
			for (int y = 0; y < cf->GetArray3D()->get_y_size(); y++){
				for (int z = 0; z < cf->GetArray3D()->get_z_size(); z++){
					Chamber*  cham = cf->GetArray3D()->get(x, y, z);
					if (cham){
						saveFile << cham->Save(x, y, z) ;
					}
				}
			}
		}
		saveFile.close();
}
void Dungeon::Load(std::string _name){
	
	ifstream loadFile;

	loadFile.open(_name + ".txt", ifstream::in);

	cout << "The file contained: ";
	std::stringstream ss;
	ss << loadFile.rdbuf();
	std::string  i;

	ss >> i;

	hero->SetCurrentChamber(cf->CreateDungFromString(i));
	

		
	
	cout << "" << endl;

	loadFile.close();

}





Dungeon::~Dungeon()
{
}
