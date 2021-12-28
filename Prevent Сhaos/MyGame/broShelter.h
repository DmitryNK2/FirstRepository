#pragma once
#include <iostream>
#include "towns.h"
#include <windows.h>



using namespace std;

class BroShelter : public Towns{
public:
	int inspectLocat() {
		Sleep(500);
		cout << "\n\t������� �������� �������� �������� ������. ����� ���� ����������� ��������� ����� ������������� ��������." << endl;
		cout << "\t������ ������ ����� � ������ ������ ����������. �� ��������� ������ ������ ������ ������� �����." << endl;
		cout << "\t��������� ����� ��������� ������������ �� �������� ���������, � ������� ������ ����� � ������� ���������." << endl;
		cout << "\t1 - ����� � ����� ������ �����.	2 - ����� � ������� ���������.	3 - ����� � ��������� ������ �������. " << endl;
		cout << "\t4 - �������� ������� ������." << endl;
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
		cout << "\t1 : ������������ ����� (+25 ������������� �����)\t���� 180 ������" << endl;
		cout << "\t2 : ������� (50 �����)\t���� 100 ������" << endl;
		cout << "\t3 : ������� (65 �����)\t���� 200 ������" << endl;
		cout << "\t4 : ����." << endl;

		int* choice = new int;
		do {
			cin >> *choice;
			switch (*choice) {
			case 1: {
				if (*caps >= 180) {
					cout << "\t�� ������ ������������ �����" << endl;
					*armor = *nomArmor + 25;
					*caps = *caps - 180;
					cout << "\t�������� ������: " << *caps << endl;
				}
				else cout << "\t� ��� �� ������� ������" << endl;
				break;
			}
			case 2:{
				if(*caps >= 100) {
				cout << "\t�� ������ �������" << endl;
				*weapon = "�������";
				*damage = 50;
				*caps = *caps - 100;
				cout << "\t�������� ������: " << *caps << endl;
			}
				else cout << "\t� ��� �� ������� ������" << endl;
				break;
			}
			case 3: {
				if (*caps >= 200) {
					cout << "\t�� ������ �������" << endl;
					*weapon = "�������";
					*damage = 65;
					*caps = *caps - 200;
					cout << "\t�������� ������: " << *caps << endl;
				}
				else cout << "\t� ��� �� ������� ������" << endl;
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
			 cout << name << "\t������� �������� �� ������������" << endl;
		 }
		 else {
			 cout << "\t������� �������� ����� ���������" << endl;
		 }
		 
	 }
};