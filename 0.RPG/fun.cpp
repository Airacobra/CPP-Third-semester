#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "fun.h"

void welcome(){
	std::cout<< "Welcome, what is your name stranger?" <<std::endl;
}

std::string getPlayerName(const unsigned int nameLength)
{
	std::string characterName;
	bool wrongName = true;

	while(wrongName){

		std::getline(std::cin, characterName);

		if(characterName.size() > nameLength){
			std::cout << "Name is to long, try again ";
		}

		else
			wrongName = false;
	}

	return characterName;
}

void createCharacter(const char attributeNames[][20], int* attributes, const std::string* characterName)
{
	std::cout<< "Choose your statistics, "<< *characterName << "." <<std::endl;
	std::cout<< "1-Physical attack, 2-Physical deffence, 3-Magical attack, 4-Magical Deffence, 5-Health"<<std::endl;
	std::cout<< "Write attribute number to gain one point (health - 2 points)"<<std::endl;
	int attribute_number = 0;
	for (int index = 0; index < 20; index++)
	{
		std::cin>> attribute_number;
		switch(attribute_number){
			case 1:
				attributes[0]+=1;
				std::cout<<"Your current physical attack value: "<<attributes[0]<<std::endl;
				break;
			case 2:
				attributes[1]+=1;
				std::cout<<"Your current physical deffence value: "<<attributes[1]<<std::endl;
				break;	
			case 3:
				attributes[2]+=1;
				std::cout<<"Your current magical attack value: "<<attributes[2]<<std::endl;
				break;
			case 4:
				attributes[3]+=1;
				std::cout<<"Your current magical defense value: "<<attributes[3]<<std::endl;
				break;
			case 5:
				attributes[4]+=2;
				std::cout<<"Your health value: "<<attributes[4]<<std::endl;
				break;
			default:
				std::cout<<"Wrong number! "<<*characterName<<" lost one attribute point >:)"<<std::endl;								
		}
	}
	std::cout<<"\nYour current statistics:"<<std::endl;
	for (int index = 0; index < 5; index++)
	{
		std::cout<<attributeNames[index]<< "=" <<attributes[index]<<std::endl;
	}
}

void Info()
{	
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "(Your objetive is to kill monsters by decreasing their health to 0)" << std::endl;
	std::cout << "(You can do that by choosing magical or physical attack)" << std::endl;
	std::cout << "You can hear footsteps of your first enemy\n" << std::endl;

	std::cout << "Oh no! It's a Demogorgon!" << std::endl;
}

void randomizeMonster(int* monsterAttributes)
{
	int randIntiger;
	for(int index = 0; index < 4; index++){

		randIntiger=rand()%5;
		if(randIntiger==4){
			monsterAttributes[4]+=2;
		}
		else{
			monsterAttributes[randIntiger]+=1;
		}
	}	
}

int attackResult(int attacker, int defender)
{
	return (attacker * attacker) / (attacker + defender);
}

void addSkillPoint(const char attributeNames[][20], int* attributes, const std::string* characterName)
{
	std::cout << "Choose your statistic to improve" << std::endl;
	std::cout << "1-Physical attack, 2-Physical deffence, 3-Magical attack, 4-Magical Deffence, 5-Health" << std::endl;

	int attribute_number;
	std::cin >> attribute_number;

	switch(attribute_number){
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
		default:
				std::cout<<"Wrong number! "<<*characterName<<" lost one attribute point >:)"<<std::endl;		
	}

}

bool duel(const char attributeNames[][20], int* attributes, const std::string* characterName, int* monsterAttributes)
{
	int currentCharacterHealth = attributes[4];
	int currentMonsterHealth = monsterAttributes[4];

	while(true){
		
		int monsterAttackType = rand()%2;

		switch(monsterAttackType){
			case 0:	 currentCharacterHealth -= attackResult(monsterAttributes[0], attributes[1]);
					 std::cout << "\nDemogorgon uses his physical attack. Your current health: " << currentCharacterHealth << " HP" << std::endl;
					 break;
			case 1:  currentCharacterHealth -= attackResult(monsterAttributes[2], attributes[3]);
					 std::cout << "\nDemogorgon uses his magical attack. Your current health: " << currentCharacterHealth << " HP" << std::endl;
					 break;
		}


		if(currentCharacterHealth <= 0){
				std::cout << *characterName<<" died!" << std::endl;
				return false;
		}


		int characterAttackType;
		std::cout<<"\nChoose your attack: 1-Physical, 2-Magical"<<std::endl;
		std::cin >> characterAttackType;

		switch(characterAttackType){
			case 1:	 currentMonsterHealth -= attackResult(attributes[0], monsterAttributes[1]);
					 std::cout << "Monster has" << currentMonsterHealth << " HP" << std::endl;
					 break;
			case 2:  currentMonsterHealth -= attackResult(attributes[2], monsterAttributes[3]);
					 std::cout << "Monster has " << currentMonsterHealth << " HP" << std::endl;
					 break;
			default: std::cout << "You panicked, you lost your round" << std::endl;
					 break;
		}

		if(currentMonsterHealth <= 0){

			std::cout << "You killed the beast!" << std::endl;
			addSkillPoint(attributeNames, attributes, characterName);
			std::cout << "---------------------------------" << std::endl;
			std::cout<< "Next monster is charging you!"<<std::endl;

			return true;
		}
	
	}
}

void addTrophyToVector(int* monsterAttributes, std::vector< std::vector<int> > &defeatedMonsters)
{
	std::vector<int> tempVector;

	for(std::vector<int>::size_type i = 0; i < 5; i++){
		tempVector.push_back(monsterAttributes[i]);
	}

	defeatedMonsters.push_back(tempVector);
}

void printCurrentCharacterStatistics(const char attributeNames[][20], int* attributes, const std::string* characterName)
{
	std::string Row = "-----------------";

	std::cout << Row << std::endl;
	std::cout << "Statistics: " <<  *characterName << std::endl;

	for (int index = 0; index < 5; index++)
	{
		std::cout<<attributeNames[index]<< "=" <<attributes[index]<<std::endl;
	}
}

void printLastMonsterAttributes(const char attributeNames[][20], int* monsterAttributes, int monsterLvl)
{
	std::string Row = "-----------------";

	std::cout << Row << std::endl;
	std::cout << "Statistics of last monster: Lvl" << monsterLvl <<std::endl;

	for (int index = 0; index < 5; index++)
	{
		std::cout<<attributeNames[index]<< "=" <<monsterAttributes[index]<<std::endl;
	}
}

void showTrophyCollection(const std::vector< std::vector<int> >& defeatedMonsters)
{
	std::string row(45, '-');
	
	std::cout << std::endl << "         Trophies           " << std::endl;
	std::cout << row << std::endl;
	std::cout << "  Atack   Defence   Atack   Defence  Health  " << std::endl;
	std::cout << "  phi.    phi.      mag.    mag.     HP  " << std::endl;
	std::cout << row << std::endl;

	for(std::vector< std::vector<int> >::size_type i = 0; i < defeatedMonsters.size(); ++i){
		for(std::vector<int>::size_type j = 0; j < defeatedMonsters[i].size(); ++j){
			std::cout << "  " << defeatedMonsters[i][j] << '\t';
		}
	}	
}