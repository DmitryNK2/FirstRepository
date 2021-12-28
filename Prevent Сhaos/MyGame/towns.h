#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class Towns: public Variables {
public:
	virtual void outfit(int* caps, int* damage, int* armor, int* nomArmor, string* weapon){
		cout << "\t1 : ������� ����� (+10 ������������� �����)\t���� 70 ������" << endl;
		cout << "\t2 : �������� (40 ����)\t���� 40 ������" << endl;
		cout << "\t3 : ��� ���, ��� � ����� ����������." << endl;

		int* choice = new int;
		do {
			cin >> *choice;
			switch (*choice) {
			case 1: {
				if (*caps >= 70) {
					cout << "\t�� ������ ������� �����" << endl;
					*armor = *nomArmor + 10;
					*caps = *caps - 70;
					cout << "\t�������� ������: " << *caps << endl;
				}
				else cout << "\t� ��� �� ������� ������" << endl;
				break;
			}
			case 2: {
				if (*caps >= 40) {
					cout << "\t�� ������ ��������" << endl;
					*weapon = "��������";
					*damage = 40;
					*caps = *caps - 40;
					cout << "\t�������� ������: " << *caps << endl;
				}
				else cout << "\t� ��� �� ������� ������" << endl;
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
		cout << "\n\t��������: -������������! ��� �� ������?" << endl;
		cout << "\t1 : ���������� (+25 ��������)\t���� 35 ������" << endl;
		cout << "\t2 : ����� �������� (+5 ��������)\t���� 8 ������" << endl;
		cout << "\t3 : ���������� (+2 ��������)\t���� 3 ������" << endl;
		cout << "\t4 : ����� (+4 ��������)\t���� 10 ������" << endl;
		cout << "\t5 : ����� �� ��������" << endl;
		//int *givenCaps = new int;

		int* choice = new int;
		do {
			cin >> *choice;
			switch (*choice) {
			case 1: {
				if (*caps >= 35) {
					cout << "\t�� ������ ����������" << endl;
					*health = *health + 25;
					if (*health > *nomHealth) {
						*health = *nomHealth;
					}
					*caps = *caps - 35;
					cout << "\t�������� ������: " << *caps << endl;
				}
				else cout << "\t� ��� �� ������� ������" << endl;
				break;
			}
			case 2: {
				if (*caps >= 8) {
					cout << "\t�� ������ ����� ��������" << endl;
					*health = *health + 5;
					if (*health > *nomHealth) {
						*health = *nomHealth;
					}
					*caps = *caps - 8;
					cout << "\t�������� ������: " << *caps << endl;
				}
				else cout << "\t� ��� �� ������� ������" << endl;
				break;
			}
			case 3: {
				if (*caps >= 3) {
					cout << "\t�� ������ ����������" << endl;
					*health = *health + 2;
					if (*health > *nomHealth) {
						*health = *nomHealth;
					}
					*caps = *caps - 3;
					cout << "\t�������� ������: " << *caps << endl;
				}
				else cout << "\t� ��� �� ������� ������" << endl;
				break;
			}
			case 4: {
				if (*caps >= 10) {
					cout << "\t�� ������ �����" << endl;
					*health = *health + 4;
					if (*health > *nomHealth) {
						*health = *nomHealth;
					}
					*caps = *caps - 3;
					cout << "\t�������� ������: " << *caps << endl;
				}
				else cout << "\t� ��� �� ������� ������" << endl;
				break;
				break;
			}
			case 5: {
				cout << "\t����� ��������." << endl;
				break;
			}
			}
		} while (*choice != 5);
		delete choice;
	}

	void hospital(int* caps, int* health, int* nomHealth) {
		cout << "\n\t���������: -������������. � ����, �� �� �� ��������, � ������ � �� ����" << endl;
		cout << "\t������� ��� ����������� ������ ���������. ����� ����� ��������" << endl;
		cout << "\t1 : ���������� (+25 ��������)\t���� 35 ������" << endl;
		cout << "\t2 : ������� (+12 ��������)\t���� 20 ������" << endl;
		cout << "\t3 : ������ ���� (+10 ��������)\t���� 17 ������" << endl;
		cout << "\t4 : ����� �� ��������" << endl;
		//int *givenCaps = new int;

		int* choice = new int;
		do {
			cin >> *choice;
			switch (*choice) {
			case 1: {
				if (*caps >= 35) {
					cout << "\t�� ������ ����������" << endl;
					*health = *health + 25;
					if (*health > *nomHealth) {
						*health = *nomHealth;
					}
					*caps = *caps - 35;
					cout << "\t�������� ������: " << *caps << endl;
				}
				else cout << "\t� ��� �� ������� ������" << endl;
				break;
			}
			case 2: {
				if (*caps >= 20) {
					cout << "\t�� ������ �������" << endl;
					*health = *health + 12;
					if (*health > *nomHealth) {
						*health = *nomHealth;
					}
					*caps = *caps - 20;
					cout << "\t�������� ������: " << *caps << endl;
				}
				else cout << "\t� ��� �� ������� ������" << endl;
				break;
			}
			case 3: {
				if (*caps >= 17) {
					cout << "\t�� ������ ������ ����" << endl;
					*health = *health + 10;
					if (*health > *nomHealth) {
						*health = *nomHealth;
					}
					*caps = *caps - 17;
					cout << "\t�������� ������: " << *caps << endl;
				}
				else cout << "\t� ��� �� ������� ������" << endl;
				break;
			}
			
			case 4: {
				cout << "\t-�� �������." << endl;
				break;
			}
			}
		} while (*choice != 4);
		delete choice;
	}

	~Towns() {
		if (alive) {
			cout << "\t��� ������ �������" << endl;
		}
		else {
			cout << "\t��� ���������� ������ �������." << endl;
		}
		
	}
};