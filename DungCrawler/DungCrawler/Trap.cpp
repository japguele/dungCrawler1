#include "stdafx.h"
#include "Trap.h"


Trap::Trap()
{
}

Trap::Trap(int _damageValue, bool _alive, std::string _Description){
	damageValue = _damageValue;
	alive = _alive;
	Description = _Description;
}


void Trap::Init(int i, string disc){
	this->Description = disc;
	damageValue = 5 + (i * 4);
	alive = true;
}

void Trap::DisableTrap(){
	alive = false;
}

int Trap::GetDamageValue(){
	return damageValue;
}

std::string Trap::GetDescription(){
	return Description;
}

std::string Trap::Save(){
	
	std::string aliven = "0";
	if (alive){
		aliven = "1";
	}
	return ",Trap," + std::to_string(damageValue) + "," +aliven + "," + Description;
//	return "";
}
Trap::~Trap()
{
}
