#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "rpg.h"

void clearScreen()
{
	std::system("clear");
}

std::string getName(const unsigned int maxLength)
{
	std::string name;
	bool incorrectName = true;

	while(incorrectName){

		std::getline(std::cin, name);

		if(name.size() > maxLength){
			std::cout << "Zbyt dluga nazwa, sprobuj ponownie: ";
		}else{
			incorrectName = false;
		}

	}

	return name;
}

void pressToContinue()
{
	std::cout << "(nacisnij dowolny klawisz i ENTER, aby kontynuowac...)";
	char buffer[100];
	std::cin >> buffer;
	clearScreen();
}

void distributeSkillPoints(const char attributeNames[][20], int* attributes)
{
	std::cout << "Przydziel 20 punktow wpisujac wartosc o jaka chcesz powiekszyc dany atrybut (wprowadz wylacznie liczby!):\n";

	int assignedNumber, remainingPoints = 20;
	bool wrongInput = true;

	for(int i = 0; i < 4; ++i){

		std::cout << attributeNames[i] << ": ";

		while(wrongInput){

			std::cin >> assignedNumber;

			if(assignedNumber <= remainingPoints && assignedNumber >= 0){
				wrongInput = false;
			}else{
				std::cout << "Nieprawidlowa wartosc, sprobuj ponownie: ";
			}

		}

		wrongInput = true;
		remainingPoints -= assignedNumber;
		*(attributes + i) += assignedNumber;
	}

	*(attributes + 4) += remainingPoints * 2;

}

void attributesManagement(const char attributeNames[][20], int* attributes, const std::string* name)
{
	bool tryAgain = true;

	while(tryAgain){
		
		distributeSkillPoints(attributeNames, attributes);
		printCurrentStatistics(attributeNames, attributes, name);

		std::cout << "Jesli chcesz rozdac punkty ponownie, nacisnij 'y', w przeciwnym wypadku nacisnij dowolny klawisz: ";
		char buffer[100];
		std::cin >> buffer;

		if(buffer[0] != 'y' && buffer[0] != 'Y'){
			tryAgain = false;
		}else{
			attributes[0] = attributes[1] = attributes[2] = attributes[3] = 1;
			attributes[4] = 2;
		}

		clearScreen();	
	}
}

bool launchTutorial()
{
	char buffer[100];
	std::cin >> buffer;

	if(buffer[0] == 'y' || buffer[0] == 'Y'){
		return true;
	}else{
		return false;
	}
}

bool fightSimulation(const char attributeNames[][20], int* attributes, const std::string* name, int* enemyAttributes, bool simulate)
{
	clearScreen();

	if(simulate)
		tutorialInfo();

	int currentUserHealth = attributes[4];
	int currentEnemyHealth = enemyAttributes[4];

	int roundCounter = 1;

	while(true){

		std::cout << "Runda " << roundCounter << std::endl;
		std::cout << "Wybierz rodzaj ataku (1-fizyczny, 2-magiczny): ";

		int userAttackType;
		std::cin >> userAttackType;

		switch(userAttackType){
			case 1:	 currentEnemyHealth -= attackResult(attributes[0], enemyAttributes[1]);
					 std::cout << "Wybierasz atak fizyczny, przeciwnikowi pozostalo " << currentEnemyHealth << " HP." << std::endl;
					 break;
			case 2:  currentEnemyHealth -= attackResult(attributes[2], enemyAttributes[3]);
					 std::cout << "Wybierasz atak magiczny, przeciwnikowi pozostalo " << currentEnemyHealth << " HP." << std::endl;
					 break;
			default: std::cout << "Dostepne opcje to 1 i 2, tracisz mozliwosc ataku." << std::endl;
					 break;
		}

		if(currentEnemyHealth <= 0){

			std::cout << "Gratulacje, wygrales!" << std::endl;
			pressToContinue();

			if(!simulate)
				addSkillPoint(attributeNames, attributes, name);

			clearScreen();

			if(!simulate){
				printCurrentStatistics(attributeNames, attributes, name);
				pressToContinue();
			}

			return true;
		}

		int enemyAttackType = rand()%2 + 1;

		switch(enemyAttackType){
			case 1:	 currentUserHealth -= attackResult(enemyAttributes[0], attributes[1]);
					 std::cout << "Przeciwnik wybiera atak fizyczny, pozostalo Ci " << currentUserHealth << " HP." << std::endl;
					 break;
			case 2:  currentUserHealth -= attackResult(enemyAttributes[2], attributes[3]);
					 std::cout << "Przeciwnik wybiera atak magiczny, pozostalo Ci " << currentUserHealth << " HP." << std::endl;
					 break;
		}


		if(currentUserHealth <= 0){

			if(simulate){
				std::cout << "Straciles wszystkie punkty zycia, koniec symulacji." << std::endl;
			}else{
				std::cout << "Straciles wszystkie punkty zycia, koniec gry." << std::endl;
			}

			return false;
		}

		std::cout << std::endl;

		roundCounter++;
	}
	
}

int attackResult(int attack, int defense)
{
	return (attack * attack) / (attack + defense);
}

void addSkillPoint(const char attributeNames[][20], int* attributes, const std::string* name)
{
	printCurrentStatistics(attributeNames, attributes, name);
	std::cout << std::endl;
	std::cout << "Wybierz atrybut, ktory powiekszysz o 1 (punkty zycia o 2):" << std::endl;
	std::cout << "1-atak fizyczny\n2-obrona fizyczna\n3-atak magiczny\n4-obrona magiczna\n5-punkty zycia" << std::endl;
	std::cout << "(wprowadzenie innych wartosci skutkuje utrata punktu)" << std::endl;

	int choice;
	std::cin >> choice;

	switch(choice){
		case 1:	attributes[0] += 1;
				break;
		case 2: attributes[1] += 1;
				break;
		case 3: attributes[2] += 1;
				break;
		case 4: attributes[3] += 1;
				break;
		case 5: attributes[4] += 2;
				break;
	}

}

void randomizeEnemyAttributes(int* enemyAttributes)
{

	for(int i = 0; i < 4; ++i){

		enemyAttributes[i] += rand()%3;
	}

	enemyAttributes[4] += 1;
}

void addEnemyToTheList(int* enemyAttributes, std::vector< std::vector<int> > &listOfDefeatedEnemies)
{
	std::vector<int> temporaryVector;

	for(std::vector<int>::size_type i = 0; i < 5; ++i)
		temporaryVector.push_back(enemyAttributes[i]);

	listOfDefeatedEnemies.push_back(temporaryVector);
}
