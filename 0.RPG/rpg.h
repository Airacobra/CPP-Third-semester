#ifndef RPG_H
#define RPG_H

//	Tekst powitalny, informuje o maksymalnej dlugosci nazwy postaci.
void welcomingText(const unsigned int);

//	Czysci okno terminalu.
void clearScreen();

//	Informacje o atrybutach postaci i zasadach podzialu punktow umiejetnosci.
void distributionInfo();

//	Oczekuje na wejscie od uzytkownika i czysci okno terminalu. Posiada tablice
//	buffer, zabezpieczajaca przed efektami wprowadzenia wiecej niz 1 znaku.
void pressToContinue();

//	Informacja o gotowosci do walki i mozliwosci uruchomienia symulacji.
void firstFightInfo();

//	Rozdawanie startowych 20 punktow umiejetnosci. Funkcja niezabezpieczona
//	przed efektami wprowadzenia znakow innych niz liczbowe (0-9).
void distributeSkillPoints(const char [][20], int*);

//	Wypisanie obecnych statystyk bohatera w ramce.
void printCurrentStatistics(const char [][20], int*, const std::string*);

//	Wywoluje funkcje rozdajaca startowe 20 punktow, nastepnie wyswietla obecne
//	statystyki i daje mozliwosc ponownego przydzialu startowych punktow.
void attributesManagement(const char [][20], int*, const std::string*);

//	Wypisuje obecne statystyki i daje mozliwosc przydzielenia 1 punktu umiejetnosci.
void addSkillPoint(const char [][20], int*, const std::string*);

//	Informacja o rozpoczeciu wlasciwej czesci gry z krotkim opisem zasad.
void realGameInfo();

//	Zwieksza losowo kazdy atrybut przeciwnika o 0, 1 lub 2 punkty, po czym zwieksza
//	jego zycie o 1.
void randomizeEnemyAttributes(int*);

//	Dodaje statystyki pokonanego przeciwnika do listy.
void addEnemyToTheList(int*, std::vector< std::vector<int> >&);

//	Wypisuje statystyki przeciwnika, ktory pokonal gracza.
void printLastEnemyStatistics(const char [][20], int*, int);

//	Wypisuje liste wszystkich pokonanych przeciwnikow.
void printAllDefeatedEnemies(const std::vector< std::vector<int> >&);

//	Informacja wyswietlana w przypadku uruchomienia trybu symulacyjnego.
void tutorialInfo();

//	Zwraca wartosc true, jesli gracz chce uruchomic tryb symulacyjny.
bool launchTutorial();

//	Uruchamia symulacje walki, ktora trwa dotad, az ktoras ze stron wygra.
//	Wygrana gracza skutkuje otrzymaniem punktu umiejetnosci i wyswietleniem
//	obecnych atrybutow, a nastepnie zwroceniem wartosci true, symbolizujacej zwyciestwo.
//	Przegrana gracza skutkuje zwroceniem wartosci false, symbolizujacej porazke.
bool fightSimulation(const char [][20], int*, const std::string*, int*, bool);

//	Zwraca ilosc obrazen zadawanych przeciwnikowi.
int attackResult(int, int);

//	Zwraca nazwe postaci wybrana przez uzytkownika.
std::string getName(const unsigned int);

#endif