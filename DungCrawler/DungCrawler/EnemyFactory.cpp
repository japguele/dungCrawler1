#include "stdafx.h"
#include "EnemyFactory.h"
#include "Enemy.h"

EnemyFactory::EnemyFactory()
{
	units = std::unordered_map<UnitType, Enemy>{
			{ UnitType::Enemy, Enemy() }
		
	};

	type[0] = "gnoll ";
	type[1] = "boar ";
	type[2] = "rat ";
	type[3] = "wolf ";
	type[4] = "turtle ";


	teeth[0] = "small ";
	teeth[1] = "big ";
	teeth[2] = "nice ";

	find[0] = "see's you ";
	find[1] = "smells you ";
	find[2] = "hears you ";

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
