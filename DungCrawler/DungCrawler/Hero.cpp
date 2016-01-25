#include "stdafx.h"
#include "Hero.h"
#include "potion.h"
#include "Talisman.h"
#include "HandGrenade.h"
#include "SilverCompass.h"

Hero::Hero(){

}

Hero::Hero(string n, int _health, int _level, int _off, int _def, int _exp, vector<Item*> _backpack)
{
	fac = ItemFactory();
	name = n;
	health = _health;
	level = _level;
	offense = _off;
	defence = _def;
	experience = _exp;
	backpack = _backpack;
	
}
Hero::Hero(string n)
{
	fac = ItemFactory();
	name = n;
	health = 50;
	level = 1;
	offense = 50;
	defence = 10;
	experience = 0;
	backpack = vector<Item*>();
	Potion* pot = new Potion(30, "HealthPotion", "I drink this weird smelling potion");
	Potion* pot2 = new Potion(30, "HealthPotion", "I drink this weird smelling potion");
	backpack.push_back(pot);
	backpack.push_back(pot2);

	//added for algorithummmmss
	Talisman* talisman = new Talisman("talisman", "Find stairs");
	backpack.push_back(talisman);
	HandGrenade* handGrenade = new HandGrenade("handgrenade", "Destroy everything");
	backpack.push_back(handGrenade);
	SilverCompass* silverCompass = new SilverCompass("silvercompass", "Find best path");
	backpack.push_back(silverCompass);
}
void Hero::AddItem(Item* item){
	backpack.push_back(item);
	//backpack.insert({ item->name, item });
}

vector<Item*> Hero::GetBackpack(){
	return backpack;
}

void Hero::LevelUp(){
	level++;
	health += 20;
	offense += 10;
	defence += 5;
	experience = 0;
}

void Hero::GainExp(int exp){
	cout << "I gained " << exp << " experience!" << endl;
	experience += exp;
	if (experience >= (level*100)){
		cout << "Congratiolations, you leveled up!\n";
		int tempExp = experience - (level * 100);
		LevelUp();
		GainExp(tempExp);
	}
	cout << "Your new experience is: " << experience << ".\n";
}

void Hero::GainOffence(int val){
	cout << "I gained " << val << " offence.\n";
	offense += val;
	cout << "Your new offence is: " << offense << ".\n";
}

void Hero::GainDefence(int val){
	cout << "I gained " << val << " defence.\n";
	defence += val;
	cout << "Your new defence is: " << defence << ".\n";
}

void Hero::DrinkPotion(int pot){
	cout << "Drinking this potion heals me: " << pot << ".\n";
	health += pot;
	cout << "My Health now is: " << health << ".\n";
}

void Hero::SetCurrentChamber(Chamber* chamber){
	previousChamber = currentChamber;
	currentChamber = chamber;
	currentChamber->SetVisited();
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
		int baseExp = rand() % 20+40;
		int bonusExp = currentChamber->GetEnemy()->GetLevel() * 5;
		currentChamber->DefeatEnemy();
		GainExp(baseExp+bonusExp);
		Item* item = fac.CreateItem();
		if (item != nullptr){
			cout << "This monster dropped a: " << item->GetName() << endl;
			AddItem(item);
		}
	}
	else {
		if (!TakeDamage(currentChamber->GetEnemy()->getAttack())){
			//exit game
			exit(0);
		}
	}
}

void Hero::Magic(){
	int ownDamage = rand() % 10 + 1;
	health = health - ownDamage;
	if (health <= 0){
		exit(0);
	}
	cout << "By using magic, I took " << ownDamage << " damage and have " << health << " health left.\n";
	if (currentChamber->AttackEnemy(offense+(offense/2))){
		int baseExp = rand() % 20 + 40;
		int bonusExp = currentChamber->GetEnemy()->GetLevel() * 5;
		currentChamber->DefeatEnemy();
		GainExp(baseExp + bonusExp);
	}
	else {
		if (!TakeDamage(currentChamber->GetEnemy()->getAttack())){
			//exit game
			exit(0);
		}
	}
}
void Hero::RunAway(){
	if (previousChamber != nullptr){
		TakeDamage(currentChamber->GetEnemy()->getAttack());
		currentChamber = previousChamber;
		cout << "I fled to the previous chamber." << endl;
	}
	else {
		cout << "I can escape in this room." << endl;
	}
}

string Hero::SavePlayer(){
	string save = name + "," + std::to_string(health) + "," + std::to_string(level) + "," + std::to_string(offense) + "," + std::to_string(defence) + "," + std::to_string(experience);
	for (auto kv : backpack) {
		save = save + "," + kv->Save();
	}

	return save;
}

Hero::~Hero()
{
}
