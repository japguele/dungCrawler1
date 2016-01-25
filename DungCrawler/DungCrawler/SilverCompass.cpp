#include "SilverCompass.h"

SilverCompass::SilverCompass(std::string name, std::string description) {
	this->name = name;
	this->description = description;
}

SilverCompass::~SilverCompass() {
	//no pointers
}

void SilverCompass::UseItem(Hero* hero) {
	

	//setting up directionVector
	std::vector<Direction> directionVector = std::vector<Direction>();
	directionVector.push_back(Direction::North);
	directionVector.push_back(Direction::East);
	directionVector.push_back(Direction::South);
	directionVector.push_back(Direction::West);

	for (auto direction : directionVector) {
		/*if (node->GetChamberInDirection(direction)) {

		}*/
	}
}