#pragma once
#include <iostream>
#include "towns.h"
#include <windows.h>



using namespace std;

class BroShelter : public Towns{
public:
	int inspectLocat() {
		Sleep(500);
		cout << "\n\tУбежище обнесено огромной стальной стеной. Здесь люди тренеруются сражаться чтобы противостоять мутантам." << endl;
		cout << "\tБойцам выдают броню в пункте выдачи снаряжения. Но бесплатно выдают только членам Братсва Стали." << endl;
		cout << "\tОбученные бойцы регулярно отправляются на зачистку местности, а раненых бойцов лечат в местном госпитале." << endl;
		cout << "\t1 - Пойти в пункт выдачи брони.	2 - Пойти в местный госпиталь.	3 - Найти и запустить машину времени. " << endl;
		cout << "\t4 - Заняться другими делами." << endl;
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
		case 4: {
			delete choice;
			return (4);
			break;
		}
		}
	}

	 void outfit (int* caps, int* damage, int* armor, int* nomArmor, string* weapon) override{
		cout << "\t1 : Металическая броня (+25 Сопротивлению урона)\tЦена 180 Крышек" << endl;
		cout << "\t2 : Автомат (50 Урона)\tЦена 100 Крышек" << endl;
		cout << "\t3 : Огнемет (65 Урона)\tЦена 200 Крышек" << endl;
		cout << "\t4 : Уйти." << endl;

		int* choice = new int;
		do {
			cin >> *choice;
			switch (*choice) {
			case 1: {
				if (*caps >= 180) {
					cout << "\tВы купили Металическую броню" << endl;
					*armor = *nomArmor + 25;
					*caps = *caps - 180;
					cout << "\tОстальсь крышек: " << *caps << endl;
				}
				else cout << "\tУ вас не хватает крышек" << endl;
				break;
			}
			case 2:{
				if(*caps >= 100) {
				cout << "\tВы купили Автомат" << endl;
				*weapon = "Автомат";
				*damage = 50;
				*caps = *caps - 100;
				cout << "\tОстальсь крышек: " << *caps << endl;
			}
				else cout << "\tУ вас не хватает крышек" << endl;
				break;
			}
			case 3: {
				if (*caps >= 200) {
					cout << "\tВы купили Огнемет" << endl;
					*weapon = "Огнемет";
					*damage = 65;
					*caps = *caps - 200;
					cout << "\tОстальсь крышек: " << *caps << endl;
				}
				else cout << "\tУ вас не хватает крышек" << endl;
				break;		
			}	  
			case 4: {	
				break;
			}
			}
		} while (*choice != 4);
		delete choice;
	}
	
	 ~BroShelter() {
		 if (alive) {
			 cout << name << "\tУбежище братства не существовало" << endl;
		 }
		 else {
			 cout << "\tУбежище братства стали захватили" << endl;
		 }
		 
	 }
};