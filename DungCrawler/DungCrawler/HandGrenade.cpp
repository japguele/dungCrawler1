#include "HandGrenade.h"
using namespace std;

typedef std::multimap<Chamber*, Chamber*>::iterator mapIter;

HandGrenade::HandGrenade(std::string name, std::string description) {
	this->name = name;
	this->description = description;
}

HandGrenade::~HandGrenade() {
	//no pointers
}

void HandGrenade::UseItem(Hero* hero) {
	//get the minimum spanning tree
	//and try to destroy paths to chambers, if the chamber is in the minimum spanning tree, do not destroy the chamber

	//GetMinimumSpanningTree(hero->GetChamber());
	std::cout << "Using Grenade \n";
	if (MakeDirectionsInaccessible(GetMinimumSpanningTree(hero->GetChamber()), hero->GetChamber())) {
		std::cout << "You feel the walls shake \n";
		if (hero->GetChamber()->GetEnemy()) {
			hero->GetChamber()->DefeatEnemy();
			hero->GainExp(100);
		}
	}
}

std::map<pair<Chamber*, Direction>, Chamber*>* HandGrenade::GetMinimumSpanningTree(Chamber* startChamber) {

	std::map<pair<Chamber*, Direction>, Chamber*>* map = new std::map<pair<Chamber*, Direction>, Chamber*>();

	std::vector<Direction> directionVector = std::vector<Direction>();
	directionVector.push_back(Direction::North);
	directionVector.push_back(Direction::East);
	directionVector.push_back(Direction::South);
	directionVector.push_back(Direction::West);

	std::vector<Chamber*> visited = std::vector<Chamber*>();

	visited.push_back(startChamber);
	bool done = false;

	while (!done){
		Chamber* min = nullptr;;
		Chamber* from = nullptr;
		Direction tvec = Direction::Down;
		for each(Chamber* chan in visited)
			
			for each(Direction vec in directionVector){
			Chamber* temp = chan->GetChamberInDirection(vec);
				
			if (std::find(visited.begin(), visited.end(), temp) == visited.end()){
				if (temp){
					if (min){
						if (temp->GetWeight() < min->GetWeight()){
							min = temp;
							from = chan;
							tvec = vec;
						}
					}
					else{

						min = temp;
						from = chan;
						tvec = vec;
					}

				}
			}

		}

		if (min){
			visited.push_back(min);
			map->insert({ { from, tvec },min });
		}
		else{
			done = true;	
		}

	}
	return map;
}

bool HandGrenade::MakeDirectionsInaccessible(std::map<pair<Chamber*, Direction>, Chamber*>* minimumSpanningTree, Chamber* startChamber) {
	//---BREADTH FIRST SEARCH SETTING UP---//
	std::deque<Chamber*> queue = std::deque<Chamber*>();
	std::unordered_set<Chamber*> visited = std::unordered_set<Chamber*>();
	
	//setting up directionVector
	std::vector<Direction> directionVector = std::vector<Direction>();
	directionVector.push_back(Direction::North);
	directionVector.push_back(Direction::East);
	directionVector.push_back(Direction::South);
	directionVector.push_back(Direction::West);

	std::multimap<Chamber*, Chamber*>::iterator m_it, s_it;

	std::pair<Chamber*, Direction> chamberDirPair = std::pair<Chamber*, Direction>();

	queue.push_back(startChamber); //get current chamber and start finding the stairs

	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(10, 15); // define the range

	int range = distr(eng); // generate random number between range
	int amount = 0;

	std::map<Chamber*, Direction> removeChambers = std::map<Chamber*, Direction>();

	//keep looping until everything is dead
	while (!queue.empty()) {
		Chamber* chamber = queue.front(); //get first element
		visited.insert(chamber); //enqueue / push

		for (auto direction : directionVector) { //adjacent chambers
			if (chamber->GetChamberInDirection(direction)) { //check if exists
				if (std::find(visited.begin(), visited.end(), chamber->GetChamberInDirection(direction)) == visited.end() // check if in visited
						&& std::find(queue.begin(), queue.end(), chamber->GetChamberInDirection(direction)) == queue.end()) { // check if in queue
					
					chamberDirPair.first = chamber;
					chamberDirPair.second = direction;
					
					if (minimumSpanningTree->find(chamberDirPair) == minimumSpanningTree->end()) { //not in minimumSpanningTree
						removeChambers.insert(make_pair(chamber, direction));
						amount++;
					}

					queue.push_back(chamber->GetChamberInDirection(direction));
				}
			}
		}
		queue.pop_front(); //dequeue / pop
	}

	/*if (amount < range) {
		for (auto removeChamberPair : removeChambers) {
			removeChamberPair.first->SetInAccessibleDirection(removeChamberPair.second);
		}
		return true;
	}
	else {
		std::cout << "It's too dangerous to use the Hand Grenade" << std::endl;
		return false;
	}*/

	for (auto removeChamberPair : removeChambers) { //testing purposes
		removeChamberPair.first->SetInAccessibleDirection(removeChamberPair.second);
	}
	return true;
}