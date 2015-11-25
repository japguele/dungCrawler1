#include "stdafx.h"
#include "EnemyFactory.h"
#include "Enemy.h"


EnemyFactory::EnemyFactory()
{

	ifstream loadFile;

	loadFile.open("Enemy.txt", ifstream::in);

	cout << "The file contained: ";
	std::stringstream ss;
	ss << loadFile.rdbuf();
	std::string  i;
	string temp = "";
	int x = 0;
	while (getline(ss, temp, '|'))
	{
		std::stringstream aa;
		aa << temp;
		string temp2 = "";
		while (getline(aa, temp2, ',')){
			if (x == 1){
				type.push_back(temp2);
			}
			else if (x == 2){
				teeth.push_back(temp2);
			}
			else if (x == 3){
				find.push_back(temp2);
			}
		}
		x++;
	}


	units = std::unordered_map<UnitType, Enemy>{
			{ UnitType::Enemy, Enemy() }
		
	};



}

Enemy* EnemyFactory::createEnemy(UnitType unit,Level* level){
	Enemy* en = units.at(unit).createEnemy();
	int typ = rand() % 5;
	en->Init(level->GetMonsterDif(), "a " + type[typ] + "appears , you see it has " + teeth[rand() % 3] + "teeth. the " + type[typ] + find[rand() % 3] );
	return en;
}



EnemyFactory::~EnemyFactory()
{
}
