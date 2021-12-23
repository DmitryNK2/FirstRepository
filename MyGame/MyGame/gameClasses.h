#pragma once
#include <iostream>
#include <windows.h>
#include <fstream>


using namespace std;

class Variables {
protected:
	string name;
	string weapon = "��� ������";
	int weapMinigun;
	int weapMachgug;
	int nomHealth = 100;
	int health = 100;
	int caps = 100;
	int armor = 20;
	int nomArmor = 5;
	int damage = 30;
	int points = 0;
	int limitPoints = 300;
	int weapStick = 0;
	int weapGun = 0;
public:
	bool gameOver = false;
	bool alive = true;
	bool take = (false);
	int lvl = 1;
	int IDLocation = 1;
	bool takeMachinTime = false;
};

class GetSet : public Variables {
public:
	int getTake() {
		return take;
	}
	void setDefTake() {
		take = 0;
	}
	void setTake() {
		take = 1;
	}
	void setTkMchTime() {
		takeMachinTime = true;
	}
	int getTkMchTime() {
		return takeMachinTime;
	}
	int getLvl() {
		return lvl;
	}
	int getLimPoints() {
		return limitPoints;
	}
	void setLimPoints() {
		limitPoints += 300;
	}
	int getPoints() {
		return points;
	}
	void setPoints(int setPoints) {
		points += setPoints;
	}
	int getDamage() {
		return damage;
	}
	int* getAdrsDamage() {
		return &damage;
	}
	void setDamage(int damage) {
		this->damage = damage;
	}
	int getHealth() {
		return health;
	}
	int* getAdrsHealth() {
		return &health;
	}
	int getNomHealth() {
		return nomHealth;
	}
	int* getAdrsNomHealth() {

		return &nomHealth;
	}
	void setHealth(int health) {
		this->health = health;
	}
	string getWeapon() {
		return (weapon);
	}
	string* getAdrsWeapon() {
		return &weapon;
	}
	int getArmor() {
		return(armor);
	}
	int* getAdrsArmor() {
		return &armor;
	}
	int* getAdrsNomArmor() {
		return &nomArmor;
	}
	int getCaps() {
		return caps;
	}
	int* getAdrsCaps() {
		return &caps;
	}
	void setCaps(int setCaps) {
		caps += setCaps;
	}
	int getIDLocation() {
		return (IDLocation);
	}
	string getName() {
		return name;
	}
	void setName() {
		cout << "\n\t������� ��� ������: ";
		cin >> name;
		cout << endl;
	}
	string getNameLoc() {
		switch (IDLocation) {
		case 1: {
			return("����� ���������");
			break;
		}
		case 2: {
			return("�����-����");
			break;
		}
		case 3: {
			return("������� �������� �����");
			break;
		}
		}
	}
};
 

class Player: public GetSet {

public:
	
	Player() {
		
	}	

	void fullState() {
		cout << "\t������� " << lvl << "\t" << points << "/" << limitPoints << " ����� �����." << endl;
		cout << "\t�������� " << health << "/" <<nomHealth << endl;
		cout << "\t������������� ����� " << armor << endl;
		cout << "\t������: " << weapon << endl;
		cout << "\t���� ����� " << damage << endl;
		cout << "\t������ " << caps << endl;
		
	}
	void trade() {
		if (weapStick > 0 || weapGun > 0 || weapMachgug > 0 || weapMinigun) {
			int* choice = new int;
			do {
				Sleep(500);
				cout << "\n\t� ��� �������: " << endl;
				if (weapStick > 0) cout << "\t���� - " << weapStick << "��. \t���� 10 ������/��." << endl;
				if (weapGun > 0) cout << "\t�������� - " << weapGun << "��. \t���� 15 ������/��." << endl;
				if (weapMachgug > 0) cout << "\t������� - " << weapMachgug << "��. \t���� 25 ������/��." << endl;
				if (weapMinigun > 0) cout << "\t������� - " << weapMinigun << "��. \t���� 30 ������/��." << endl;
				cout << "\n\t�������� ������, ������� ������ �������: " << endl;
				if (weapStick > 0) cout << "\t1 - ����";
				if (weapGun > 0) cout << "\t2 - ��������";
				if (weapMachgug > 0) cout << "\t3 - �������";
				if (weapMinigun > 0) cout << "\t4 - �������";
				cout << "\t5 - ����������� � ������." << endl;

				cin >> *choice;
				switch (*choice) {
				case  1: {
					if (weapStick > 0) {
						setCaps(10);
						cout << "\t�� ������� ����. (+10 ������)" << endl;
						deductWeapon(*choice);
					}
					break;
				}
				case  2: {
					if (weapGun > 0) {
						setCaps(15);
						cout << "\t�� ������� ��������. (+15 ������)" << endl;
						deductWeapon(*choice);
					}
					break;
				}
				case  3: {
					if (weapMachgug > 0) {
						setCaps(25);
						cout << "\t�� ������� �������. (+25 ������)" << endl;
						deductWeapon(*choice);
					}
					break;
				}
				case  4: {

					if (weapMinigun > 0) {
						setCaps(30);
						cout << "\t�� ������� �������. (+30 ������)" << endl;
						deductWeapon(*choice);
					}
					break;
				}
				}
			} while ((*choice != 5)&&(weapStick > 0 || weapGun > 0 || weapMachgug > 0 || weapMinigun > 0));
			delete choice;
		} else cout << "\n\t� ��� ������ ���������� �� �������. " << endl;
	}

	bool fight(int healthEn, int armorEn, int damageEn) {
		int *realDamPl = new int;
		if ((damage - armorEn) > 0) {
			*realDamPl = (damage - armorEn);
		}
		else {
			*realDamPl = 0;
		}
		int* realDamEn = new int;
			if ((damageEn - armor) > 0) {
				*realDamEn = (damageEn - armor);
			}
			else {
				*realDamEn = 0;
			}
		while (health > 0 && healthEn > 0) {
			cout << "\n\t�� ������� ���� ����������" << endl;
			healthEn = healthEn - *realDamPl;
			if (healthEn < 0)
			{
				cout << "\t�������� ���������� 0" << endl;
			}
			else
			{
				cout << "\t�������� ���������� " << healthEn << endl;
			}
			Sleep(1000);
			if (healthEn > 0) {
				cout << "\n\t��� ����� ����" << endl;
				health = health - *realDamEn;
				if (health < 0)
				{
					cout << "\t���� �������� 0/" << nomHealth << endl;
				}
				else {
					cout << "\t���� �������� " << health << " / " << nomHealth << endl;
				}
				Sleep(1000);
			}
		}
		if (health > 0)
			return (true);
		else
			return (false);
	}

	void travel() {
		cout << "\t�� ������� �����. �� ����� �������� ��������� ����. �������� �����, ���� ������ �����������." << endl;
		cout << "\t1 - ����� ���������	2 - �����-����.	3 - ������� �������� �����.	4 -  ������ �����" << endl;
		int* choice = new int;
		do {
			cin >> *choice;
			if (*choice == IDLocation) cout << "\t�� ���������� � ��������� �������." << endl;
		} while (*choice == IDLocation);

		switch (*choice) {
		case 1: {
			IDLocation = 1;
			take = 1;
			cout << "\t����������� � ���������" << endl;
			Sleep(1000);
			break;
		}
			
		case 2: {
			IDLocation = 2;
			take = 1;
			cout << "\t����������� � ����� ����" << endl;
			Sleep(1000);
			break;
		}
		
		case 3: {
			IDLocation = 3;
			take = 1;
			cout << "\t����������� � ������� �������� �����" << endl;
			Sleep(1000);
			break;
		}
		case 4: {
			cout << "\t������ �����" << endl;
			break;
		}
		}
		delete choice;
	}
	int baseAction() {
		cout << "\t1 - ��������� ���������.\t2 - ������� �����.\t3 - ������� ��� ��������� � ����������" << endl;
		cout << "\t                        \t                  \t4 - ��������� ����." << endl;
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

	void deductWeapon(int weapon) {
		switch (weapon) {
		case 1: {
			weapStick = weapStick - 1;
			break;
		}
		case 2: {
			weapGun = weapGun - 1;
			break;
		}
		case 3: {
			weapMachgug = weapMachgug - 1;
			break;
		}
		case 4: {
			weapMinigun = weapMinigun - 1;
			break;
		}
		}
	}
	void addWeapon(int weapon) {
		switch (weapon) {
		case 1: {
			weapStick += 1;
			break;
		}
		case 2: {
			weapGun += 1;
			break;
		}
		case 3: {
			weapMachgug += 1;
			break;
		}
		case 4: {
			weapMinigun += 1;
			break;
		}
		}
	}
	
	void lvlUp() {
		this->lvl++;
		nomHealth = (nomHealth * 1.1);
		nomArmor = (nomArmor * 1.1);
		damage = (damage * 1.1);
	}
	
	
	virtual void getStats() {
		cout << "\t���� ���������:" << endl;
		cout << "\t������� " << lvl << "\t" << points << " ����� �����." << endl;
		cout << "\t�������� " << health << "/" << nomHealth << endl;
		cout << "\t������������� ����� " << armor << endl;
		cout << "\t���� ����� " << damage << endl;
	}
	~Player() {
		if (alive) {
			cout << "\t" << name << " ������������ �����" << endl;
		}
		else {
			cout << "\t" << name << " �����." << endl;
		}
	}
};
