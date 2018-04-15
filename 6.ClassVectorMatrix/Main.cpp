// Nazwa pliku wykonywalnego: Algebra

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na koncu tego
// pliku.

// Prosze napisac klasy reprezentujace wektor (poziomy), wektor
// transposnowany (pionowy) i macierz. Prosze zaimplementowac mnozenie:
// * wektor*wektorTransponowany = liczba
// * wektoTransponowany*wektor = macierz
// * macierz*wektorTransponowany = wektorTransponowany
// * macierz*macierz = macierz

// Komentarze w kodzie pokazuja jakie wyjscie powinna generowac dana
// linia.

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
  Vector3D first (1, 2, 3);
  VectorTrans3D second (10, 20, 30);

  std::cout<<"second:\n";
  second.Print();  // 10
                   // 20
                   // 30

  std::cout<<"first = ";
  first.Print();  // (1, 2, 3)

  const int scalar = first.Times(second);
  std::cout<<"vector x vector transposed = "<<scalar<<"\n"; // vector x vector transposed = 140

  Matrix3 product = second.Times(first);
  std::cout<<"\nvector transposed x vector\n";
  product.Print(); // (10, 20, 30)
                   // (20, 40, 60)
                   // (30, 60, 90)

  std::cout<<"Matrix x vector transposed\n";
  product.Times(second).Print(); // 1400
                                 // 2800
                                 // 4200

  std::cout<<"Matrix x matrix\n";
  product.Times(product).Print(); // (1400, 2800, 4200)
                                  // (2800, 5600, 8400)
                                  // (4200, 8400, 12600)

  return 0;
}
/* wynik dzialania programu:
second:
10
20
30
first = (1, 2, 3)
vector x vector transposed = 140

vector transposed x vector
(10, 20, 30)
(20, 40, 60)
(30, 60, 90)
Matrix x vector transposed
1400
2800
4200
Matrix x matrix
(1400, 2800, 4200)
(2800, 5600, 8400)
(4200, 8400, 12600)
*/
