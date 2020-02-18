#include "UI.h"
#include<iostream>
#include <string>
#include "Iterator.h"
#include "Map.h"
#include <assert.h>

using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "\t 1 - Display agenda." << endl;
	cout << "\t 2 - Add a day and the number of studied hours to the agenda." << endl;
	cout << "\t 3 - Delete information from a day." << endl;
	cout << "\t 4 - Search the studied hours for a day." << endl;
	cout << "\t 5 - Compute average of studied hours for odd/even days." << endl;
	cout << "\t 0 - Exit." << endl;
}

void UI::addPair()
{
	int key{};
	int val{};
	cout << "Give key: ";
	cin >> key;
	cout << "Give value: ";
	cin >> val;
	try
	{
		this->map.add(key, val);
	}
	catch (std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void UI::removeKey()
{
	int key{};
	int val{};
	cout << "Give key: ";
	cin >> key;
	try
	{
		this->map.remove(key);
	}
	catch (std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void UI::searchKey()
{
	int key{};
	int val{};
	cout << "Give key: ";
	cin >> key;
	try
	{
		cout <<"The value of the given key is: "<< this->map.search(key)<<endl;
	}
	catch (std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void UI::displayAll()
{
	int pos = 0;
	Iterator* it = map.getIterator();
	while (it->isValid())
	{
		//cout << "| " << pos << " | <" << it->getCurrent().first << ", " << it->getCurrent().second << "> | next: " << map.getNext(pos) << endl;
		cout << "| " << pos << " | <" << it->getCurrent().first << ", " << it->getCurrent().second << endl;
		cout << "_________________________" << endl;
		it->next();
		pos++;
	}
}

void UI::averageHours()
{
	cout << "Press 1 if you want to compute the average of studied hours for odd days or 2 for the even dates." << endl;
	int day{};
	cin >> day;
	float av= this->map.getAverage(day);
	cout <<"The average of studied hours is: "<< av << endl;
}

void UI::run()
{
	while (true)
	{

		UI::printMenu();
		int command{};
		cout << "Give command: ";
		cin >> command;
		if (command == 0)
			break;
		switch (command)
		{
		case 1:
			this->displayAll();
			break;
		case 2:
			this->addPair();
			break;
		case 3:
			this->removeKey();
			break;
		case 4:
			this->searchKey();
			break;
		case 5:
			this->averageHours();
			break;
		}
	}
}

//void UI::testIterator()
//{
//	Map m{};
//	m.add(1, 3);
//	m.add(2, 4);
//	m.add(3, 6);
//	UI ui{ m };
//	Iterator* it = m.getIterator();
//	std::pair<int,int> p= m.getIterator()->getCurrent();
//	assert(p.first == -1);
//	assert(p.second == -1);
//	it->next();
//	assert(it->getCurrent().first == 1);
//	assert(it->getCurrent().second == 3);
//	assert(it->isValid() == true);
//	for (int i = 0; i < m.getHashSize(); i++)
//		it->next();
//	assert(it->isValid() == false);
//}