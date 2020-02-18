#pragma once
#include "Map.h"


class UI
{
private:
	Map map;
public:
	UI(const Map& m) : map(m) {}
	~UI(){}

	void run();
	//void testIterator();

private:
	static void printMenu();
	void addPair();
	void removeKey();
	void searchKey();
	void displayAll();
	void averageHours();
};

