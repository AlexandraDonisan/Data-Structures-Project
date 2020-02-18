#pragma once
#include <string>
#include <vector>
#include <exception>
#include <string>
#include "Iterator.h"
//class Iterator;

class Map
{
private:
	std::pair<int, int> pair[20];
	int next[20];
	int hashSize=20;
	int firstFree=0;
	int hashFunction(int key) { return key % hashSize; }
	

public:
	Map();
	~Map(){}
	friend class Iterator;

	void add(int key, int value);
	void remove(int key);
	int search(int key);

	
	Iterator* getIterator() { return new Iterator(this); }
	int getNumberOfPairs();
	float getAverage(int day);

	void testMap();

private:
	void changeFirstFree();

	std::pair<int, int>& operator[](int pos);

	int getNext(int pos) { return this->next[pos]; }
	int getHashSize() const { return this->hashSize; }
};