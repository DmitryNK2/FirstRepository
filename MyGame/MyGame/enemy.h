#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class Enemy: public Variables {
protected:
	bool enemyWeapStick = false;
	bool enemyWeapGun = false;
	bool enemyWeapMachgug = false;
	bool enemyWeapMinigun = false;
	int nomHealth;
	int health;
	int armor;
	int damage;
	string weapon;
	string name;
public:
	Enemy() {
	}

	int getArmor() {
		return(armor);
	}
	int getDamage() {
		return(damage);
	}
	void defaultWeapon() {
		enemyWeapStick = false;
		enemyWeapGun = false;
		enemyWeapMachgug = false;
		enemyWeapMinigun = false;
	}
	void getArgum(int* healthEn, int* armorEn, int* damageEn, int* weaponEn) {
		*healthEn = health;
		*armorEn = armor;
		*damageEn = damage;
		if (enemyWeapStick) *weaponEn = 1;
		else if (enemyWeapGun) *weaponEn = 2;
		else if (enemyWeapMachgug) *weaponEn = 3;
		else if (enemyWeapMinigun) *weaponEn = 4;
		else *weaponEn = 0;
	}

	void getStats() {
		cout << "\t�������� " << health << endl;
		cout << "\t���� ����� " << damage << endl;
		cout << "\t������������� ����� " << armor << endl;
	}

	void createHuman() {
		health = 50 + (rand() % 50);
		armor = rand() % 10;
		damage = 5 + rand() % 5;
		cout << "\n\t��� ���������� ����������";

		int* randFig = new int;
		*randFig =rand() % 4;
		switch (*randFig) {
		case 0: {
			delete randFig;
			cout << "\n\t����������:" << endl;
			break;
		}
		case 1: {
			delete randFig;
			cout << " � �����" << endl;
			damage += 4;
			enemyWeapStick = true;
			cout << "\n\t����������:" << endl;
			break;
		}
		case 2: {
			delete randFig;
			cout << " � ����������" << endl;
			damage += 10;
			enemyWeapGun = true;
			cout << "\n\t����������:" << endl;
			break;
		}
		case 3: {
			delete randFig;
			cout << " � ���������" << endl;
			damage += 15;
			enemyWeapMachgug = true;
			cout << "\n\t����������:" << endl;
			break;
		}
		case 4: {
			delete randFig;
			cout << " � ���������" << endl;
			damage += 25;
			enemyWeapMinigun = true;
			cout << "\n\t����������:" << endl;
			break;
		}
		}
	}

	void createMutant() {
		health = 50 + (rand() % 50);
		armor = 5 + (rand() % 10);
		damage = 5 + (rand() % 10);
		cout << "\n\t��� ���������� �������-������" ;
		
		int* randFig = new int;
		*randFig = rand() % 4;
		switch (*randFig) {
		case 0: {
			delete randFig;
			cout << "\n\t������� - ������:" << endl;
			break;
		}
		case 1: {
			delete randFig;
			cout << " � �����" << endl;
			damage += 4;
			enemyWeapStick = true;
			cout << "\n\t������� - ������:" << endl;

			break;
		}
		case 2: {
			delete randFig;
			cout << " � ���������" << endl;
			damage += 15;
			enemyWeapMachgug = true;
			cout << "\n\t������� - ������:" << endl;
			break;
		}
		case 3: {
			delete randFig;
			cout << " � ���������" << endl;
			damage += 25;
			enemyWeapMinigun = true;
			cout << "\n\t������� - ������:" << endl;
			break;
		}
		}
	}

	void createScorp() {
		health = 30 + (rand() % 30);
		armor = 5 + (rand() % 10);
		damage = 10 + (rand() % 15);
		cout << "\n\t��� ���������� �������� ��������-������" << endl;
		cout << "\n\t�������� - ������:" << endl;
	}

	void createAnt() {
		health = 20 + (rand() % 30);
		armor = 5 + (rand() % 10);
		damage = 10 + (rand() % 10);
		cout << "\n\t��� ���������� �������-������" << endl;
		cout << "\n\t������� - ������:" << endl;
	}	
	
	void choosEnemy() {
		int* randFig = new int;
		*randFig = rand() % 4;
		switch (*randFig) {
		case 0: {
			delete randFig;
			createHuman();
			break;
		}
		case 1: {
			delete randFig;
			createMutant();
			break;
		}
		case 2: {
			delete randFig;
			createScorp();
			break;
		}
		case 3: {
			delete randFig;
			createAnt();
			break;
		}
		}
		getStats();
	}
	~Enemy() {
		if (alive) {
			cout << "\t�������� �� ������������." << endl;
		}
		else {
			cout << "\t���� ��� ���������." << endl;
		}
		
	}
	
};

