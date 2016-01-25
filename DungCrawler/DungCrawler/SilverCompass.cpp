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
	std::unordered_map<Chamber*, ChamberWeight*> weight = std::unordered_map<Chamber*, ChamberWeight*>();

	//setting up directionVector
	std::vector<Direction> directionVector = std::vector<Direction>();
	directionVector.push_back(Direction::North);
	directionVector.push_back(Direction::East);
	directionVector.push_back(Direction::South);
	directionVector.push_back(Direction::West);

	queue.push_back(hero->GetChamber()); //get current chamber and start finding the stairs

	std::vector<Direction> directionList = std::vector<Direction>();
	std::vector<int> enemyHPList = std::vector<int>();
	weight[hero->GetChamber()] = new ChamberWeight(0, directionList, enemyHPList, 0); //set current distance to zero

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
					
					if (weight.find(currentChamber) == weight.end() 
						|| newWeight < weight.find(currentChamber)->second->weight) {
						directionList = weight.find(currentChamber)->second->directionList;
						directionList.push_back(direction);
						enemyHPList = weight.find(currentChamber)->second->enemyHPList;
						enemyHPList.push_back(currentChamber->GetChamberInDirection(direction)->GetEnemy()->GetHealth());
						
						int amountTraps = weight.find(currentChamber)->second->amountTraps;
						if (currentChamber->GetChamberInDirection(direction)->GetTrap()) {
							amountTraps++;
						}

						weight[currentChamber] = new ChamberWeight(newWeight, directionList, enemyHPList, amountTraps);
					}
					
					

					//when you can go Up or Down, that means you are in a "Stairs derived Chamber" = found our goal
					if (currentChamber->GetChamberInDirection(direction)->GetChamberInDirection(Direction::Up) || currentChamber->GetChamberInDirection(direction)->GetChamberInDirection(Direction::Down)) {
						//return the amount of steps
						stairsChamber = currentChamber->GetChamberInDirection(direction);
						//std::cout << "Amount of steps away from the stairs: " << distance[currentChamber->GetChamberInDirection(direction)] << std::endl;
						//return; //break hue
					}

					queue.push_back(currentChamber->GetChamberInDirection(direction));

					directionList.clear();
					enemyHPList.clear();
				}
			}
		}
		queue.pop_front(); //dequeue / pop

		directionList.clear();
		enemyHPList.clear();
	}

	if (stairsChamber) {
		ChamberWeight* stairsWeight = weight.find(stairsChamber)->second;
		for (auto dir : stairsWeight->directionList) {
			std::cout << "[direction]";
		}
	}


	//delete all chamberWeights
}