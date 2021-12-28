#include <iostream>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include <dos.h>
#include <windows.h>
#include <string>
#include "gameClasses.h"
#include "enemy.h"
#include "towns.h"
#include "Megatonna.h"
#include "RivetCity.h"
#include "broShelter.h"
using namespace std;

void getArgum(Enemy* instClass,  int* health, int *armor, int* damage, int* weapon) {
	instClass->getArgum( health, armor, damage, weapon);
}

void createEnemy(Enemy* instClass) {
	instClass->choosEnemy();
}	



int main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	Megatonna megatonna;
	RivetCity rivetcity;
	BroShelter broShelter;
	Enemy enemy;

	Player player;

	

	int* choice = new int;
	ifstream fin;
	fin.open("saveGame.txt");//������
	if (fin.is_open()) {
		
		cout << "\n\t��������� ��������� ����������� ����?" << endl;
		cout << "\n\t1 - ��������� ����.\t2 - ������ ����� ����." << endl;
		cout << "\t";
		cin >> *choice;
		if (*choice == 1) {
			fin.read((char*)&player, sizeof(Player));
			Sleep(700);
			cout << "\t�������� ���� ���������." << endl;
		}	
		fin.close();
	}
	cout << "\n\t\t\t\t~ ~ ~ ������ ���� ~ ~ ~" << endl;
	if (*choice != 1) {
		cout << "\n\t\t����� ������� ����� ������� ������������ � ��������� ��. " << endl;
		cout << "\t�� ������, ������� �������� �� ������� ������ �������, ������� ��������, " << endl;
		cout << "\t� ������ ���� � ��� ����������� ���. ���������� �� ����� ���� ��������, ��� �����." << endl;
		cout << "\t\t���-�� �������� ������ ������ �����, ���-�� ����������� ������� ����������� " << endl;
		cout << "\t��� �������������� ��������, � ���-�� ������� � ������ ������ �� ����� ����, " << endl;
		cout << "\t���� ������ ���� ����������." << endl;
		Sleep(700);
		cout << "\n\t�������� ������������ ����� �� �������� ������ �������. ���� ����� ������ ���������" << endl;
		cout << "\t� �������, � ������� ����� �������� �����. ���� �� ��������� � ����������� � �������," << endl;
		cout << "\t����� ����������� ������������� ������� �����." << endl;
		Sleep(700);
		player.setName();
	}
	delete choice;
	if (player.IDLocation == 1) {
		cout << "\t�� ���������� � ������ ���������." << endl;
	}
	else {
		cout << "\t�� ���������� � " << player.getNameLoc() << endl;
	}
	
	 

	while (!player.gameOver) {

		do {
			do {
				switch (player.baseAction()) {
				case 1: { // ��������� ���������
					switch (player.IDLocation) {
					case 1: { // ����� ��������� � ���������
						switch (megatonna.inspectLocat()) {
						case 1: { // ������� � ��������
							cout << "\t����..." << endl;
							Sleep(1000);
							cout << "\n\t-������. � - ������� ������. ������ ���-�� ��� ����������?" << endl;
							cout << "\t� ���� ���� ������ ������ ����, ��� �� ����������!" << endl;
							cout << "\n\t��������:\t1 - ��, �������.\t2 - ���, � ������ ���� ��������." << endl;
							int* choice = new int;
							cin >> *choice;
							if (*choice == 1) {
								player.trade();
							}
							cout << "\t�� ������, ������." << endl;
							Sleep(1000);
							break;
						}
						case 2: { //����� � �������
							cout << "\t����� � �������." << endl;
							Sleep(1500);
							int* pnomHealth = player.getAdrsNomHealth();
							int* phealth = player.getAdrsHealth();
							int* pcaps = player.getAdrsCaps();
							megatonna.market(pcaps, phealth,pnomHealth);
							pnomHealth = NULL;
							phealth = NULL;
							pcaps = NULL;
							break;
						}
						case 3: { // �������� ������� ������
							break;
						}
						}
						break;
					}
					case 2: {// ����� ��������� � �����-����
						switch (rivetcity.inspectLocat()) {
						case 1: { // ����� � �����
							cout << "\t���� � �����" << endl;
							Sleep(1000);
							cout << "\n\t����: -�, ����������. �� ������ ���������� �������� ����������?" << endl;
							cout << "\t���� ������ �������. ����, �����������!" << endl;
							cout << "\n\t��������:\t1 - ����� �����.\t2 - ���, �������. ���� � ��� ����������." << endl;
							int* choice = new int;
							cin >> *choice;
							if (*choice == 1) {
								string* pweapon = player.getAdrsWeapon();
								int* parmor = player.getAdrsArmor();
								int* pdamage = player.getAdrsDamage();
								int* pcaps = player.getAdrsCaps();
								int* pnomArmor = player.getAdrsNomArmor();
								rivetcity.outfit(pcaps, pdamage, parmor, pnomArmor, pweapon);
								pweapon = NULL;
								parmor = NULL;
								pdamage = NULL;
								pcaps = NULL;
								pnomArmor = NULL;
							}
							cout << "\t�� �������, ����� ��� ��������!" << endl;
							Sleep(1000);
							break;
						}
						case 2: { // �������
							cout << "\t����� � �������." << endl;
							Sleep(1500);
							int* pnomHealth = player.getAdrsNomHealth();
							int* phealth = player.getAdrsHealth();
							int* pcaps = player.getAdrsCaps();		
							rivetcity.market(pcaps, phealth, pnomHealth);
							pnomHealth = NULL;
							phealth = NULL;
							pcaps = NULL;
							break;
						}
						case 3: { // ������ ����
							break;
						}
						}
						break;
					}
					case 3: {// ����� ���������� � ������� �������� �����
						switch (broShelter.inspectLocat()) {
						case 1: {//����� ������ ����������
							string* pweapon = player.getAdrsWeapon();
							int* parmor = player.getAdrsArmor();
							int* pdamage = player.getAdrsDamage();
							int* pcaps = player.getAdrsCaps();
							int* pnomArmor = player.getAdrsNomArmor();
							broShelter.outfit(pcaps, pdamage, parmor, pnomArmor, pweapon);
							pweapon = NULL;
							parmor = NULL;
							pdamage = NULL;
							pcaps = NULL;
							pnomArmor = NULL;
							break;
						}
						case 2: {
							int* pcaps = player.getAdrsCaps();
							int* phealth = player.getAdrsHealth();
							int* pnomHealth = player.getAdrsNomHealth();
							broShelter.hospital(pcaps, phealth, pnomHealth);
							pcaps = NULL;
							phealth = NULL;
							pnomHealth = NULL;
							break;
						}
						case 3: {
							if (player.lvl > 2) {
								cout << "\n\t���� � ������ �������." << endl;
								player.setTkMchTime();
								player.setTake();
							}
							else {
								cout << "\n\t� ��� ������������ ����� � ������ ��� ����, ����� ��������� ������." << endl;
							}
							break;
						}
						case 4: {
							break;
						}
						}
						break;
					}
					}
					break;
				}
				case 2: { // ������� �����
					player.travel();
					break;
				}
				case 3: { // ������� ���� ���������
					player.fullState();
					break;
				}
				case 4: {
						cout << "\n\t��������� ����?" << endl;
						cout << "\t1 - ���������.\t2 - ������." << endl;
						int* choice = new int;
						cin >> *choice;
						if (*choice == 1) {
							ofstream fout;
							fout.open("saveGame.txt"); //������
							if (!fout.is_open()) {
								cout << "\t������ �������� ����� ��� ����������." << endl;
							}
							else {
								fout.write((char*)&player, sizeof(Player));
								Sleep(700);
								cout << "\t���������� ���������." << endl;
							}
							fout.close();
						}
						delete choice;
						break;
				}
				}
			} while (player.getTake() == 0); // �������� �������� �������
			player.setDefTake();


			if (!player.getTkMchTime()) {
				int* choice2 = new int;
				do {
					enemy.defaultWeapon();
					Sleep(700);
					createEnemy(&enemy);
					if (player.getDamage() <= enemy.getArmor()) {
						cout << "\t��������!!! ��������� ����� ������� ������� ������������� �����." << endl;
						cout << "\t�� �� ������� ������� ���������� ����. ������������� �������� ���." << endl;
					}

					cout << "\t1 - �������� � ���		2 - �������" << endl;
					int* choice = new int;
					cin >> *choice;
					switch (*choice) {
					case 1: {
						delete choice;
						cout << "\t�� �������� � ���" << endl;
						int* healthEn = new int;
						int* damageEn = new int;
						int* armorEn = new int;
						int* weaponEn = new int;
						getArgum(&enemy, healthEn, armorEn, damageEn, weaponEn);

						if (player.fight(*healthEn, *armorEn, *damageEn) == true) {
							Sleep(200);
							cout << "\t�� �������� ����������" << endl << endl;
							Sleep(200);
							cout << "\t+" << *healthEn << " ����� �����." << endl;
							player.setPoints(*healthEn);
							Sleep(200);
							cout << "\t��� ������ ���� ���������� �� ����� ";
							int* randFig = new int;
							*randFig = rand() % 20;
							cout << *randFig << " ������." << endl;
							Sleep(200);
							player.setCaps(*randFig);
							delete randFig;
							switch (*weaponEn) {
							case 1: {
								cout << "\t�� ������� � �������� ������ ����." << endl;
								player.addWeapon(*weaponEn);
								break;
							}
							case 2: {
								cout << "\t�� ������� � �������� ������ ��������." << endl;
								player.addWeapon(*weaponEn);
								break;
							}
							case 3: {
								cout << "\t�� ������� � �������� ������ �������." << endl;
								player.addWeapon(*weaponEn);
								break;
							}
							case 4: {
								cout << "\t�� ������� � �������� ������ �������." << endl;
								player.addWeapon(*weaponEn);
								break;
							}
							case 0: {
								break;
							}
							}
							Sleep(200);
							if (player.getPoints() >= player.getLimPoints()) {
								player.lvlUp();
								player.setLimPoints();
								cout << "\t�� ������� �� ��������� �������. ���� �������������� ����������." << endl;
							}
							player.getStats();
						}
						else {
							cout << "\t" << player.getName() << " ����� � ��������." << endl;
							player.alive = false;
						}
						delete healthEn;
						delete damageEn;
						delete armorEn;
						delete weaponEn;
						break;
					}
					case 2: {
						delete choice;
						cout << "\t�� ��������..." << endl;
						Sleep(1000);

						int* randFig = new int;
						*randFig = rand() % 3;
						player.setHealth(player.getHealth() - (*randFig) * (enemy.getDamage()));
						cout << "\n\t��� ������� ���� " << ((*randFig) * (enemy.getDamage())) << endl;
						delete randFig;
						Sleep(1000);
						if (player.getHealth() <= 0) {
							cout << "\t" << player.getName() << " ����� ��� �������." << endl;
							player.alive = false;
						}
						else {
							cout << "\t�� �������" << endl << endl;
							player.getStats();
						}
						break;
					}
					}

					if (player.alive) {
						cout << "\t1 - ����� �� ������ ������\t2 - ���������� ���� � " << player.getNameLoc() << endl;

						cin >> *choice2;
						if (*choice2 == 2) {
							cout << "\n\t����� ������..." << endl;
							Sleep(2000);
							cout << "\n\t�� ������ � " << player.getNameLoc() << endl;

						}
					}
				} while (*choice2 == 1 && player.alive == true);
				delete choice2;
			}
		} while (player.takeMachinTime == false && player.alive == true);


		if (player.alive) {
			Sleep(1500);
			cout << "\n\t�� ����� ������ �������." << endl;
			Sleep(1500);
			cout << "\n\t�� ��������� �� ���������." << endl;
			Sleep(1500);
			cout << "\n\t�� ��������� ������ ������� � ����������� � �������." << endl;
			int* i = new int(0);
			for (; *i < 200; *i = *i + 1) {
				cout << " ~";
				Sleep(1);
			}
			delete i;

			cout << "\n\n\t* ���������� � ������� �� ������������� ������� �����.   *" << endl;
			cout << "\t* ������ �� ����� ����� �� ����� � ��� ������� ��������.*" << endl;
			cout << "\t* � ������� - ���� ������ ����...                        *" << endl;
			cout << "\n\t\tGAME OVER\tGAME OVER\tGAME OVER" << endl << endl;
			player.gameOver = true;
		}
	}
	return 0;
}

