#pragma once
#include <Windows.h>
#include <iostream>
#include<string>
#include<vector>
#include "Map.h"
#include "UI.h"
using namespace std;

int main()
{
	Map m{};
	m.testMap();
	m.add(1, 3);
	m.add(2, 4);
	m.add(6, 6);
	m.add(7, 9);
	m.add(12, 8);
	m.add(29,12);
	m.add(22, 9);
	m.add(16, 2);
	m.add(11, 7);
	m.add(21, 5);
	m.add(26, 3);
	m.add(27, 1);
	UI ui{ m };
	//ui.testIterator();
	ui.run();

	system("pause");
	return 0;
}