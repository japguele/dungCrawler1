#pragma once
#include <string>
class Trap
{
private:
	std::string Description;
	int damageValue;
	bool alive;
public:
	Trap();
	void Init(int, std::string);
	void DisableTrap();
	int GetDamageValue();
	std::string GetDescription();
	virtual ~Trap();
};

