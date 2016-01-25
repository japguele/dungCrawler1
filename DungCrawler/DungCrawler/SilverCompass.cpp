#include "SilverCompass.h"

SilverCompass::SilverCompass(std::string name, std::string description) {
	this->name = name;
	this->description = description;
}

SilverCompass::~SilverCompass() {
	//no pointers
}

void SilverCompass::UseItem(Hero* hero) {
	//---DIJKSTRA'S ALGORITHM SETTING UP---//
	std::deque<Chamber*> queue = std::deque<Chamber*>();
	std::unordered_set<Chamber*> visited = std::unordered_set<Chamber*>();
	std::unordered_map<Chamber*, Direction> previous = std::unordered_map<Chamber*, Direction>();


	//setting up directionVector
	std::vector<Direction> directionVector = std::vector<Direction>();
	directionVector.push_back(Direction::North);
	directionVector.push_back(Direction::East);
	directionVector.push_back(Direction::South);
	directionVector.push_back(Direction::West);

	queue.push_back(hero->GetChamber()); //get current chamber and start finding the stairs

	

	Chamber* stairsChamber = nullptr;
	//---DIJKSTRA'S FINISHED SETTING UP---//

	//start looping until finding the stairs
	while (!queue.empty()) {
		Chamber* currentChamber = queue.front(); //get first element
		visited.insert(currentChamber); //enqueue / push

		for (auto direction : directionVector) {
			if (currentChamber->GetChamberInDirection(direction)) {
				if (std::find(visited.begin(), visited.end(), currentChamber->GetChamberInDirection(direction)) == visited.end()
						&& std::find(queue.begin(), queue.end(), currentChamber->GetChamberInDirection(direction)) == queue.end()) {

					int newWeight = currentChamber->GetChamberInDirection(direction)->GetWeight();
					
					if (newWeight < currentChamber->GetChamberInDirection(direction)->dijkstraWeight) {
						currentChamber->GetChamberInDirection(direction)->dijkstraWeight = 
							currentChamber->dijkstraWeight + currentChamber->GetChamberInDirection(direction)->GetWeight();

						previous[currentChamber->GetChamberInDirection(direction)] = GetOppositeDirection(direction);
					}
					
					//when you can go Up or Down, that means you are in a "Stairs derived Chamber" = found our goal
					if (currentChamber->GetChamberInDirection(direction)->GetChamberInDirection(Direction::Up) || currentChamber->GetChamberInDirection(direction)->GetChamberInDirection(Direction::Down)) {
						//return the amount of steps
						stairsChamber = currentChamber->GetChamberInDirection(direction);
						//std::cout << "Amount of steps away from the stairs: " << distance[currentChamber->GetChamberInDirection(direction)] << std::endl;
						//return; //break hue
					}

					queue.push_back(currentChamber->GetChamberInDirection(direction));
				}
			}
		}
		queue.pop_front(); //dequeue / pop
	}

	std::vector<Direction> reverseDirectionList = std::vector<Direction>();
	std::vector<Direction> directionList = std::vector<Direction>();
	std::vector<int> enemyHPList = std::vector<int>();
	int amountTraps = 0;


	Chamber* currentChamber = nullptr;
	currentChamber = stairsChamber;

	if (stairsChamber) {
		while (currentChamber != hero->GetChamber()) {
			reverseDirectionList.push_back(previous.find(currentChamber)->second);
			currentChamber = currentChamber->GetChamberInDirection(previous.find(currentChamber)->second);
		}

		auto rit = reverseDirectionList.rbegin();

		for (int x = reverseDirectionList.size() - 1; x >= 0; x--){
			directionList.push_back(GetOppositeDirection(reverseDirectionList.at(x)));
		}
		
		//just in case
		currentChamber = hero->GetChamber();

		for (Direction direction : directionList) {
			//get all stats

			//get enemies
			if (currentChamber->GetEnemy()) {
				enemyHPList.push_back(currentChamber->GetEnemy()->GetHealth());
			}

			//get traps
			if (currentChamber->GetTrap()) {
				amountTraps++;
			}

			currentChamber = currentChamber->GetChamberInDirection(direction);
		}

		std::cout << std::endl;
		std::cout << "Directions: ";
		for (Direction direction : directionList) {
			if (direction == Direction::North) {
				std::cout << "North - ";
			}
			if (direction == Direction::East) {
				std::cout << "East - ";
			}
			if (direction == Direction::South) {
				std::cout << "South - ";
			}
			if (direction == Direction::West) {
				std::cout << "West - ";
			}
		}
		std::cout << std::endl;
		std::cout << "Enemies: ";
		for (auto hp : enemyHPList) {
			std::cout << "Enemy - " << hp << "HP - ";
		}
		std::cout << std::endl;

		std::cout << "Amount of traps: " << amountTraps << std::endl;
	}


	//delete all chamberWeights
}

Direction SilverCompass::GetOppositeDirection(Direction direction) {
	if (direction == Direction::North) {
		return Direction::South;
	}
	else if (direction == Direction::East) {
		return Direction::West;
	}
	else if (direction == Direction::South) {
		return Direction::North;
	}
	else if (direction == Direction::West) {
		return Direction::East;
	}
}