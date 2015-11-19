#include "stdafx.h"
#include "Enemy.h"
#include <iostream>

Enemy::Enemy()
{

}
Enemy::Enemy(int _lvl, int _attack, int _defence, int _health, std::string _disc){
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
	health = 30 + (diff * 8);
	level = diff;
	offense = 3 + (diff * 1.5);
	defence = 1 + (diff * 1.5);
}
int Enemy::getAttack(){
	return offense;
}

string Enemy::GetDisc(){
	return disc;
}

bool Enemy::TakeDamage(int damage){
	health -= damage;
	if (health <= 0){
		cout << "I defeated this enemy, I received 50 experience." << endl;
		return true;
	}
	cout << "The enemy took " << damage << " damage and has " << health << " health left.\n";
	return false;
}
std::string Enemy::Save(){
	return "," + std::to_string(level) + "," + std::to_string(health) + "," + std::to_string(offense) + "," + std::to_string(defence) + "," + disc;
}
Enemy::~Enemy()
{
}
