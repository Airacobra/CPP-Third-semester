// Nazwa pliku wykonywalnego: Mario

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase majaca glosne konstruktor i destruktor oraz
// przechowujaca indeks, ktory zwieksza sie automatycznie gdy tworzony
// jest nowy obiekt. Klasa powinna byc napisana tak aby nie dalo
// spowodowac wyciekow pamieci przy jej uzyciu.

// UWAGA !!!
// Po uruchomieniu ktorejkolwiek z linii ERROR powinien pojawic sie
// blad kompilacji. W przypadku jego braku zadanie zostanie ocenione
// na 0 punktow.

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


// #define ERROR
// #define ERROR_TWO

#include "Main.h"

#include <iostream>

#define PRINT(X) {std::cout<<"\n===== Print "<<__LINE__<<" =====\n";\
    X;\
    std::cout<<"\n";}

int main() 
{

#ifdef ERROR
  {
    NonLeakable* dynamicFirst = new NonLeakable;
  }
#endif

  NonLeakablePtr firstPtr;
  
  {
    NonLeakable staticFirst;
  
    NonLeakablePtr dynamicFirst;
    dynamicFirst.MakeNewObject();

    NonLeakablePtr tempPtr;
    tempPtr.MakeNewObject();

    PRINT (staticFirst.Print();
	   dynamicFirst->Print();
	   tempPtr->Print(););

    PRINT (firstPtr.Print();
	   dynamicFirst.Print();
	   tempPtr.Print(););

    firstPtr = dynamicFirst = dynamicFirst;
    const NonLeakablePtr tempPtrSecond = tempPtr;

#ifdef ERROR_TWO
    {
      NonLeakablePtr tempPtr = tempPtrSecond;
    }
#endif

    PRINT(firstPtr.Print();
	  dynamicFirst.Print();
	  tempPtr.Print();
	  tempPtrSecond.Print(););
  }

  const NonLeakable staticSecond;

  PRINT(staticSecond.Print();
	(*firstPtr).Print(););

  firstPtr.MakeNewObject();

  PRINT(staticSecond.Print();
	(&firstPtr)->Print(););
  
  

  return 0;
}
/* output
Constructing object 0
Constructing object 1
Constructing object 2

===== Print 78 =====
This is object with ID=0
This is object with ID=1
This is object with ID=2


===== Print 82 =====
Object pointing to nothing
Object pointing to 0xb20c30
Object pointing to 0xb20c50


===== Print 96 =====
Object pointing to 0xb20c30
Object pointing to nothing
Object pointing to nothing
Object pointing to 0xb20c50

Destroying object 2
Destroying object 0
Constructing object 3

===== Print 102 =====
This is object with ID=3
This is object with ID=1

Destroying object 1
Constructing object 4

===== Print 107 =====
This is object with ID=3
This is object with ID=4

Destroying object 3
Destroying object 4
*/
