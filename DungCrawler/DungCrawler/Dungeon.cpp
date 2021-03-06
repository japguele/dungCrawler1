#include "stdafx.h"
#include "Dungeon.h"



Dungeon::Dungeon(int chambers) : cf(new ChamberFactory())
{
	this->chambers = chambers;
	//hero = new Hero("Jark");
	//startChamber = cf->CreateChambers(chambers);
	//hero->SetCurrentChamber(startChamber);
	//Save("heyo");
	//Load("heyo");

}

void Dungeon::CreateDungeon(){
	hero = new Hero("Jark");
	startChamber = cf->CreateChambers(chambers);
	hero->SetCurrentChamber(startChamber);

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

	cout << "loading file ...";
	std::stringstream ss;
	ss << loadFile.rdbuf();
	std::string  i;

	ss >> i;

	hero->SetCurrentChamber(cf->CreateDungFromString(i));
	

		
	
	cout << "done" << endl;

	loadFile.close();

}
void Dungeon::SavePlayer(std::string _name){
	
	if (hero){
		ofstream saveFile(_name + ".txt");
		saveFile << hero->SavePlayer();
	}
	
}
void Dungeon::LoadPlayer(std::string _name){
	ifstream loadFile;
	loadFile.open(_name + ".txt", ifstream::in);
	cout << "loading file ...";
	std::stringstream ss;
	ss << loadFile.rdbuf();
	std::vector<string> vect;
	string i;
	while (ss.good())
	{
		getline(ss, i, ',');
		vect.push_back(i);
	}
	if (hero){
		delete hero;
	}
	vector<Item*> backpack = vector<Item*>();
	int x = 6;
	while (vect.size() < x){
		if (vect[x] == "Potion"){
			backpack.push_back(new Potion(atoi(vect[x + 1].c_str()),vect[x+2],vect[x+3]));
		}
		else{
			backpack.push_back(new Weapon(vect[x + 1], vect[x + 2], vect[x + 3]));
		}
		
			x = x + 4;
	}
	hero = new Hero(vect[0], atoi(vect[1].c_str()), atoi(vect[2].c_str()), atoi(vect[3].c_str()), atoi(vect[4].c_str()), atoi(vect[5].c_str()), backpack);

	cout << "done" << endl;

	loadFile.close();
}




Dungeon::~Dungeon()
{
}
