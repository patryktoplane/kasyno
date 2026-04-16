#include "Kasyno.h"
using namespace std;

Kasyno::Kasyno()
{
    aktualnaKarta = 0;

    int licznik = 0;

    for (int kolor = 0; kolor < 4; kolor++)
    {
        for (int wartosc = 0; wartosc < 13; wartosc++)
        {
            talia[licznik] = Karta(kolor, wartosc);
            licznik++;
        }
    }
}

Karta* Kasyno::dajKarte()
{
    if (aktualnaKarta < 52)
    {
        Karta* wsk = &talia[aktualnaKarta];
        aktualnaKarta++;
        return wsk;
    }

    return nullptr;
}

void Kasyno::graj()
{
    for (int i = 0; i < 3; i++)
    {
        gracze[i].wezKarte(dajKarte());
        gracze[i].wezKarte(dajKarte());
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "Gracz " << i + 1 << ":" << endl;
        gracze[i].pokazKarty();
        cout << endl;
    }
}
