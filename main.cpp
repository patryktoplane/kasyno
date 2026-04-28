#include "Kasyno.h"
#include <iostream>
using namespace std;

int main()
{
    int liczbaGraczy;
    int liczbaBotow;
    int wybor;

    cout << "Podaj liczbe graczy: ";
    cin >> liczbaGraczy;

    while (liczbaGraczy < 1 || liczbaGraczy > 3)
    {
        cout << "Bledna liczba. Podaj liczbe od 1 do 3: ";
        cin >> liczbaGraczy;
    }

    cout << "Podaj liczbe botow: ";
    cin >> liczbaBotow;

    while (liczbaBotow < 1 || liczbaBotow > 3)
    {
        cout << "Bledna liczba. Podaj liczbe od 1 do 3: ";
        cin >> liczbaBotow;
    }

    Kasyno kasyno(liczbaGraczy, liczbaBotow);

    do
    {
        kasyno.graj();

        cout << endl;
        cout << "Czy chcesz rozpoczac nowa gre?" << endl;
        cout << "1: Tak" << endl;
        cout << "0: Nie" << endl;
        cin >> wybor;

    } while (wybor == 1);

    cout << "Koniec programu." << endl;

    return 0;
}
