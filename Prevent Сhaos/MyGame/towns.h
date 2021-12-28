#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class Towns: public Variables {
public:
	virtual void outfit(int* caps, int* damage, int* armor, int* nomArmor, string* weapon){
		cout << "\t1 : Кожаная броня (+10 Сопротивлению урона)\tЦена 70 Крышек" << endl;
		cout << "\t2 : Пистолет (40 Урон)\tЦена 40 Крышек" << endl;
		cout << "\t3 : Это все, что я хотел посмотреть." << endl;

		int* choice = new int;
		do {
			cin >> *choice;
			switch (*choice) {
			case 1: {
				if (*caps >= 70) {
					cout << "\tВы купили Кожаную броню" << endl;
					*armor = *nomArmor + 10;
					*caps = *caps - 70;
					cout << "\tОстальсь крышек: " << *caps << endl;
				}
				else cout << "\tУ вас не хватает крышек" << endl;
				break;
			}
			case 2: {
				if (*caps >= 40) {
					cout << "\tВы купили Пистолет" << endl;
					*weapon = "Пистолет";
					*damage = 40;
					*caps = *caps - 40;
					cout << "\tОстальсь крышек: " << *caps << endl;
				}
				else cout << "\tУ вас не хватает крышек" << endl;
				break;
				break;
				
			}
			
			case 3: {
				break;
			}
			}
		} while (*choice != 3);
		delete choice;
	}

	virtual void market(int* caps, int* health, int* nomHealth) {
		cout << "\n\tПродавец: -Здравствуйте! Что то хотели?" << endl;
		cout << "\t1 : Стимулятор (+25 Здоровья)\tЦена 35 Крышек" << endl;
		cout << "\t2 : Сухие макароны (+5 Здоровья)\tЦена 8 Крышек" << endl;
		cout << "\t3 : Сухофрукты (+2 Здоровья)\tЦена 3 Крышки" << endl;
		cout << "\t4 : Виски (+4 Здоровья)\tЦена 10 Крышек" << endl;
		cout << "\t5 : Выйти из магазина" << endl;
		//int *givenCaps = new int;

		int* choice = new int;
		do {
			cin >> *choice;
			switch (*choice) {
			case 1: {
				if (*caps >= 35) {
					cout << "\tВы купили стимулятор" << endl;
					*health = *health + 25;
					if (*health > *nomHealth) {
						*health = *nomHealth;
					}
					*caps = *caps - 35;
					cout << "\tОстальсь крышек: " << *caps << endl;
				}
				else cout << "\tУ вас не хватает крышек" << endl;
				break;
			}
			case 2: {
				if (*caps >= 8) {
					cout << "\tВы купили Сухие макароны" << endl;
					*health = *health + 5;
					if (*health > *nomHealth) {
						*health = *nomHealth;
					}
					*caps = *caps - 8;
					cout << "\tОстальсь крышек: " << *caps << endl;
				}
				else cout << "\tУ вас не хватает крышек" << endl;
				break;
			}
			case 3: {
				if (*caps >= 3) {
					cout << "\tВы купили Сухофрукты" << endl;
					*health = *health + 2;
					if (*health > *nomHealth) {
						*health = *nomHealth;
					}
					*caps = *caps - 3;
					cout << "\tОстальсь крышек: " << *caps << endl;
				}
				else cout << "\tУ вас не хватает крышек" << endl;
				break;
			}
			case 4: {
				if (*caps >= 10) {
					cout << "\tВы купили Виски" << endl;
					*health = *health + 4;
					if (*health > *nomHealth) {
						*health = *nomHealth;
					}
					*caps = *caps - 3;
					cout << "\tОстальсь крышек: " << *caps << endl;
				}
				else cout << "\tУ вас не хватает крышек" << endl;
				break;
				break;
			}
			case 5: {
				cout << "\tВсего хорошего." << endl;
				break;
			}
			}
		} while (*choice != 5);
		delete choice;
	}

	void hospital(int* caps, int* health, int* nomHealth) {
		cout << "\n\tМедсестра: -Здравствуйте. Я вижу, вы не из Братства, а значит я не могу" << endl;
		cout << "\tоказать вам медицинскую помощь бесплатно. Таков закон Братства" << endl;
		cout << "\t1 : Стимулятор (+25 Здоровья)\tЦена 35 Крышек" << endl;
		cout << "\t2 : Аспирин (+12 Здоровья)\tЦена 20 Крышек" << endl;
		cout << "\t3 : Чистая вода (+10 Здоровья)\tЦена 17 Крышек" << endl;
		cout << "\t4 : Выйти из магазина" << endl;
		//int *givenCaps = new int;

		int* choice = new int;
		do {
			cin >> *choice;
			switch (*choice) {
			case 1: {
				if (*caps >= 35) {
					cout << "\tВы купили стимулятор" << endl;
					*health = *health + 25;
					if (*health > *nomHealth) {
						*health = *nomHealth;
					}
					*caps = *caps - 35;
					cout << "\tОстальсь крышек: " << *caps << endl;
				}
				else cout << "\tУ вас не хватает крышек" << endl;
				break;
			}
			case 2: {
				if (*caps >= 20) {
					cout << "\tВы купили Аспирин" << endl;
					*health = *health + 12;
					if (*health > *nomHealth) {
						*health = *nomHealth;
					}
					*caps = *caps - 20;
					cout << "\tОстальсь крышек: " << *caps << endl;
				}
				else cout << "\tУ вас не хватает крышек" << endl;
				break;
			}
			case 3: {
				if (*caps >= 17) {
					cout << "\tВы купили Чистую воду" << endl;
					*health = *health + 10;
					if (*health > *nomHealth) {
						*health = *nomHealth;
					}
					*caps = *caps - 17;
					cout << "\tОстальсь крышек: " << *caps << endl;
				}
				else cout << "\tУ вас не хватает крышек" << endl;
				break;
			}
			
			case 4: {
				cout << "\t-Не болейте." << endl;
				break;
			}
			}
		} while (*choice != 4);
		delete choice;
	}

	~Towns() {
		if (alive) {
			cout << "\tВсе города уцелели" << endl;
		}
		else {
			cout << "\tВсе населенные пункты вымерли." << endl;
		}
		
	}
};