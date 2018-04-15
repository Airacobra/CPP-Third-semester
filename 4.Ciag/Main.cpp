// Nazwa pliku wykonywalnego: Ciagi

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac funkcje tworzace i operaujace na ciagach. Nalezy
// utworzyc ciagi geometryczne o pierwszym wyrazie 1 i zadanym
// ilorazie. Oprocz tego nalezy obliczyc sume oraz iloczyn wszystkich
// elementow ciagu, a takze znalezc jego najwiekszy i najmniejszy element.

// Prosze zadbac o odbre zarzadzanie pamiecia.

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
  const rozmiarCiagu rozmiar = 6;
  const float iloraz1 = 2;
  
  // pierwszy element ciagu to 1
  const ciag geometryczny1 = InicjalizujCiagGeometryczny (rozmiar, iloraz1);
  Wypisz(geometryczny1, rozmiar); // (1, 2, 4, 8, 16, 32)
  
  const float iloraz2 = 3.;
  const ciag geometryczny2 = InicjalizujCiagGeometryczny (rozmiar, iloraz2);
  Wypisz(geometryczny2, rozmiar); // (1, 3, 9, 27, 81, 243)

  Suma(geometryczny1, rozmiar);
  std::cout<<"suma (w main): "<<Suma(geometryczny1, rozmiar)<<"\n"; // suma (w main): 63

  operacja przeksztalc [] = {Suma, Iloczyn, Max, Min};
  const int ileOperacji = sizeof(przeksztalc)/sizeof(operacja);
  for (int i = 0; i < ileOperacji; ++i)
    WykonajIWypisz (przeksztalc[i], geometryczny1, rozmiar); // SUMA: 63
                                                             // ILOCZYN: 32768
                                                             // MAX: 32
                                                             // MIN: 1

  delete [] geometryczny1;
  delete [] geometryczny2;
}
/* wynik dzialania programu:
(1, 2, 4, 8, 16, 32)
(1, 3, 9, 27, 81, 243)
suma (w main): 63
SUMA: 63
ILOCZYN: 32768
MAX: 32
MIN: 1
*/
