#pragma once
#include <iostream>
#include <windows.h>
#include <fstream>


using namespace std;

class Variables {
protected:
	string name;
	string weapon = "без оружия";
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
		cout << "\n\tВведите имя Игрока: ";
		cin >> name;
		cout << endl;
	}
	string getNameLoc() {
		switch (IDLocation) {
		case 1: {
			return("Город Мегатонна");
			break;
		}
		case 2: {
			return("Ривет-Сити");
			break;
		}
		case 3: {
			return("Убежище Братства Стали");
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
		cout << "\tУровень " << lvl << "\t" << points << "/" << limitPoints << " очков опыта." << endl;
		cout << "\tЗдоровье " << health << "/" <<nomHealth << endl;
		cout << "\tСопротивление урону " << armor << endl;
		cout << "\tОружие: " << weapon << endl;
		cout << "\tСила урона " << damage << endl;
		cout << "\tКрышки " << caps << endl;
		
	}
	void trade() {
		if (weapStick > 0 || weapGun > 0 || weapMachgug > 0 || weapMinigun) {
			int* choice = new int;
			do {
				Sleep(500);
				cout << "\n\tУ вас имеется: " << endl;
				if (weapStick > 0) cout << "\tБита - " << weapStick << "шт. \tЦена 10 крышек/шт." << endl;
				if (weapGun > 0) cout << "\tПистолет - " << weapGun << "шт. \tЦена 15 крышек/шт." << endl;
				if (weapMachgug > 0) cout << "\tАвтомат - " << weapMachgug << "шт. \tЦена 25 крышек/шт." << endl;
				if (weapMinigun > 0) cout << "\tПулемет - " << weapMinigun << "шт. \tЦена 30 крышек/шт." << endl;
				cout << "\n\tВыберите оружие, которое хотите продать: " << endl;
				if (weapStick > 0) cout << "\t1 - Бита";
				if (weapGun > 0) cout << "\t2 - Пистолет";
				if (weapMachgug > 0) cout << "\t3 - Автомат";
				if (weapMinigun > 0) cout << "\t4 - Пулемет";
				cout << "\t5 - Поторговали и хватит." << endl;

				cin >> *choice;
				switch (*choice) {
				case  1: {
					if (weapStick > 0) {
						setCaps(10);
						cout << "\tВы продали биту. (+10 крышек)" << endl;
						deductWeapon(*choice);
					}
					break;
				}
				case  2: {
					if (weapGun > 0) {
						setCaps(15);
						cout << "\tВы продали пистолет. (+15 крышек)" << endl;
						deductWeapon(*choice);
					}
					break;
				}
				case  3: {
					if (weapMachgug > 0) {
						setCaps(25);
						cout << "\tВы продали автомат. (+25 крышек)" << endl;
						deductWeapon(*choice);
					}
					break;
				}
				case  4: {

					if (weapMinigun > 0) {
						setCaps(30);
						cout << "\tВы продали пулемет. (+30 крышек)" << endl;
						deductWeapon(*choice);
					}
					break;
				}
				}
			} while ((*choice != 5)&&(weapStick > 0 || weapGun > 0 || weapMachgug > 0 || weapMinigun > 0));
			delete choice;
		} else cout << "\n\tУ вас нечего предложить на продажу. " << endl;
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
			cout << "\n\tВы нанесли урон противнику" << endl;
			healthEn = healthEn - *realDamPl;
			if (healthEn < 0)
			{
				cout << "\tЗдоровье противника 0" << endl;
			}
			else
			{
				cout << "\tЗдоровье противника " << healthEn << endl;
			}
			Sleep(1000);
			if (healthEn > 0) {
				cout << "\n\tВам насли урон" << endl;
				health = health - *realDamEn;
				if (health < 0)
				{
					cout << "\tВаше здоровье 0/" << nomHealth << endl;
				}
				else {
					cout << "\tВаше здоровье " << health << " / " << nomHealth << endl;
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
		cout << "\tВы достали карту. На карте отмечено несколько мест. Выберите место, куда хотите отправиться." << endl;
		cout << "\t1 - Город Мегатонна	2 - Ривет-Сити.	3 - Убежище Братства Стали.	4 -  Убрать карту" << endl;
		int* choice = new int;
		do {
			cin >> *choice;
			if (*choice == IDLocation) cout << "\tВы находитесь в выбранной локации." << endl;
		} while (*choice == IDLocation);

		switch (*choice) {
		case 1: {
			IDLocation = 1;
			take = 1;
			cout << "\tОтправились в Мегатонну" << endl;
			Sleep(1000);
			break;
		}
			
		case 2: {
			IDLocation = 2;
			take = 1;
			cout << "\tОтправились в Ривет Сити" << endl;
			Sleep(1000);
			break;
		}
		
		case 3: {
			IDLocation = 3;
			take = 1;
			cout << "\tОтправились в Убежище Братства Стали" << endl;
			Sleep(1000);
			break;
		}
		case 4: {
			cout << "\tУбрали карту" << endl;
			break;
		}
		}
		delete choice;
	}
	int baseAction() {
		cout << "\t1 - Осмотреть местность.\t2 - Достать карту.\t3 - Оценить своё состояние и снаряжение" << endl;
		cout << "\t                        \t                  \t4 - Сохранить игру." << endl;
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
		cout << "\tВаше состояние:" << endl;
		cout << "\tУровень " << lvl << "\t" << points << " очков опыта." << endl;
		cout << "\tЗдоровье " << health << "/" << nomHealth << endl;
		cout << "\tСопротивление урону " << armor << endl;
		cout << "\tСила урона " << damage << endl;
	}
	~Player() {
		if (alive) {
			cout << "\t" << name << " Предотвратил войну" << endl;
		}
		else {
			cout << "\t" << name << " погиб." << endl;
		}
	}
};
