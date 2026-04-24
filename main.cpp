#include "Kasyno.h"
#include <iostream>
using namespace std;

int main()
{
    int liczbaGraczy;

    cout << "Podaj liczbe graczy (1-3): ";
    cin >> liczbaGraczy;

    while (liczbaGraczy < 1 or liczbaGraczy > 3)
    {
        cout << "Bledna liczba. Podaj jeszcze raz (1-3): ";
        cin >> liczbaGraczy;
    }

    Kasyno kasyno(liczbaGraczy);
    kasyno.graj();

    return 0;
}
