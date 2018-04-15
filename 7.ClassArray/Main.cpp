// Nazwa pliku wykonywalnego: Array

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase reprezentujaca tablice intow. 

// UWAGA !!!
// Przy rozwiazaniu zadania nie wolno korzystac z biblioteki
// standardowej oprocz cout i endl

// UWAGA !!!
// Po uruchomieniu linii zabezpieczonych przy pomocy ERROR musi
// pojawic sie blad kompilacji w uruchomionej linii. Jezeli program
// skompiluje sie z uruchomionym ERROR, ocena koncowa zostanie
// obnizona o 4 punkty.

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

// #define ERROR

void Just5 (MyArray array) {
  std::cout<<"\n===== Just5 =====\n";
  for (int i = 0; i < array.size; ++i)
    array.at(i) = 5;
  
  array.print();
}

void OnlyPrint (const MyArray& array) {
  std::cout<<"\n===== OnlyPrint =====\n";
  for (int i = 0; i < array.size; ++i)
    std::cout<<i<<": "<<array.at(i)<<"\n";
}


int main ()
{
  MyArray array (4);
  for (int i = 0; i < array.size; ++i)
    array.at(i) = 10*i;

  std::cout<<"===== first print =====\n";
  array.print();
  
  Just5 (array);

  std::cout<<"\n===== after Just5 =====\n";
  array.print();

  OnlyPrint (array);

  std::cout<<"\n===== resize =====\n";
  array.resize(6);
  array.at(4) = 4;
  array.at(5) = 2;
  array.print();

  std::cout<<"\nNew array size: "<<array.size<<"\n";

#ifdef ERROR
  array.size = 4;
#endif

  return 0;
}
/* wynik dzialania programu:
===== first print =====
Array content:
array[0] = 0
array[1] = 10
array[2] = 20
array[3] = 30

===== Just5 =====
Array content:
array[0] = 5
array[1] = 5
array[2] = 5
array[3] = 5

===== after Just5 =====
Array content:
array[0] = 0
array[1] = 10
array[2] = 20
array[3] = 30

===== OnlyPrint =====
0: 0
1: 10
2: 20
3: 30

===== resize =====
Array content:
array[0] = 0
array[1] = 10
array[2] = 20
array[3] = 30
array[4] = 4
array[5] = 2

New array size: 6
*/
