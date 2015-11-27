#include "stdafx.h"
#include "ItemFactory.h"


ItemFactory::ItemFactory()
{
	potionSize[0] = 25;
	potionSize[1] = 50;
	potionSize[2] = 75;

	potionName[0] = "HealthPotion";
	potionName[1] = "ExperiencePotion";
	potionName[2] = "OffencePotion";
	potionName[3] = "DefencePotion";

	potionDescription[0] = "I drink this weird smelling potion.";
	potionDescription[1] = "Hmmm, This potion tastes delicious.";
	potionDescription[2] = "This tasts like shit.";
}

Item* ItemFactory::CreateItem(){
	int chance = rand()% 5+1;
	int potionChance = rand() % 3 + 1;
	if (chance != 5){
		if (potionChance != 3){
			cout << "potion!!!";
			return CreatePotion();
		}
		else{
			return CreateUselessItem();
		}
	}
	else {
		return nullptr;
	}
}

Item* ItemFactory::CreatePotion(){
	int type = rand() % 4;
	if (type == 2){
		Item* item = new Potion(potionSize[((rand()%3 )/10)+1],potionName[type], potionDescription[rand()%3]);
		return item;
		//offence
	}
	else if (type = 3){
		Item* item = new Potion((potionSize[rand() % 3]/20)+1, potionName[type], potionDescription[rand() % 3]);
		return item;
		//defence
	}
	else {
		Item* item = new Potion(potionSize[(rand() % 3)], potionName[type], potionDescription[rand() % 3]);
		return item;
		//health/exp
	}
}

Item* ItemFactory::CreateUselessItem(){
	cout << "useless item";
	return nullptr;
}

ItemFactory::~ItemFactory()
{
}
