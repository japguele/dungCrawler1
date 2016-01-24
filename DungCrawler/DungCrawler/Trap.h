#pragma once
#include <string>
class Trap
{
private:
	std::string Description;
	int damageValue;
	bool alive;
public:
	Trap(int _damageValue, bool _alive, std::string _Description);
	Trap();
	void Init(int, std::string);
	void DisableTrap();
	int GetDamageValue();
	std::string GetDescription();
	std::string Save();
	virtual ~Trap();
};

