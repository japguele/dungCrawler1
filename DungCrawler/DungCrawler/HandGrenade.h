#include "Node.h"
#include <unordered_map>

class HandGrenade {
public:
	HandGrenade();
	~HandGrenade();
	void Explosions(); //destroy edges in map
private:
	std::unordered_map<Node*, Node*> GetMinimumSpanningTree();

};