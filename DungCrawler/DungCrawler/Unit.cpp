#include "stdafx.h"
#include "Unit.h"
#include <iostream>

Unit::Unit()
{
}

int Unit::GetLevel(){
	return level;
}

int Unit::GetHealth(){
	return health;
}

int Unit::GetOffense(){
	return offense;
}

int Unit::GetDefense(){
	return defence;
}

void Unit::TakeDamage(int damage){
	health -= damage;
	if (health <= 0){
		//gameover!!!
	}
	cout << "auch, I took " << damage << " damage and have " << health << " health left.\n";
}


Unit::~Unit()
{
}
