#pragma once
#pragma message ("enemy")
#include "Unit.h"
#include <string>


class Enemy :
	public Unit
{
public:
	Enemy();
	Enemy(int _lvl, int _attack,int _defence,int _health,std::string _disc);
	virtual ~Enemy();
	std::string disc;
	virtual Enemy* createEnemy();
	int getAttack();
	void Init(int, std::string);
	std::string GetDisc();
	bool TakeDamage(int);
	std::string Save();
};


