#include <iostream>
#include "Map.h"
#include "Object.h"
#include <string>

int main()
{

	Map<std::string> map = Map<std::string>();

	map.Insert("lol");
	int _key = Object::hachage("lol");
	std::cout << _key << std::endl; 
	std::cout << map.At(_key);

	//ça marche ?! 
}

