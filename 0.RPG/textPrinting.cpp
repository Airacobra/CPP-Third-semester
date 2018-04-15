#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include "rpg.h"

void welcomingText(const unsigned int maxNameLength)
{
	std::cout << "Witaj w mojej grze!\nZanim zaczniemy, zalecam zmaksymalizowanie okna terminalu." << std::endl;
	std::cout << "Na poczatek wybierz imie dla swojej postaci (do " << maxNameLength << " znakow): ";
}

void distributionInfo()
{
	std::cout << "Teraz przejdziemy do rozdysponowania punktow umiejetnosci Twojej postaci pomiedzy:\n";
	std::cout << "-atak fizyczny\n-obrona fizyczna\n-atak magiczny\n-obrona magiczna\n";
	std::cout << "Mozesz je rozdzielic zupelnie dowolnie. Kazdy niewydany punkt zwieksza maksymalny poziom zdrowia o 2.\n";
	std::cout << "Bazowe wartosci powyzszych atrybutow to 1, bazowa wartosc punktow zycia to 2.\n";
	pressToContinue();
}

void printCurrentStatistics(const char attributeNames[][20], int* attributes, const std::string* name)
{
	clearScreen();

	std::string partOfUpperRow = "###########";
	std::string upperRow = partOfUpperRow + " Twoje statystyki " + partOfUpperRow;
	std::string lowerRow(40, '#');
	std::string nameRowBlankSpaces(24 - (*name).size(), ' ');

	std::cout << upperRow << std::endl;
	std::cout << "# Imie postaci" << nameRowBlankSpaces << *name << " #" << std::endl;

	for(int i = 0; i < 5; ++i){
		std::string tempName = attributeNames[i];
		char buffer[20];
		sprintf(buffer, "%d", attributes[i]);
		std::string tempValue = buffer;
		std::string blankSpaces(36 - tempName.size() - tempValue.size(), ' ');
		std::cout << "# " << attributeNames[i] << blankSpaces << *(attributes + i) << " #" << std::endl;
	}

	std::cout << lowerRow << std::endl;
}

void firstFightInfo()
{
	std::cout << "Twoja postac jest gotowa do walki!\nZanim zmierzysz sie z realnymi przeciwnikami, mozesz uruchomic symulacje pojedynku." << std::endl;
	std::cout << "Aby to zrobic, nacisnij 'y', aby pominac symulacje - dowolny klawisz poza 'y'" << std::endl;
}

void tutorialInfo()
{
	std::cout << "Witaj w walce symulacyjnej!" << std::endl;
	std::cout << "Twoim przeciwnikiem bedzie slaba jednostka treningowa o 10 punktach zycia." << std::endl;
	std::cout << "Pojedynek wygrywa strona, ktora pierwsza sprowadzi zdrowie przeciwnika do zera." << std::endl;
	std::cout << "Z racji na symulacyjny typ rozgrywki, Twoja ewentualna przegrana nie bedzie miala negatywnych skutkow." << std::endl;
	std::cout << "W czasie walki mozesz dokonac wyboru miedzy rodzajem wyprowadzanego ataku." << std::endl;
	pressToContinue();
}

void realGameInfo()
{	
	clearScreen();
	std::cout << "Zaczynamy rozgrywke!" << std::endl;
	std::cout << "Gra polega na odpieraniu atakow coraz silniejszych przeciwnikow." << std::endl;
	std::cout << "Strona, ktora pierwsza sprowadzi punkty zycia wroga do zera, wygrywa." << std::endl;
	std::cout << "Twoje zwyciestwa nagradzane sa dodatkowymi punktami umiejetnosci." << std::endl;
	pressToContinue();

	clearScreen();
	std::cout << "Zbliza sie Twoj pierwszy przeciwnik!" << std::endl;
}

void printLastEnemyStatistics(const char attributeNames[][20], int* enemyAttributes, int enemyID)
{
	std::string partOfUpperRow = "##########";
	std::string upperRow = partOfUpperRow + " Ostatni przeciwnik " + partOfUpperRow;
	std::string lowerRow(40, '#');

	char buffer[20];
	sprintf(buffer, "%d", enemyID);
	std::string enemyidAsString = buffer;

	std::string IDRowBlankSpaces(22 - enemyidAsString.size(), ' ');

	std::cout << upperRow << std::endl;
	std::cout << "# ID przeciwnika" << IDRowBlankSpaces << enemyID << " #" << std::endl;

	for(int i = 0; i < 5; ++i){
		std::string tempName = attributeNames[i];
		sprintf(buffer, "%d", enemyAttributes[i]);
		std::string tempValue = buffer;
		std::string blankSpaces(36 - tempName.size() - tempValue.size(), ' ');
		std::cout << "# " << attributeNames[i] << blankSpaces << enemyAttributes[i] << " #" << std::endl;
	}

	std::cout << lowerRow << std::endl;
}

void printAllDefeatedEnemies(const std::vector< std::vector<int> >& listOfDefeatedEnemies)
{
	std::string tableRows(40, '=');
	
	std::cout << std::endl << "         Pokonani przeciwnicy           " << std::endl;
	std::cout << tableRows << std::endl;
	std::cout << "  Atak   Obrona   Atak   Obrona  Zycie  " << std::endl;
	std::cout << "  fiz.    fiz.    mag.    mag.    (HP)  " << std::endl;
	std::cout << tableRows << std::endl;

	for(std::vector< std::vector<int> >::size_type i = 0; i < listOfDefeatedEnemies.size(); ++i){
		for(std::vector<int>::size_type j = 0; j < listOfDefeatedEnemies[i].size(); ++j){
			std::cout << "   " << listOfDefeatedEnemies[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}
