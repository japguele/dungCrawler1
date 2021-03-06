#pragma once


class Chamber;

class Stair :
	public Chamber
{
public:

	~Stair();
	Stair(Level* lvl, int x, int y,Enemy* en);
	virtual void SetChamberInDirection(Chamber*, Direction);
	virtual Chamber* GetChamberInDirection(Direction);
	virtual std::string GetMapIconCheatmode();
	std::string GetMapIcon();
	virtual std::string Save(int x, int y, int z);
private:
	Chamber* up;
	Chamber* down;
};

