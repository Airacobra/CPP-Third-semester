// Nazwa pliku wykonywalnego: Katy

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase reprezentujaca kat z przedzialu od 0 do 2PI. W
// przypadku podania kata spoza tego przedzialu powinien on zostac
// zamieniony na odpowiadajacy mu kat z przedzialu od 0 do 2PI. Klasa
// obsluguje radiany i stopnie.

// Zamiana radianow na stopnie:
// radian = stopnie * PI / 180

// Zamiana stopni na radiany:
// stopnie = radian * 180 / PI

// Do oznaczenia wartosci PI prosze uzyc zmiennej znajdujacej sie w
// bibliotece matematycznej. Po dodaniu:
// #include <cmath>
// mozna uzywac zmiennej M_PI (np. double val = M_PI;)

// Konstruktor klasy przyjmuje radiany.

// UWAGA !!!
// Rozwiazujac zadanie nie wolno przeladowywac zadnych operatorow.

// UWAGA !!!
// Po uruchomieniu linii zabezpieczonych przy pomocy ERROR musi
// pojawic sie blad kompilacji w uruchomionej linii. Jezeli program
// skompiluje sie z uruchomionym ERROR, ocena koncowa zostanie
// obnizona o 5 punktow.

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

int main() {
  using namespace std;

  const double radiansPhi1 = -24;
  const double radiansPhi2 = 12;

  const Angle phi1 (radiansPhi1);
  const Angle phi2 (radiansPhi2);

#ifdef ERROR
  {
    const Angle phi1 = 0.45;
  }
#endif

  double valPhi1 = phi1.rad();
  double valPhi2 = phi2.rad();
  cout << "Radians: phi1 = " << valPhi1 << "     phi2 = " << valPhi2 <<endl;

  valPhi1 = phi1.deg();
  valPhi2 = phi2.deg();
  cout << "Degrees: phi1 = " << valPhi1 << "     phi2 = " << valPhi2 <<endl;

  
  Angle phi3(phi1);
  cout << "phi3 first = "<< phi3.deg() << endl;
  phi3.deg() = 42;
  cout << "phi3 second = "<< phi3.deg() << endl;

  cout << "Distance " << Angle::distance(phi1, phi2).deg() <<" = "<<Angle::distance(phi2, phi1).rad() << endl;
 
  if (phi1 > phi2)
    cout << "phi1 > phi2\n";

  if (phi1 < phi2)
    cout << "phi1 is smaller than phi2\n";

  return 0;
}
/* output
Radians: phi1 = 1.13274     phi2 = 5.71681
Degrees: phi1 = 64.9013     phi2 = 327.549
phi3 first = 64.9013
phi3 second = 42
Distance 97.3519 = 1.69911
phi1 is smaller than phi2
*/
