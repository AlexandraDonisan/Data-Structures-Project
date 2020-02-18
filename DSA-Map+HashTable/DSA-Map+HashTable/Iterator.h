#pragma once
#include <string>

class Map;

class Iterator
{
	Map *map;
	int currentPos;

public:
	Iterator(Map* m) : map{ m } { this->currentPos = 20; }
	~Iterator() {}

	std::pair<int,int> &getCurrent();
	bool isValid();
	void next();
};
