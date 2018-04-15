// Nazwa pliku wykonywalnego: Complex

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klasy reprezentujace liczbe zespolona oraz rejestr,
// ktory potrafi przechowywac jedna liczbe. Rejestr jest tworzony
// dopiero wtedy kiedy jest potrzebny.

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
  {
    Register::Clear();
    ComplexNumber number (4, 3); // Creating number: 4 + 3i
    number.Print();		 // 4 + 3i

    std::cout<<"\n";
    
    Register& reg = Register::Retrieve(); // Creating register
    reg.Print();			  // Register is empty
    reg.Write(number);
    std::cout<<"\n";
    reg.Print();		// Register stores number: 4 + 3i

    number.SetReal(-5).SetImaginary(-4);
    number.Print();		// -5 + -4i

    ComplexNumber saved = reg.Read();
    saved.Print();		// 4 + 3i

    number.Save(reg);
    number.SetImaginary(42);
    number.Print();		// -5 + 42i

    reg.Read().Print();		// -5 + -4i
  
  }
  std::cout<<"\n";

  Register& reg = Register::Retrieve();

  const ComplexNumber number (400, 300); // Creating number: 400 + 300i
  ComplexNumber saved = reg.Read();

  number.Print();		// 400 + 300i
  std::cout<<"+\n";
  saved.Print();		// -5 + -4i
  std::cout<<"=\n";
  number.Add(saved).Print();    // Creating number: 395 + 296i
                                // 395 + 296i

  std::cout<<"\n";

  reg.Clear();

  return 0;
}
/* wynik dzialania programu:
Creating number: 4 + 3i
4 + 3i

Creating register
Register is empty

Register stores number: 4 + 3i
-5 + -4i
4 + 3i
-5 + 42i
-5 + -4i
Deleting: -5 + -4i
Deleting: 4 + 3i
Deleting: -5 + 42i

Creating number: 400 + 300i
400 + 300i
+
-5 + -4i
=
Creating number: 395 + 296i
395 + 296i
Deleting: 395 + 296i

Deleting: -5 + -4i
Deleting: -5 + -4i
Deleting: 400 + 300i
*/
