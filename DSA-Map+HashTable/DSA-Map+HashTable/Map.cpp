#include "Map.h"
#include <vector>
#include<string>
#include <assert.h>

using namespace std;


Map::Map()
{
	for (int i = 0; i < this->hashSize; i++)
	{
		this->pair[i] = make_pair(-1,-1);
		this->next[i] = -1;
	}
	this->firstFree = 0;
}

void Map::add(int key, int value)
{
	std::pair<int,int> p = make_pair(key, value);
	int pos = this->hashFunction(key);
	if (this->pair[pos] == make_pair(-1, -1))
	{
		this->pair[this->hashFunction(key)] = p;
		this->next[pos] = -1;
	}
	else
	{
		if (this->firstFree == this->hashSize)
		{
			std::exception ex{"The hash table is full!"}; throw(ex);}
		int current = pos;
		while (this->next[current] !=- 1)
			current = this->next[current];
		this->pair[this->firstFree] = p;
		this->next[this->firstFree] = -1;
		this->next[current] = this->firstFree;
		this->changeFirstFree();
	}
}

void Map::remove(int key)
{
	int p, pp;
	int i = this->hashFunction(key);
	int j = -1;
	int idx = 0;
	while (idx < this->hashSize && j ==-1)
	{
		if (this->next[idx] == i)
			j = idx;
		else
			idx++;
	}
	while (i != -1 && this->pair[i].first != key)
	{
		j = i;
		i = this->next[i];
	}
	if (i == -1)
	{
		std::exception ex{ "Key doesn't exist!" }; throw(ex);}
	else
	{
		bool over = false;
		while(over == false)
		{
			p = this->next[i];
			pp = i;
			while (p != -1 && this->hashFunction(this->pair[p].first) != i)
			{
				pp = p;
				p = this->next[p];
			}
			if (p == -1)
				over = true;
			else
			{
				this->pair[i] = this->pair[p];
				j = pp;
				i = p;
			}
		}
		if (j != -1)
			this->next[j] = this->next[i];
		this->pair[i] = make_pair(-1,-1);
		this->next[i] = -1;
		if (this->firstFree > i)
			this->firstFree = i;
	}
}

int Map::search(int key)
{
	int pos;
	pos = this->hashFunction(key);
	while (pos != -1 && this->pair[pos].first != key)
		pos = this->next[pos];
	if (pos == -1)
	{
		std::exception ex{ "The key doesn't exist!" }; throw(ex);}
	else
		return this->pair[pos].second;
}

void Map::changeFirstFree()
{
	this->firstFree = this->firstFree + 1;
		while (this->firstFree < this->getHashSize() && this->pair[this->firstFree] != make_pair(-1,-1))
			this->firstFree = this->firstFree + 1;
}

std::pair<int, int>& Map::operator[](int pos)
{
	return this->pair[pos];
}

int Map::getNumberOfPairs()
{
	std::pair<int, int> p = make_pair(-1, -1);
	int nr = 0;
	for (int i = 0; i < this->hashSize; i++)
	{
		if (this->pair[i].first != p.first && this->pair[i].second != p.second)
			nr++;
	}
	return nr;
}

float Map::getAverage(int day)
{
	float sumE = 0,sumO=0,kE=0,kO=0;
	for (int i = 0; i < this->hashSize; i++)
	{
		if(this->pair[i].first%2==1 && search(this->pair[i].first)!=-1)
		{	
			sumO += this->pair[i].second;
			kO++;
		}
		else 
		if(this->pair[i].first % 2 == 0 && search(this->pair[i].first) != -1){
			sumE += this->pair[i].second;
			kE++;
		}
	}
	if(day == 1)
		return sumO/kO;
	return sumE / kE;
}

void Map::testMap()
{
	Map m{};
	m.add(1, 3);
	m.add(2, 4);
	m.add(6, 6);
	m.add(12, 8);
	assert(m.getAverage(2) == 6);
	m.add(62, 4);
	m.add(82, 5);
	assert(m.getAverage(1) == 3);
	
	assert(m[1] == make_pair(1, 3));
	assert(m.getNumberOfPairs() == 6);
	m.add(22, 9);
	m.add(42, 2);
	assert(m.getNumberOfPairs() == 8);
	m.remove(1);
	assert(m.getNumberOfPairs() == 7);
	m.remove(22);
	m.remove(82);
	assert(m.getNumberOfPairs() == 5);
	/*m.remove(5);
	assert(m.getNumberOfPairs() == 5);*/
	assert(m.search(12)==8);
	assert(m.search(42) == 2);
	m.remove(62);
	assert(m.getNumberOfPairs() == 4);
	
	assert(m.getNext(1) == -1);
	m.add(7, 1);
	m.add(17, 2);
	m.add(37, 3);
	m.add(57, 3);
	m.remove(7);
	m.remove(17);
	m.remove(57);
}
