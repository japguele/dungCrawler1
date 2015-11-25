#include "stdafx.h"
#include "Trap.h"


Trap::Trap()
{
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


Trap::~Trap()
{
}
