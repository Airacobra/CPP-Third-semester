// Nazwa pliku wykonywalnego: Simpsons

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze zwrocic uwage na dobre zarzadzanie pamiecia.

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
#include "Main.h"

#define SIMPSONS_SIZE 3

#include<iostream>

int main ()
{
  std::cout<<"--- MAGGIE ---\n";
  Student maggie;
  maggie.first_letter_name = 'M';
  maggie.first_letter_surname = 'S';
  maggie.grade = 5;
  print(maggie);		// Initials: M. S. 	grade: 5

  std::cout<<"\n--- BART ---\n";
  Student bart;
  set_student ('B', 'S', 2, &bart);
  print (bart);			// Initials: B. S. 	grade: 2

  std::cout<<"\n--- LISA ---\n";
  Student lisa;
  set_student ('L', 'S', 6, &lisa);
  print (lisa);			// Initials: L. S. 	grade: 6


  StudentsArray simpsons;
  init_array(&simpsons, 3);
  simpsons.element[0] = &maggie;
  simpsons.element[1] = &lisa;
  simpsons.element[2] = &bart;


  std::cout<<"\n--- ITERATOR ---\n";
  Iterator firstIter;
  init_iter (&simpsons, &firstIter);

  while (firstIter.object) {
    print (*firstIter.object);
    move_forward(&firstIter);
  } 


  std::cout<<"\n--- ELEMENT 1 ---\n";
  select_element(&firstIter, 1);
  print (*firstIter.object);
  
  std::cout<<"\n--- TWO ITERATORS ---\n";
  Iterator secondIter;
  init_iter (&simpsons, &secondIter);

  while (firstIter.object) {
    print (*firstIter.object);
    move_forward(&firstIter);

    print (*secondIter.object);
    move_forward(&secondIter);
  }
  
  delete_array (&simpsons);

  return 0;
}
/* wynik dzialania programu:
--- MAGGIE ---
Initials: M. S. 	grade: 5

--- BART ---
Initials: B. S. 	grade: 2

--- LISA ---
Initials: L. S. 	grade: 6

--- ITERATOR ---
Initials: M. S. 	grade: 5
Initials: L. S. 	grade: 6
Initials: B. S. 	grade: 2

--- ELEMENT 1 ---
Initials: L. S. 	grade: 6

--- TWO ITERATORS ---
Initials: L. S. 	grade: 6
Initials: M. S. 	grade: 5
Initials: B. S. 	grade: 2
Initials: L. S. 	grade: 6
*/
