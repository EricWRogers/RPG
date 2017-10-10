#include <iostream>
#include <fstream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;



class Player {
public:
	int timeTraveling = 0;
	int time = 6;
	int day = 0;
	//player stats
	int health = 0;
	int mHealth = 0;
	int magic = 0;
	int attack = 0;
	int stealth = 0;
	int gold = 0;
	int food = 0;
	int is = 1;
	int mStamina = 24;
	int stamina = 15;
	char playerName[50];
	//inventory
	int hog = 0;

	void setStats(int a, int h, int mH, int g, int f, int j, int s, int m) {
		attack = a; health = h; mHealth = mH; gold = g; food = f; stamina = j; stealth = s; magic = m;
	}
	void getStats() {
		cout << playerName << "'s " /*<< "Doing " << state[is] */<< " Gold: " << gold << " Food: " << food << " Stamina: " << stamina <<endl;
		cout <<"Attack: " << attack << " Magic: " << magic << " Health: " << health << " Stealth: " << stealth << endl;
		//SaveFile
		saveFile();
		//gameStart();
	}
	void saveFile() {
		ofstream psf;
		psf.open("playerSaveFile.dat");
		psf << playerName << endl;
		psf << attack << endl;
		psf << health << endl;
		psf << stamina << endl;
		psf << mStamina << endl;
		psf << magic << endl;
		psf << stealth << endl;
		psf << gold << endl;
		psf << food << endl;
		psf << is << endl;
		//inventory
		psf << hog << endl;

		psf.close();
	}
	void loadSave() {
		ifstream psf;
		psf.open("playerSaveFile.dat");
		psf >> playerName;
		cout << playerName << endl;
		psf >> attack;
		cout << attack << endl;
		psf >> health;
		cout << health << endl;
		psf >> stamina;
		cout << stamina << endl;
		psf >> mStamina;
		cout << mStamina << endl;
		psf >> magic;
		cout << magic << endl;
		psf >> stealth;
		cout << stealth << endl;
		psf >> gold;
		cout << gold << endl;
		psf >> food;
		cout << food << endl;
		psf >> is;
		cout << is << endl;
		//inventory
		psf >> hog;
		cout << hog << endl;


		psf.close();
	}
	void updateMoney(int m) {
		gold = gold + m;
	}
	void updateMagic(int m) {
		magic = magic + m;
	}
	void updateHealth(int h) {
		health = health + h;
	}
	void resetHealth() {
		health = mHealth;
	}
	void updateMaxHealth(int h) {
		mHealth = mHealth + h;
	}
	void updateAttack(int a) {
		attack = attack + a;
	}
	void updateFood(int f) {
		food = food + f;
	}
	void updateStamina(int j) {
		stamina = stamina + j;
	}
	void resetStamina(){
        stamina = mStamina;
	}
	void updatemStamina(int j) {
		mStamina = mStamina + j;
	}

};
class townLoop {
public:
};
class forestLoop {

};
class shop {

};
class inn {

};
int rollDice(int max, int min) {
	int dice;
	dice = rand() % (max - min + 1) + 1;
	cout << dice << endl;
	return dice;
}
int main() {
	srand(time(NULL));
	Player p;
	char r;
	bool game = true;
	int dTaken;
	int diceRoll;
	int goldRoll;
	int runRoll;
    //Startup
	cout << "Would you like to play a game? New: (1) or continue: (2) " << endl;cin >> r;
	if (r == '2') {
		p.loadSave();
	}
	//int a, int h, int g, int f, int j, int s, int m,
	else {
		cout << "Please enter your name: ";cin >> p.playerName;
		cout << "|Charater select| Warrior: (1) Elf: (2) Mage: (3) " << endl;cin >> r;
		if (r == '1') {p.setStats(5, 20, 20, 0, 0, 1, 3, 3);p.getStats();}
		else if (r == '2') {p.setStats(7, 15, 15, 0, 0, 3, 7, 5);p.getStats();}
		else if (r == '3') {p.setStats(3, 10, 10, 0, 0, 2, 3, 7);p.getStats();
		}
	}
	while (p.health > 0) {
		//getchar();
		//Traveling(0)Town(1)Shop(2)Food Market(3) inn(4)
		cout << "Day: " << p.day << "Time: " << p.time << ":00 " << endl;
		//Hud
		while (p.is == 0) {
			cout << "|"<< p.playerName<<"'s text based adventure|\n Travel: (1)\n Eat and Rest: (2)\n Setup Camp: (3)" << endl; cin >> r;
			switch (r) {
			case('1'):
				p.is = 1;
				break;
			case('2'):

				break;
			default:

				break;
			}
		}
		//Traveling
		while (p.is == 1) {
			diceRoll = rollDice(20, 1);
			switch (diceRoll) {
			case 20:
				goldRoll = rollDice(20, 10);
				cout << "Found " << diceRoll << " Gold!!!!" << endl;
				p.updateMoney(diceRoll);
				p.getStats();
				break;
			case 18:
				cout << "You found a town!!!!" << endl;
				p.is = 2;
				break;
			case 16:
				break;
			case 14:
				diceRoll = rollDice(3, 1);
				cout << "Found a chest do you open it? enter y or n : " << endl;
				cin >> r;
				if (r == 'Y') {
					if (diceRoll == 1) {
						goldRoll = rollDice(20, 10);
						cout << "Found " << goldRoll << " Gold!!!!" << endl;
						p.updateMoney(goldRoll);
					}
					else if (diceRoll == 2) {
						cout << "It's A TRAP!!!! -2 Health" << endl;
						p.updateHealth(-2);
					}
					else if (diceRoll == 3) {
						cout << "It's Locked" << endl;
					}
				}
				else if (r == 'N') {
					cout << "Safe choice!!!" << endl;
				}
				else {
					cout << "-1 to health" << endl;
					p.updateHealth(-1);
					p.getStats();
				}
				break;
			case 12:
				// Code
				break;
			case 10:

				break;
			case 8:
				// Code
				break;
			case 6:
				// Code
				break;
			case 4:
				// Code
				break;
			case 2:
				// Code
				break;
			default:
				cout << "O no a wild boar showed up!!!\n Do you run: (1) Or Fight: (2)" << endl; cin >> r;
				//run
				if (r == '1') {
					runRoll = rollDice(10, 7);
					if (runRoll == 3) {
						cout << "You Got away" << endl;
					}
					else {
						dTaken = 10 - (p.stealth + runRoll);
						cout << "You were biten while running loss " << dTaken << " Health!!!!" << endl;
						p.updateHealth(dTaken);
					}
				}
				if(r == '2') {
					if (p.attack > 5 || p.magic > 7) {
						cout << "You Won!!!! Joy +1 Food +1" << endl;
						p.updateFood(+1);
						p.updateStamina(-1);
					}else{
                        cout << "You were hurt badly but you have learned a better way to fight" << endl;
                        p.updateAttack(1);
                        p.updateMagic(1);
                        p.updateHealth(-3);
					}
				}
				break;
			}

			if (p.time <= 24) {
				p.time++;
			}
			if (p.time >= 25) {
				p.time = 0;
				p.day++;
			}
			p.timeTraveling++;
			if (p.timeTraveling == 5) {
				p.timeTraveling = 0;
				p.is = 0;
			}
		}
		//Town
		while (p.is == 2) {
			cout << "|Entered into Town| You may look or a shop: (1) Food Market: (2) inn: (3) or \nPress any key to leave Town" << endl; cin >> r;
			switch (r) {
			case '1':
				p.is = 3;
				break;
			case '2':
				p.is = 4;
				break;
			case '3':
				p.is = 5;
				break;
			default:
				p.is = 1;
				break;
			}
		}
		//Shop
		while (p.is == 3) {
			cout << "\n\n\n\n|Welcome To My Shop| \n +1 to Attack for 10 Gold: (1) \n Fully Restore Health For 20 Gold: (2) \n +1 To Max Health For 40 Gold: (3) \n Sorry I forgot My Money: (4)" << endl; cin >> r;
			switch (r) {
			case '1':
                if(p.gold < 10)
                {
                    cout << "Sorry Sir, you do not have enough gold" << endl;
                    break;
                }
				cout << "(-10 Gold) +1 to Attack" << endl;
				p.updateMoney(-10);
				p.updateAttack(1);
				p.getStats();
				break;
			case '2':
                if(p.gold < 20)
                {
                    cout << "Sorry Sir, you do not have enough gold" << endl;
                    break;
                }
				cout << "(-20 Gold) Healed" << endl;
				p.updateMoney(-20);
				p.resetHealth();
				p.getStats();
				break;
			case '3':
                if(p.gold < 40)
                {
                    cout << "Sorry Sir, you do not have enough gold" << endl;
                    break;
                }
				cout << "(-40 Gold) +1 to Max Health" << endl;
				p.updateMoney(-40);
				p.updateMaxHealth(1);
				p.getStats();
				break;
			default:
				//Back to Town
				p.is = 2;
				break;
			}
			if (p.time <= 24) {
				p.time++;
			}
			if (p.time >= 25) {
				p.time = 0;
				p.day++;
			}
		}
		//Food Market
		while (p.is == 4) {
            p.is = 2;
		}
		//Inn
		while (p.is == 5) {
            cout << "\n\n\n\n|Welcome To My Inn|\n Your stamina: "<< p.stamina <<" \n Stay and rest For 1 gold (1) \n I've rested enough (2)" << endl; cin >> r;
            switch (r){
            case '1':
                if(p.gold < 1)
                {
                    cout << "Sorry Sir, you do not have enough gold" << endl;
                    break;
                }
                cout << "your is maxedout" << endl;
                p.resetStamina();
                break;
                default:
				//Back to Town
				p.is = 2;
				break;
            }
		}
		//Fight
		if (p.time <= 24) {
			p.time++;
		}
		if (p.time >= 25) {
			p.time = 0;
			p.day++;
		}
		//p.getStats();
	}
	cout << "GameOver" << endl;
	getchar();
	return 0;
}
