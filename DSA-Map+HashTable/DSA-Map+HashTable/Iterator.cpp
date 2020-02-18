#include "Iterator.h"
#include <string>
#include "Map.h"
#include <assert.h>
#include<vector>

std::pair<int, int>& Iterator::getCurrent()
{
	//std::pair<int, int> p = make_pair(-1, -1);
	return this->map->pair[this->currentPos];
}

bool Iterator::isValid()
{
	if (currentPos != -1 && currentPos<=map->getHashSize())
		return true;
	return false;
}

void Iterator::next()
{
	std::pair<int, int> p = std::make_pair(-1, -1);
	//this->currentPos++;
	this->currentPos--;
	
	while (this->map->pair[currentPos].first == p.first && this->map->pair[currentPos].second == p.second)
		this->currentPos--;
	std::pair<int,int> currentPair = this->getCurrent();
}
