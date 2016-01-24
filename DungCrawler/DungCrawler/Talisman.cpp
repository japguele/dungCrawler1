#include "Talisman.h"

Talisman::Talisman(std::string name, std::string description) {
	this->name = name;
	this->description = description;
}

Talisman::~Talisman() {
	//no pointers
}

//breadth first search, display amount of steps needed to find stairs
void Talisman::UseItem(Hero* hero) {
	//---BREADTH FIRST SEARCH SETTING UP---//
	std::deque<Chamber*> queue = std::deque<Chamber*>();
	std::unordered_set<Chamber*> visited = std::unordered_set<Chamber*>();
	std::unordered_map<Chamber*, int> distance = std::unordered_map<Chamber*, int>();

	//setting up directionVector
	std::vector<Direction> directionVector = std::vector<Direction>();
	directionVector.push_back(Direction::North);
	directionVector.push_back(Direction::East);
	directionVector.push_back(Direction::South);
	directionVector.push_back(Direction::West);

	queue.push_back(hero->GetChamber()); //get current chamber and start finding the stairs
	distance[hero->GetChamber()] = 0; //set current distance to zero
	//---BREADTH FIRST SEARCH FINISHED SETTING UP---//
	
	Chamber* checkFirstNode = queue.front();
	if (checkFirstNode->GetChamberInDirection(Direction::Up) || checkFirstNode->GetChamberInDirection(Direction::Down)) { //catch zero distance
		//return the amount of steps
		std::cout << "Amount of steps away from the stairs: 0" << std::endl;
		return; //break hue
	}



	//start looping until finding the stairs
	while (!queue.empty()) {
		Chamber* node = queue.front(); //get first element
		visited.insert(node); //enqueue / push

		for (auto direction : directionVector) {
			if (node->GetChamberInDirection(direction)) {
				if (std::find(visited.begin(), visited.end(), node->GetChamberInDirection(direction)) == visited.end()
					&& std::find(queue.begin(), queue.end(), node->GetChamberInDirection(direction)) == queue.end()) {

					distance[node->GetChamberInDirection(direction)] = distance[node] + 1;
					
					//when you can go Up or Down, that means you are in a "Stairs derived Chamber" = found our goal
					if (node->GetChamberInDirection(direction)->GetChamberInDirection(Direction::Up) || node->GetChamberInDirection(direction)->GetChamberInDirection(Direction::Down)) {
						//return the amount of steps
						std::cout << "Amount of steps away from the stairs: " << distance[node->GetChamberInDirection(direction)] << std::endl;
						return; //break hue
					}

					queue.push_back(node->GetChamberInDirection(direction));
				}
			}
		}
		queue.pop_front(); //dequeue / pop
	}

	//not found, catch -1
	std::cout << "Not found the stairs, errrrr... Oops?" << std::endl;
}