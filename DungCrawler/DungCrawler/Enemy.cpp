#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{

}
Enemy* Enemy::createEnemy(){
	return new Enemy();
}
void Enemy::Init(int diff ,string disc_){
	disc = disc_;
	health = 30 + (diff * 8);
	level = diff;
	offense = 3 + (diff * 1.5);
	defence = 1 + (diff * 1.5);
}
int Enemy::getAttack(){
	return offense;
}

Enemy::~Enemy()
{
}
