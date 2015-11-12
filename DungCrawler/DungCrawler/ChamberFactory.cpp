
#include "ChamberFactory.h"

ChamberFactory::ChamberFactory()
{
	fac = EnemyFactory();
	counter = 0;
	light[0] = "dark ";
	light[1] = "bright ";
	light[2] = "";

	size[0] = "small ";
	size[1] = "big ";
	size[2] = "";

	chambertype[0] = "storage room ";
	chambertype[1] = "torture room ";
	chambertype[2] = "dinning room ";
	chambertype[3] = "bathroom ";
	chambertype[4] = "hallway ";
	chambertype[5] = "kitchen ";
	chambertype[6] = "bedroom ";
	chambertype[7] = "tv room ";
	chambertype[8] = "throne room ";
	chambertype[9] = "wardrobe room ";

	objects[0] = "a few chairs ";
	objects[1] = "some broken glass ";
	objects[2] = "a broken painting ";
	objects[3] = "a fresh corpse ";
	objects[4] = "a table lying on its side ";
	objects[5] = "a few boxes stacked ";
	objects[6] = "some dried up blood ";
	objects[7] = "allot of brokenplanks ";
	objects[8] = "some chaines ";
	objects[9] = "some old rotten fruit ";

	objectsloc[0] = "on the floor";
	objectsloc[1] = "against the wall";
	objectsloc[2] = "in the corner";
	time_t t = time(0);   // get time now
	srand(t);
}

Array3D* ChamberFactory::GetArray3D(){
	return ray;
}


Chamber* ChamberFactory::CreateChambers(int ammount){

	int levels = ammount / 100;

	int v2 = rand() % 5;
	v2 = v2 + levels;
	ray = new Array3D(10, 10, v2);

	std::vector<Level*> level(v2);
	// std::vector<Stair*> stairs(v2);    // make room for 10 integers,
	// and initialize them to 0
	// do something with them:
	for (int i = 0; i < v2; i++){
		//create levels plus stairs
		level[i] = new Level(i);
		Chamber* chamber = nullptr;
		Enemy* en = nullptr;
		if (rand() % 3 > 1){
			en = fac.createEnemy(UnitType::Enemy, level[i]);
		}
		chamber = new Stair(level[i], 4, 4, en);
		ray->put(chamber, 4, 4, chamber->GetLevel()->GetDepth());
		RandomChambersArround(chamber, 4, 4, 4, 4);

	}




	for (int i = 0; i + 1 < v2; ++i){
		//connect stairs
		if (i != 0){
			ray->get(4, 4, i)->SetChamberInDirection(ray->get(4, 4, i - 1), Direction::Down);
		}
		if (i + 1 < v2){
			ray->get(4, 4, i)->SetChamberInDirection(ray->get(4, 4, i + 1), Direction::Up);
		}

	}

	if (ray->get(4, 5, 0)){
		return ray->get(4, 5, 0);
	}
	else if (ray->get(6, 5, 0)){
		return ray->get(6, 5, 0);
	}
	else if (ray->get(5, 4, 0)){
		return ray->get(5, 4, 0);
	}
	else if (ray->get(5, 6, 0)){
		return ray->get(5, 6, 0);
	}
	else{
		return ray->get(5, 5, 0);
	}

}




void ChamberFactory::RandomChambersArround(Chamber* cham, int north, int south, int west, int east)
{

	if (north > 0){
		Chamber* c = nullptr;
		c = RandomChamberDirection(cham, Direction::North);
		if (c != nullptr){
			RandomChambersArround(c, north - 1, south, west, east);
		}

	}
	if (south > 0){
		Chamber* c = nullptr;
		c = RandomChamberDirection(cham, Direction::South);
		if (c != nullptr){
			RandomChambersArround(c, north, south - 1, west, east);
		}


	}
	if (east > 0){
		Chamber* c = nullptr;
		c = RandomChamberDirection(cham, Direction::East);
		if (c != nullptr){
			RandomChambersArround(c, north, south, west, east - 1);
		}

	}
	if (west > 0){

		Chamber* c = nullptr;
		c = RandomChamberDirection(cham, Direction::West);
		if (c != nullptr){
			RandomChambersArround(c, north, south, west - 1, east);
		}

	}
}
Chamber* ChamberFactory::RandomChamberDirection(Chamber* cham, Direction d){
	int x = cham->GetXpos();
	int y = cham->GetYpos();
	int z = cham->GetLevel()->GetDepth();
	switch (d)
	{
	case Direction::North:
		x = x + 1;
		break;
	case Direction::South:
		x = x - 1;
		break;
	case Direction::West:
		y = y - 1;
		break;
	case Direction::East:
		y = y + 1;
		break;

	}
	Chamber* c = nullptr;
	if (ray->get(x, y, z) == nullptr || ray->get(x, y, z) == NULL){
		if (rand() % 5 > 1){
			c = CreateChamber(cham->GetLevel(), x, y);
			cham->SetChamberInDirection(c, d);
		}
	}
	else if (rand() % 4 > 1){
		cham->SetChamberInDirection(ray->get(x, y, z), d);

	}
	return c;
}

Chamber* ChamberFactory::CreateChamber(Level* l, int xpos, int ypos){
	Chamber* c = nullptr;
	if (l->GetDepth() > 5 && rand() % 30 == 1 ){
		Enemy* en = fac.createEnemy(UnitType::Enemy, l);
		c = new BossChamber(l, xpos, ypos, en);
		

	}
	string discription = "You enter a " + size[rand() % 3] + light[rand() % 3] + chambertype[rand() % 10] + "in the room you see " + objects[rand() % 10];
	counter = counter + 1;
	//cout << counter;
	Enemy* en = nullptr;
	if (rand() % 3 > 1){
		en = fac.createEnemy(UnitType::Enemy, l);
	}
	c = new Chamber(l, xpos, ypos, discription, en);
	
	ray->put(c, xpos, ypos, l->GetDepth());
	return c;


}

ChamberFactory::~ChamberFactory()
{
}
