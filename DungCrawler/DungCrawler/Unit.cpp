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

bool Unit::TakeDamage(int damage){
	int trueDamage = damage - defence;
	if (trueDamage <= 0){
		trueDamage = 1;
	}
	health -= trueDamage;
	if (health <= 0){
		cout << "I have been beaten. Goodbye cruel world." << endl;
		return false;
	}
	cout << "auch, I took " << trueDamage << " damage and have " << health << " health left.\n";
	return true;
}


Unit::~Unit()
{
}
