#include "stdafx.h"
#include "Potion.h"
#include "hero.h"

enum potions{ HealthPotion, ExperiencePotion, OffencePotion, DefencePotion};

Potion::Potion(int val,std::string nam, std::string desc)
{
	this->value = val;
	this->name = nam;
	this->description = desc;
}

potions hashit(string const& inString) {
	if (inString == "HealthPotion") return HealthPotion;
	if (inString == "ExperiencePotion") return ExperiencePotion;
	if (inString == "OffencePotion") return OffencePotion;
	if (inString == "DefencePotion") return DefencePotion;
}


void Potion::UseItem(Hero* hero){
	cout << "I used the following item: " << name << endl;
	cout << description;

	switch (hashit(name)){
	case HealthPotion:
		hero->DrinkPotion(value);
		break;
	case ExperiencePotion:
		hero->GainExp(value);
		break;
	case OffencePotion:
		hero->GainOffence(value);
		break;
	case DefencePotion:
		hero->GainDefence(value);
		break;
	}
}

Potion::~Potion()
{
}
