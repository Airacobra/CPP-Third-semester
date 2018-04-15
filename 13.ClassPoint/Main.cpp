// Nazwa pliku wykonywalnego: Point

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase reprezentujaca punkt w przestrzeni
// trojwymiarowej (wspolrzedne sa typu int) oraz tablice takich
// punktow. Rozmiar tablicy oraz domyslne wartosci elementow sa podane
// w konstruktorze.

// UWAGA !!!
// Rozwiazujac zadanie nie wolno korzystac z biblioteki standardowej oprocz cout i endl.

// UWAGA !!!
// Wycieki pamieci obnizaja ocene koncowa o 2 punkty.

// UWAGA !!!
// Uruchomienie linii oznaczonej ERROR powinno powodowac blad
// kompilacji. W przypadku braku takiego bledu program zostanie
// oceniony na 0 punktow.

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
#include "Main.h"

#include <iostream>

//#define ERROR

int main() 
{
#ifdef ERROR
  { Point3D first;}
#endif

  const Point3D first (101, 102, 103);
  std::cout<<"First\n";
  std::cout<<first<<"\n";

  PointArray arrayFirst (4, Point3D (1, 2, 3));
  arrayFirst[1] = Point3D (6, 2, 8);
  arrayFirst[2] = Point3D (11, 3, 90);

  arrayFirst.Print();

  PointArray arraySecond = arrayFirst;
  arrayFirst[2] = Point3D (-4, -5, -6);

  PointArray arrayThird (2, Point3D (10, 20, 30));

  std::cout<<"\nThird array\n";
  arrayThird.Print();

  std::cout<<"\nModified first array\n";
  arrayFirst.Print();

  std::cout<<"\nSecond array\n";
  arraySecond.Print();


  std::cout<<"\nFirst logic\n";
  if (arrayFirst == arraySecond)
    std::cout<<"first == second\n";
  else
    std::cout<<"first differs from second\n";

  if (arrayFirst == arrayThird)
    std::cout<<"first == third\n";
  else
    std::cout<<"first differs from third\n";

  arraySecond = arrayThird = arrayFirst = arrayFirst;

  std::cout<<"\nSecond logic\n";
  if (arrayFirst == arrayThird)
    std::cout<<"first == third\n";
  else
    std::cout<<"first differs from third\n";


  std::cout<<"\n--- first ---\n";
  arrayFirst.Print();
  std::cout<<"\n--- second ---\n";
  arraySecond.Print();
  std::cout<<"\n--- third ---\n";
  arrayThird.Print();

  return 0;
}
/* output
First
(101, 102, 103)
(1, 2, 3)
(6, 2, 8)
(11, 3, 90)
(1, 2, 3)

Third array
(10, 20, 30)
(10, 20, 30)

Modified first array
(1, 2, 3)
(6, 2, 8)
(-4, -5, -6)
(1, 2, 3)

Second array
(1, 2, 3)
(6, 2, 8)
(11, 3, 90)
(1, 2, 3)

First logic
first differs from second
first differs from third

Second logic
first == third

--- first ---
(1, 2, 3)
(6, 2, 8)
(-4, -5, -6)
(1, 2, 3)

--- second ---
(1, 2, 3)
(6, 2, 8)
(-4, -5, -6)
(1, 2, 3)

--- third ---
(1, 2, 3)
(6, 2, 8)
(-4, -5, -6)
(1, 2, 3)
*/