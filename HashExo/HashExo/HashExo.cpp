#include <iostream>
#include "Map.h"
#include "Object.h"
#include <string>

int main()
{

	Map<std::string> map = Map<std::string>();
	std::string value = "coucou";


	map.Insert(value);
	int _key = Object::hachage(value);
	std::cout << _key << std::endl; 
	std::cout << map.At(_key);

	
}

