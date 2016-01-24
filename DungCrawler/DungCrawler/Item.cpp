#include "stdafx.h"
#include "Item.h"


Item::Item()
{
}

void Item::UseItem(Hero* her){

}

string Item::GetName(){
	return name;
}
string Item::GetDescription(){
	return description;
}


Item::~Item()
{
}
std::string Item::Save(){
	return "";
}
