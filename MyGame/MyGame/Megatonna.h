#pragma once
#include <iostream>
#include "towns.h"
#include <windows.h>


using namespace std;

class Megatonna : public Towns {
public:
	int inspectLocat() {
		Sleep(500);
		cout << "\tПо улице ходят несколько людей, возле жестяного сарая сидит бородатый худой человек." << endl;
		cout << "\t Недалеко виднеется вывеска 'MarketTonna', а в центре улици лежит огромная неразорвавшаяся бомба." << endl;
		cout << "\t1 - Подойти к человеку.	2 - Зайти в магазин.	3 - Заняться другими делами." << endl;
		int* choice = new int;
		cin >> *choice;
		switch (*choice) {
		case 1: {
			delete choice;
			return (1);
			break;
		}
		case 2: {
			delete choice;
			return (2);
			break;
		}
		case 3: {
			delete choice;
			return (3);			
			break;
		}
		}
	}

	~Megatonna() {
		if (alive) {
			cout << name << "\tМегатонны не существовало. " << endl;
		}
		else {
			cout << "\tМегатонна взорвалась." << endl;
		}
		
	}

};