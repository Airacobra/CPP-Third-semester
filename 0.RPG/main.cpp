#include <iostream>
#include <string>
#include <vector>
#include "rpg.h"

int main()
{
	clearScreen();

	const unsigned int maxNameLength = 20;
	welcomingText(maxNameLength);
	const std::string characterName = getName(maxNameLength);

	clearScreen();

	const char attributeNames[][20] = {{"Atak fizyczny"}, {"Obrona fizyczna"}, {"Atak magiczny"}, {"Obrona magiczna"}, {"Punkty zycia"}};
	int attributes[5] = {1, 1, 1, 1, 2};

	distributionInfo();

	attributesManagement(attributeNames, attributes, &characterName);

	firstFightInfo();

	int fakeEnemy[5] = {1, 3, 1, 3, 10};

	bool simulateFirstFight = launchTutorial();

	if(simulateFirstFight)
		fightSimulation(attributeNames, attributes, &characterName, fakeEnemy, simulateFirstFight);

	simulateFirstFight = false;

	realGameInfo();

	int enemyAttributes[5] = {1, 1, 1, 1, 10};
	int enemyID = 1;

	std::vector< std::vector<int> > listOfDefeatedEnemies;


	while(true){

		randomizeEnemyAttributes(enemyAttributes);
		bool victory = fightSimulation(attributeNames, attributes, &characterName, enemyAttributes, simulateFirstFight);

		if(victory){
			addEnemyToTheList(enemyAttributes, listOfDefeatedEnemies);
			enemyID++;
		}else{
			addEnemyToTheList(enemyAttributes, listOfDefeatedEnemies);
			printCurrentStatistics(attributeNames, attributes, &characterName);
			std::cout << std::endl;
			printLastEnemyStatistics(attributeNames, enemyAttributes, enemyID);
			std::cout << std::endl;
			printAllDefeatedEnemies(listOfDefeatedEnemies);
			break;
		}
	}

	return 0;
}