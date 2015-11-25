
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

	chambertype[0] = "storage\x20room ";
	chambertype[1] = "torture\x20room ";
	chambertype[2] = "dinning\x20room ";
	chambertype[3] = "bathroom\x20";
	chambertype[4] = "hallway\x20";
	chambertype[5] = "kitchen\x20";
	chambertype[6] = "bedroom\x20";
	chambertype[7] = "tv\x20room\x20";
	chambertype[8] = "throne\x20room\x20";
	chambertype[9] = "wardrobe\x20room\x20";

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
		x = x - 1;
		break;
	case Direction::South:
		x = x + 1;
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

void ChamberFactory::LinkChamberFromString(string a){
	std::vector<string> vect;

	std::stringstream ss(a);

	string i;

	while (ss.good())
	{
		getline(ss, i, ',');
		vect.push_back(i);


	}

	int xpos = atoi(vect[1].c_str());
	int ypos = atoi(vect[2].c_str());
	int z = atoi(vect[3].c_str());
	bool n = (vect[4] == "1");
	bool e = (vect[5] == "1");
	bool s = (vect[6] == "1");
	bool w = (vect[7] == "1");
	if (n){
		ray->get(xpos, ypos, z)->SetChamberInDirection(ray->get(xpos - 1, ypos, z), Direction::North);
	}
	if (e){
		ray->get(xpos, ypos, z)->SetChamberInDirection(ray->get(xpos, ypos + 1, z), Direction::East);
	}
	if (s){
		ray->get(xpos, ypos, z)->SetChamberInDirection(ray->get(xpos + 1, ypos, z), Direction::South);
	}
	if (w){
		ray->get(xpos, ypos, z)->SetChamberInDirection(ray->get(xpos, ypos -1, z), Direction::West);
	}

}
void ChamberFactory::CreateChamberFromString(string a, vector<Level*> vec){
	


	std::vector<string> vect;

	std::stringstream ss(a);

	string i;

	while (ss.good())
	{
		getline(ss, i, ',');
		vect.push_back(i);

		
	}
	string type = vect[0];
	int xpos = atoi(vect[1].c_str());
	int ypos = atoi(vect[2].c_str());
	int z = atoi(vect[3].c_str());

//	bool n = vect[4];
//	bool e = vect[5];
//	bool s = vect[6];
//	bool w = vect[7];
	string disc = vect[8];
	Enemy* enemy = nullptr;
	if (vect.size() > 9){
		string enemylevel = vect[9];
		string health = vect[10];
		string offense = vect[11];
		string defence = vect[12];
		string discenemy = vect[13];
		enemy = new Enemy(atoi(enemylevel.c_str()), atoi(offense.c_str()), atoi(defence.c_str()), atoi(health.c_str()), discenemy);
	
	}
	if (type == "Chamber"){
		ray->put(new Chamber(vec[z], xpos, ypos, disc, enemy),xpos, ypos, z);

		}
	else 	if (type == "Stair"){
		ray->put(new Stair(vec[z], xpos, ypos, enemy), xpos, ypos, z);
	}
	else	if (type == "BossChamber"){
		ray->put(new BossChamber(vec[z], xpos, ypos, enemy),xpos, ypos, z);

		}
	


}
ChamberFactory::~ChamberFactory()
{
}
Chamber* ChamberFactory::CreateDungFromString(string a){
	int x = 4;
	int y = 4;
	int z = 0;
	string temp;

	for (std::string::iterator it = a.begin(); it != a.end(); ++it) {
		if (*it == '_') {
			*it = ' ';
		}
	}
	vector<Level*> vec = vector<Level*>();
	stringstream ss(a);
	bool first = true;
	while (getline(ss, temp, '|'))
	{
		if (first){
			vector<string> vecop = vector<string>();
			stringstream op(temp);
			while (op.good())
			{
				getline(op, temp, ',');
				vecop.push_back(temp);


			}

			ray = new Array3D(10, 10, atoi(vecop[0].c_str()));
			x = atoi(vecop[1].c_str());
			y = atoi(vecop[2].c_str());
			z = atoi(vecop[3].c_str());
			for (int counter = 0; counter < atoi(vecop[0].c_str()); counter++){
				vec.push_back(new Level(counter));
			}
			first = false;
		}
		else{
			CreateChamberFromString(temp, vec);
		}
	
	}
	first = true;
	stringstream sa(a);
	while (getline(sa, temp, '|'))
	{
		if (first){
			
			first = false;
		}
		else{
			LinkChamberFromString(temp);
		}

	}

	
	return ray->get(4,4,0);
}
