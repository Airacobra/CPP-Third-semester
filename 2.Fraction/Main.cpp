// Nazwa pliku wykonywalnego: Fraction

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac strukture reprezentujaca ulamek oraz funkcje
// wykonujace na niej operacje oraz typ reprezentujacy macierz ulamkow
// Matrix.

// Macierz mozna wypelnic automatycznie przy uzyciu funkcji:

// FillRowByColumnPlus1 (&first, 3), ktora tworzy macierz:
// 1/1  1/2  1/3
// 2/1  2/2  2/3
// 3/1  3/2  3/3

// FillRowByColumnPlus5 (&first, 3), ktora tworzy macierz:
// 1/6  1/7  1/8
// 2/6  2/7  2/8
// 3/6  3/7  3/8
  
// Przy wypisywaniu macierzy kolumny powinny byc oddzielone znakiem tabulatora "\t"

// UWAGA !!!
// Do rozwiazania zadania nie wolno korzystac z zadnych funkcji z
// biblioteki standardowej oprocz cout i endl.

// Komentarze w kodzie pokazuja jakie wyjscie powinna generowac dana
// linia.

// Prosze zwrocic uwage na dobre zarzadzanie pamiecia.

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
  const int size = 3;

  Matrix first;
  InitMatrix (&first, size);

  Matrix second;
  InitMatrix (&second, size);

  first[0][0] = new Fraction;
  SetFraction(first[0][0], 3, 4);
  first[2][1] = new Fraction;
  SetFraction(first[2][1], 1, 8);

  second[2][2] = new Fraction;
  SetFraction(second[2][2], 42, 13);

  std::cout<<"===== FRACTIONS =====\n";
  Print(first[0][0]);		// 3/4
  std::cout<<"\n";
  Print(first[2][1]);		// 1/8
  std::cout<<"\n";
  Print(second[2][2]);		// 3 3/13
  std::cout<<"\n";

  FillRowByColumnPlus1 (&first, size); // SET 1/1  1/2  1/3
                                       //     2/1  2/2  2/3
                                       //     3/1  3/2  3/3

  FillRowByColumnPlus5 (&second, size);  // SET 1/6  1/7  1/8
                                         //     2/6  2/7  2/8
                                         //     3/6  3/7  3/8
  
  std::cout<<"\n===== FIRST MATRIX =====\n";
  PrintMatrix(first, size);	// 1 	1/2	1/3
                                // 2 	1 	2/3
                                // 3 	1 1/2	1 


  std::cout<<"\n===== SECOND MATRIX =====\n";
  PrintMatrix(second, size);	// 1/5	1/6	1/7
                                // 2/5	2/6	2/7
                                // 3/5	3/6	3/7


  std::cout<<"\n===== SUM =====\n";
  Matrix sumFirstSecond;
  Sum (first, second, size,  &sumFirstSecond);
  PrintMatrix (sumFirstSecond, size); // 1 1/5	8/12	10/21
                                      // 2 2/5	1 4/12	20/21
                                      // 3 3/5	2 	1 9/21

  
  
  Clear (first, size);
  Clear (second, size);
  Clear (sumFirstSecond, size);
  

  return 0;
}
/* wynik dzialania programu:
===== FRACTIONS =====
3/4
1/8
3 3/13

===== FIRST MATRIX =====
1 	1/2	1/3
2 	1 	2/3
3 	1 1/2	1 

===== SECOND MATRIX =====
1/5	1/6	1/7
2/5	2/6	2/7
3/5	3/6	3/7

===== SUM =====
1 1/5	8/12	10/21
2 2/5	1 4/12	20/21
3 3/5	2 	1 9/21
*/
