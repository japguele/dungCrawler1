#include "stdafx.h"
#include "Hero.h"


Hero::Hero(string n)
{
	name = n;
	health = 100;
	level = 1;
	offense = 50;
	defence = 10;
	experience = 0;
	backpack = unordered_map<string, Item*>();
}
void Hero::AddItem(Item* item){
	backpack.insert({ item->name, item });
}

void Hero::LevelUp(){
	level++;
	health += 20;
	offense += 10;
	defence += 10;
	experience = 0;
}

void Hero::GainExp(int exp){
	experience += exp;
	if (experience >= 100){
		cout << "Congratiolations, you leveled up!\n";
		int tempExp = experience - 100;
		LevelUp();
		GainExp(tempExp);
	}
	cout << "Your new experience is: " << experience << ".\n";
}

void Hero::DrinkPotion(int pot){
	cout << "Drinking this potion heals me: " << pot << ".\n";
	health += pot;
	cout << "My Health now is: " << health << ".\n";
}

Hero::~Hero()
{
}
