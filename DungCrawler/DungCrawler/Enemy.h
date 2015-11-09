#pragma once
#pragma message ("enemy")
#include "Unit.h"
#include <string>


class Enemy :
	public Unit
{
public:
	Enemy();
	virtual ~Enemy();
	string disc;
	virtual Enemy* createEnemy();
	int getAttack();
	void Init(int,string);
};


