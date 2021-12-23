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
	fin.open("saveGame.txt");//Чтение
	if (fin.is_open()) {
		
		cout << "\n\tЗагрузить последнюю сохраненную игру?" << endl;
		cout << "\n\t1 - Загрузить игру.\t2 - Начать новую игру." << endl;
		cout << "\t";
		cin >> *choice;
		if (*choice == 1) {
			fin.read((char*)&player, sizeof(Player));
			Sleep(700);
			cout << "\tЗагрузка игры завершена." << endl;
		}	
		fin.close();
	}
	cout << "\n\t\t\t\t~ ~ ~ Начало игры ~ ~ ~" << endl;
	if (*choice != 1) {
		cout << "\n\t\tПосле ядерной войны планета превратилась в настоящий ад. " << endl;
		cout << "\tПо руинам, которые остались от городов бродят мутанты, повсюду радиация, " << endl;
		cout << "\tа чистой воды и еды практически нет. Оставшиеся на земле люди выживают, как могут." << endl;
		cout << "\t\tКто-то пытается помочь другим людям, кто-то возглавляет большие группировки " << endl;
		cout << "\tдля противостояния мутантам, а кто-то убивает и грабит любого на своем пути, " << endl;
		cout << "\tдабы добыть себе пропитание." << endl;
		Sleep(700);
		cout << "\n\tПрогресс человечества дошел до создания машины времени. Одна такая машина находится" << endl;
		cout << "\tв Убежище, в котором живет Братство Стали. Если ее запустить и отправиться в прошлое," << endl;
		cout << "\tможно попробовать предотвратить ядерную войну." << endl;
		Sleep(700);
		player.setName();
	}
	delete choice;
	if (player.IDLocation == 1) {
		cout << "\tВы находитесь в городе Мегатонна." << endl;
	}
	else {
		cout << "\tВы находитесь в " << player.getNameLoc() << endl;
	}
	
	 

	while (!player.gameOver) {

		do {
			do {
				switch (player.baseAction()) {
				case 1: { // Осмотреть местность
					switch (player.IDLocation) {
					case 1: { // Когда находится в Мегатонне
						switch (megatonna.inspectLocat()) {
						case 1: { // Подойти к человеку
							cout << "\tИдем..." << endl;
							Sleep(1000);
							cout << "\n\t-Привет. Я - местный барыга. Хочешь что-то мне предложить?" << endl;
							cout << "\tУ меня есть крышки взамен тому, что ты предложишь!" << endl;
							cout << "\n\tОтветить:\t1 - Да, пожалуй.\t2 - Нет, я просто мимо проходил." << endl;
							int* choice = new int;
							cin >> *choice;
							if (*choice == 1) {
								player.trade();
							}
							cout << "\tНу прощай, путник." << endl;
							Sleep(1000);
							break;
						}
						case 2: { //Пойти в магазин
							cout << "\tПошли в магазин." << endl;
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
						case 3: { // Заняться другими делами
							break;
						}
						}
						break;
					}
					case 2: {// Когда находится в Ривет-Сити
						switch (rivetcity.inspectLocat()) {
						case 1: { // Зайти к Стену
							cout << "\tИдем к Стену" << endl;
							Sleep(1000);
							cout << "\n\tСтен: -О, здравствуй. Не хочешь приобрести отличные снаряжение?" << endl;
							cout << "\tЦены просто смешные. Бери, непожалеешь!" << endl;
							cout << "\n\tОтветить:\t1 - Давай гляну.\t2 - Нет, спасибо. Меня и моя устраивает." << endl;
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
							cout << "\tДо встречи, может еще увидимся!" << endl;
							Sleep(1000);
							break;
						}
						case 2: { // Магазин
							cout << "\tПошли в магазин." << endl;
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
						case 3: { // Другие дела
							break;
						}
						}
						break;
					}
					case 3: {// Когда находишься в убежище Братства Стали
						switch (broShelter.inspectLocat()) {
						case 1: {//пункт выдачи снаряжения
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
								cout << "\n\tИдем к машине времени." << endl;
								player.setTkMchTime();
								player.setTake();
							}
							else {
								cout << "\n\tУ вас недостаточно опыта и уровня для того, чтобы запустить машину." << endl;
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
				case 2: { // Достать карту
					player.travel();
					break;
				}
				case 3: { // Оценить свое состояние
					player.fullState();
					break;
				}
				case 4: {
						cout << "\n\tСохранить игру?" << endl;
						cout << "\t1 - Сохранить.\t2 - Отмена." << endl;
						int* choice = new int;
						cin >> *choice;
						if (*choice == 1) {
							ofstream fout;
							fout.open("saveGame.txt"); //Запись
							if (!fout.is_open()) {
								cout << "\tОшибка открытия файла для сохранения." << endl;
							}
							else {
								fout.write((char*)&player, sizeof(Player));
								Sleep(700);
								cout << "\tСохранение завершено." << endl;
							}
							fout.close();
						}
						delete choice;
						break;
				}
				}
			} while (player.getTake() == 0); // Проверка принятия решения
			player.setDefTake();


			if (!player.getTkMchTime()) {
				int* choice2 = new int;
				do {
					enemy.defaultWeapon();
					Sleep(700);
					createEnemy(&enemy);
					if (player.getDamage() <= enemy.getArmor()) {
						cout << "\tВНИМАНИЕ!!! Противник имеет высокий уровень сопротивления урону." << endl;
						cout << "\tВы не сможете нанести противнику урон. Рекомендуется избежать боя." << endl;
					}

					cout << "\t1 - Вступить в бой		2 - Сбежать" << endl;
					int* choice = new int;
					cin >> *choice;
					switch (*choice) {
					case 1: {
						delete choice;
						cout << "\tВы вступили в бой" << endl;
						int* healthEn = new int;
						int* damageEn = new int;
						int* armorEn = new int;
						int* weaponEn = new int;
						getArgum(&enemy, healthEn, armorEn, damageEn, weaponEn);

						if (player.fight(*healthEn, *armorEn, *damageEn) == true) {
							Sleep(200);
							cout << "\tВы победили противника" << endl << endl;
							Sleep(200);
							cout << "\t+" << *healthEn << " очков опыта." << endl;
							player.setPoints(*healthEn);
							Sleep(200);
							cout << "\tПри обыске тела противника вы нашли ";
							int* randFig = new int;
							*randFig = rand() % 20;
							cout << *randFig << " крышек." << endl;
							Sleep(200);
							player.setCaps(*randFig);
							delete randFig;
							switch (*weaponEn) {
							case 1: {
								cout << "\tВы забрали в качестве трофея биту." << endl;
								player.addWeapon(*weaponEn);
								break;
							}
							case 2: {
								cout << "\tВы забрали в качестве трофея пистолет." << endl;
								player.addWeapon(*weaponEn);
								break;
							}
							case 3: {
								cout << "\tВы забрали в качестве трофея автомат." << endl;
								player.addWeapon(*weaponEn);
								break;
							}
							case 4: {
								cout << "\tВы забрали в качестве трофея пулемет." << endl;
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
								cout << "\tВы перешли на следующий уровень. Ваши характеристики повысились." << endl;
							}
							player.getStats();
						}
						else {
							cout << "\t" << player.getName() << " погиб в сражении." << endl;
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
						cout << "\tВы убегаете..." << endl;
						Sleep(1000);

						int* randFig = new int;
						*randFig = rand() % 3;
						player.setHealth(player.getHealth() - (*randFig) * (enemy.getDamage()));
						cout << "\n\tВам нанесли урон " << ((*randFig) * (enemy.getDamage())) << endl;
						delete randFig;
						Sleep(1000);
						if (player.getHealth() <= 0) {
							cout << "\t" << player.getName() << " погиб при бегстве." << endl;
							player.alive = false;
						}
						else {
							cout << "\tВы сбежали" << endl << endl;
							player.getStats();
						}
						break;
					}
					}

					if (player.alive) {
						cout << "\t1 - Пойти на поиски врагов\t2 - Продолжить идти в " << player.getNameLoc() << endl;

						cin >> *choice2;
						if (*choice2 == 2) {
							cout << "\n\tПошли дальше..." << endl;
							Sleep(2000);
							cout << "\n\tВы пришли в " << player.getNameLoc() << endl;

						}
					}
				} while (*choice2 == 1 && player.alive == true);
				delete choice2;
			}
		} while (player.takeMachinTime == false && player.alive == true);


		if (player.alive) {
			Sleep(1500);
			cout << "\n\tВы нашли машину времени." << endl;
			Sleep(1500);
			cout << "\n\tВы пытаетесь ее запустить." << endl;
			Sleep(1500);
			cout << "\n\tВы запустили машину времени и перенеслись в прошлое." << endl;
			int* i = new int(0);
			for (; *i < 200; *i = *i + 1) {
				cout << " ~";
				Sleep(1);
			}
			delete i;

			cout << "\n\n\t* Вернувшись в прошлое вы предотвратили ядерную войну.   *" << endl;
			cout << "\t* Теперь на земле вновь всё живет и нет никакой радиации.*" << endl;
			cout << "\t* А главное - есть чистая вода...                        *" << endl;
			cout << "\n\t\tGAME OVER\tGAME OVER\tGAME OVER" << endl << endl;
			player.gameOver = true;
		}
	}
	return 0;
}

