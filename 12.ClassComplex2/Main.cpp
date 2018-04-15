// Nazwa pliku wykonywalnego: Complex

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase reprezentujaca liczbe zespolona. Porownanie
// liczb zespolonych ma odbywac sie na podstawie ich kwadratu
// dlugosci.

// UWAGA !!!
// Rozwiazujac zadanie nie wolno przeladowywac operatorow porownania i
// przypisania.

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

int main()
{
  using namespace std;

  std::cout<<"----- creating first -----\n";
  const ComplexNumber first (2, 4);
  first.Print();		// 2 + 4i
  cout<<"Manual print: "<<first.Real()<<" + "<<first.Imaginary()<<"i\n"; // Manual print: 2 + 4i
  
  std::cout<<"\n----- creating second -----\n";
  ComplexNumber second (10, 20);
  second.Print();		// 10 + 20i

  std::cout<<"\n----- setting -----\n";
  second.Imaginary() = 0.2;
  second.Real() = 0.1;
  second.Print();		// 0.1 + 0.2i
  
  std::cout<<"\n----- seven -----\n";
  second = 7;
  second.Print();		// 7

  std::cout<<"\n----- sum -----\n";
  second.Add(first).Add(2).Add(first);
  second.Print();		// 13 + 8i
  
  std::cout<<"\n----- go compare -----\n";
  first.Print();		// 2 + 4i
  if (first > second)
    cout << "   >\n";
  else if (second > first)
    cout << "   <\n";
  else 
    cout << "   =\n";
  second.Print();		// 13 + 8i

  return 0;
}
/* output
----- creating first -----
2 + 4i
Manual print: 2 + 4i

----- creating second -----
10 + 20i

----- setting -----
0.1 + 0.2i

----- seven -----
7

----- sum -----
13 + 8i

----- go compare -----
2 + 4i
   <
13 + 8i
 */
