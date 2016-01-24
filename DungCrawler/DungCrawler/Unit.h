#pragma once
class Unit
{
public:
	Unit();
	virtual ~Unit();
	int GetLevel();
	int GetHealth();
	int GetOffense();
	int GetDefense();
	virtual bool TakeDamage(int);
protected:
	int health;
	int level;
	int offense;
	int defence;
};


