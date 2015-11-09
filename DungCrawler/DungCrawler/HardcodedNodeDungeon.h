#pragma once
#include "Node.h"

class HardCodedNodeDungeon {
public:
	HardCodedNodeDungeon();
	~HardCodedNodeDungeon();
	static std::pair<Node*, Node*> StartAndEndNode();
};