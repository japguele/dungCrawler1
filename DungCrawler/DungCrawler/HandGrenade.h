#include "Node.h"
#include "HardcodedNodeDungeon.h"
#include <map>
#include <random>

class HandGrenade {
public:
	HandGrenade();
	~HandGrenade();
	void Explosions(); //destroy edges in map
private:
	std::multimap<Node*, Node*>* GetMinimumSpanningTree(Node* startNode);
};