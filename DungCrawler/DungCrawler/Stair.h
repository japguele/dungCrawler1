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
private:
	Chamber* up;
	Chamber* down;
};

