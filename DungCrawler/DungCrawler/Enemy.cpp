#include "stdafx.h"
#include "Enemy.h"
#include <iostream>

Enemy::Enemy()
{

}
Enemy::Enemy(int _lvl, int _attack, int _defence, int _health, std::string _disc){
	cout << disc;
	disc = _disc;
	health = _health;
	level = _lvl;
	offense = _attack;
	defence = _defence;
}
Enemy* Enemy::createEnemy(){
	return new Enemy();
}
void Enemy::Init(int diff, std::string disc_){
	disc = disc_;
	health = 60 + (diff * 8);
	level = diff;
	offense = 10 + (diff * 2);
	defence = 5 + (diff * 2);
}
int Enemy::getAttack(){
	return offense;
}

string Enemy::GetDisc(){
	return disc;
}

bool Enemy::TakeDamage(int damage){
	int trueDamage = damage - defence;
	if (trueDamage <= 0){
		trueDamage = 0;
	}
	health -= trueDamage;
	if (health <= 0){
		cout << "The enemy took " << trueDamage << " damage and has been defeated.\n";
		return true;
	}
	cout << "The enemy took " << trueDamage << " damage and has " << health << " health left.\n";
	return false;
}
std::string Enemy::Save(){
	
	return ",Enemy,"+ std::to_string(level) + "," + std::to_string(health) + "," + std::to_string(offense) + "," + std::to_string(defence) + "," + disc;
	//return "";
}
Enemy::~Enemy()
{
}
