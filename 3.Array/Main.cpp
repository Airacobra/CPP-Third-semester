// Nazwa pliku wykonywalnego: Array

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze zaimplementowac tablice dwuwymiarowa, ktora w kazdym wierszu
// ma inna liczbe kolumn. Dodtakowo prosze napisac funkcje, ktore
// wypisze te tablice, cala wyplenia podana liczba lub ustawia wartosc
// konkretnego elementu oraz znajda maksimum w kazdym z wierszy jak i
// globalne.

// Komentarze w kodzie pokazuja jakie wyjscie powinna generowac dana
// linia.

// Prosze zwrocic uwage na dobre zarzadzanie pamiecia.

// UWAGA !!!
// W tym zadaniu bardzo wazne jest zarzadzanie pamiecia. Za problemy z
// pamiecia moga zostac odjete nawet 2 punkty za samo wykonanie.

// UWAGA !!!
// Implementacja powinna byc zoptymalizowana pod wzgledem
// wykorzystania pamieci, tzn. nie powinno byc zaalokowane wiecej
// miejsca niz jest to konieczne. Za brak optymalizacji bedzie
// odejmowane nawet do 3 punktow za kod.

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

int main ()
{
  std::cout<<"=== First Array ===\n";
  int size1 [] = {3, 9, 5, 1};
  Array* firstArray = 0;
  CreateArray (firstArray, size1, sizeof(size1)/sizeof(int));
  size1[1] = 100;
  FillWith(firstArray, 1);
  Print (*firstArray);          // 1 1 1
                                // 1 1 1 1 1 1 1 1 1
                                // 1 1 1 1 1
                                // 1

  
  std::cout<<"\nmodified\n";
  SetElement(2, 4, &firstArray, 10);
  SetElement(0, 2, &firstArray, 11);
  SetElement(1, 1, &firstArray, 12);

  SetElement(2, 8, &firstArray, 12); // Index out of bounds

  Print (*firstArray);           // 1 1 11
                                // 1 12 1 1 1 1 1 1 1
                                // 1 1 1 1 10
                                // 1

  PrintMax (firstArray);        // maximum
                                // max 0: 11
                                // max 1: 12
                                // max 2: 10
                                // max 3: 1
                                // global max: 12
  
  std::cout<<"\n=== Second Array ===\n";

  const int size2 [] = {7, 2};
  Array* secondArray = 0;
  CreateArray (secondArray, size2, sizeof(size2)/sizeof(int));
  FillWith(secondArray, 5);

  Print (*secondArray);          // 5 5 5 5 5 5 5
                                //5 5
  
  SetElement(0, 4, &secondArray, 10);
  SetElement(2, 1, &secondArray, 12); // Index out of bounds
  SetElement(1, 1, &secondArray, 12);

  std::cout<<"\nmodified\n";

  Print (*secondArray);          // 5 5 5 5 10 5 5
                                // 5 12

  Clear (&firstArray);
  Clear (&secondArray);
  
  return 0;
}
/* wynik dzialania programu:
=== First Array ===
1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1
1
modified
Index out of bounds
1 1 11
1 12 1 1 1 1 1 1 1
1 1 1 1 10
1
maximum
max 0: 11
max 1: 12
max 2: 10
max 3: 1
global max: 12
=== Second Array ===
5 5 5 5 5 5 5
5 5
Index out of bounds
modified
5 5 5 5 10 5 5
5 12
*/