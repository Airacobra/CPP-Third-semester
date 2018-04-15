// Nazwa pliku wykonywalnego: Fraction

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klasy reprezentujace ulamek zwykly oraz tablice
// ulamkow. Na ulamkach mozna wykonywac operacje dodawania oraz mozna
// obliczyc sume wszystkich ulamkow w tablicy.

// Komentarze w kodzie pokazuja jakie wyjscie powinna generowac dana
// linia.

// UWAGA !!!
// Przy rozwiazaniu zadania nie wolno korzystac z biblioteki
// standardowej oprocz cout i endl

// UWAGA !!!
// Po uruchomieniu linii zabezpieczonych przy pomocy ERROR musi
// pojawic sie blad kompilacji w uruchomionej linii. Jezeli program
// skompiluje sie z uruchomionym ERROR, rozwiazanie zostanie
// potraktowane jako bledna kompilacja co oznacza 0 punktow za
// zadanie.

// Pliku Main.cpp, nie wolno modyfikowac. 

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie podanej na poczatku tego pliku. Program nalezy kompilowac
// z flagami -Wall -Wextra -pedantic -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile)

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy wgrac
// do UPEL: upel.agh.edu.pl/wfiis/course/view.php?id=22

#include "Main.h"

#include<iostream>

//#define ERROR

int main ()
{

#ifdef ERROR
  {
   Fraction first;
  }
#endif
  Fraction first (1, 2);
  first.Print();		// 1/2

  Fraction* second = new Fraction(5, 3);
  second->Print();		// 1 2/3

  Fraction sumFirstSecond = first.Add(*second);
  sumFirstSecond.Print();	// 2 1/6

  const int arraySize = 3;
  FractionArray array (arraySize);
  array.AddFration(2, 5);
  array.AddFration(6, 7);
  array.AddFration(3, 4);

  std::cout<<"\n=== ARRAY I ===\n";
  array.Print ();   // 0: 2/5
                    // 1: 6/7
                    // 2: 3/4


  std::cout<<"\n=== SUM ===\n";
  array.Sum().Print();		// 2 1/140

  std::cout<<"\n=== ARRAY II ===\n";
  array.Print ();   // 0: 2/5
                    // 1: 6/7
                    // 2: 3/4

  delete second;

  return 0;
}
/* wynik dzialania programu:
1/2
1 2/3
2 1/6

=== ARRAY I ===
0: 2/5
1: 6/7
2: 3/4

=== SUM ===
2 1/140

=== ARRAY II ===
0: 2/5
1: 6/7
2: 3/4
*/
