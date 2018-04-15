#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "fun.h"

int main(int argc, char const *argv[])
{
	welcome();

	const unsigned int nameLength = 20;
	const std::string characterName = getPlayerName(nameLength);

	const char attributeNames[][20] = {{"Physical attack"}, {"Physical deffence"}, {"Magical attack"}, {"Magical deffence"}, {"Health"}};
	int attributes[5] = {0};

	createCharacter(attributeNames, attributes, &characterName);
	Info();

	int monsterAttributes[5] = {3, 2, 3, 2, 10};
	int monsterLvl = 0;
	std::vector < std::vector<int> > defeatedMonsters;

		while(true){

		randomizeMonster(monsterAttributes);
		bool duelResult = duel(attributeNames, attributes, &characterName, monsterAttributes);

		if(duelResult){
			addTrophyToVector(monsterAttributes, defeatedMonsters);
			monsterLvl++;
		}
		else{
			printLastMonsterAttributes(attributeNames, monsterAttributes, monsterLvl);
			std::cout <<"\n";
			printCurrentCharacterStatistics(attributeNames, attributes, &characterName);
			std::cout <<"\n";
			showTrophyCollection(defeatedMonsters);
			break;
		}
	}

	return 0;
}