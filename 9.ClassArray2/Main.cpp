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

  std::cout<<"\n--- before ---\n";
  array.print();

  for (int i = 0; i < array.size; ++i)
    array.at(i) = 5;
  
  std::cout<<"\n--- after ---\n";
  array.print();
}

void OnlyPrint (const MyArray& array) {
  std::cout<<"\n===== OnlyPrint =====\n";
  std::cout<<"Array ID = "<<array.id()<<"\n";;
  for (int i = 0; i < array.size; ++i)
    std::cout<<i<<": "<<array.at(i)<<"\n";
}


int main ()
{
  const int arraySize = 4;
  int* bareArray = new int[arraySize];
  MyArray array (bareArray, arraySize);
  array.id() = 1;
  for (int i = 0; i < array.size; ++i)
    array.at(i) = 10*i;

  std::cout<<"===== first print =====\n";
  array.print();

  std::cout<<"===== bare elements =====\n";
  std::cout<<bareArray[0];
  for (int i = 1; i < array.size; ++i)
    std::cout<<" "<<bareArray[i];
  std::cout<<"\n";
  
  Just5 (array);

  std::cout<<"\n===== after Just5 =====\n";
  array.print();

  OnlyPrint (array);

  std::cout<<"\n===== resize =====\n";
  array.id() = 2;
  array.resize(6);
  array.at(4) = 4;
  array.at(5) = 2;
  array.print();

  std::cout<<"\nNew array size: "<<array.size<<"\n";

  std::cout<<"\n===== bare array resize =====\n";
  std::cout<<bareArray[4]<<" "<<bareArray[5]<<"\n";

#ifdef ERROR
  array.size = 4;
#endif

  return 0;
}
/* wynik dzialania programu:
===== first print =====
Content of array with ID=1
array[0] = 0
array[1] = 10
array[2] = 20
array[3] = 30
===== bare elements =====
0 10 20 30

===== Just5 =====

--- before ---
Content of array with ID=1
array[0] = 0
array[1] = 10
array[2] = 20
array[3] = 30

--- after ---
Content of array with ID=1
array[0] = 5
array[1] = 5
array[2] = 5
array[3] = 5

===== after Just5 =====
Content of array with ID=1
array[0] = 0
array[1] = 10
array[2] = 20
array[3] = 30

===== OnlyPrint =====
Array ID = 1
0: 0
1: 10
2: 20
3: 30

===== resize =====
Content of array with ID=2
array[0] = 0
array[1] = 10
array[2] = 20
array[3] = 30
array[4] = 4
array[5] = 2

New array size: 6

===== bare array resize =====
4 2
*/
