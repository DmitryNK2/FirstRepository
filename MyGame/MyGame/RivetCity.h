#pragma once
#include <iostream>
#include "towns.h"
#include <windows.h>



class RivetCity : public Towns {
public:

	int inspectLocat() {
		Sleep(500);
		cout << "\n\t�����-���� ��� �����, ������� �������� �� ������� �������." << endl;
		cout << "\t�� ������� ���� '����� ����������', ������� �������� ������ �� ����� ����." << endl;
		cout << "\t����� ����� ���� �������, � ������� ����� �� ��������� ����� ����������." << endl;
		cout << "\t1 - ����� � �����.	2 - ����� � �������.	3 - �������� ������� ������." << endl;
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
			cout << "\t" << name << "�����-���� �� ������������. " << endl;
		}
		else {
			cout << "\t" << "����� - ���� �������." << endl;
		}
	}
};
