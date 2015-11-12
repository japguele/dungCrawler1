#include "stdafx.h"
#include "Hero.h"

Hero::Hero(){

}

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

void Hero::SetCurrentChamber(Chamber* chamber){
	currentChamber = chamber;
	cout << currentChamber->getDescription() << endl;
}

int Hero::GetExperience(){
	return experience;
}

Chamber* Hero::GetChamber(){
	return currentChamber;
}

void Hero::Attack(){
	if (currentChamber->AttackEnemy(offense)){
		GainExp(50);
	}
	else {
		if (!TakeDamage(currentChamber->GetEnemy()->getAttack())){
			//exit game
		}
	}
}

void Hero::Magic(){
	int ownDamage = rand() % 10 + 1;
	if (!TakeDamage(ownDamage)){
		//killed yourself
	}
	if (currentChamber->AttackEnemy(offense)){
		GainExp(50);
	}
	else {
		if (!TakeDamage(currentChamber->GetEnemy()->getAttack())){
			//exit game
		}
	}
}
void Hero::RunAway(){

}

Hero::~Hero()
{
}
