#pragma once
#include <iostream>
#include "towns.h"
#include <windows.h>



class RivetCity : public Towns {
public:

	int inspectLocat() {
		Sleep(500);
		cout << "\n\tРивет-Сити это город, который основали на большом корабле." << endl;
		cout << "\tНа корабле есть 'Лавка Экипировки', которой заведует старик по имени Стен." << endl;
		cout << "\tТакже здесь есть магазин, в котором можно за небольшую сумму накидаться." << endl;
		cout << "\t1 - Зайти к Стену.	2 - Пойти в магазин.	3 - Заняться другими делами." << endl;
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
	~RivetCity() {
		if (alive) {
			cout << "\t" << name << "Ривет-Сити не существовало. " << endl;
		}
		else {
			cout << "\t" << "Ривет - Сити затонул." << endl;
		}
	}
};
