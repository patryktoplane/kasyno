#include "Kasyno.h"
#include <time.h>
using namespace std;

Kasyno::Kasyno(int _liczbaGraczy)
{
    aktualnaKarta = 0;
    liczbaGraczy = _liczbaGraczy;
    gracze = new Gracz[liczbaGraczy];

    int licznik = 0;

    for (int kolor = 0; kolor < 4; kolor++)
    {
        for (int wartosc = 0; wartosc < 13; wartosc++)
        {
            talia[licznik] = Karta(kolor, wartosc);
            licznik++;
        }
    }

    for (int i = 0; i < liczbaGraczy; i++)
    {
        gracze[i].ustawKasyno(this);
    }

    tasujKarty();
}

Kasyno::~Kasyno()
{
    delete[] gracze;
}

void Kasyno::graj()
{
    for (int i = 0; i < liczbaGraczy; i++)
    {
        gracze[i].wezKarte(dajKarte());
        gracze[i].wezKarte(dajKarte());
    }

    while (!czyWszyscySpasowali())
    {
        for (int i = 0; i < liczbaGraczy; i++)
        {
            if (!gracze[i].czyPass())
            {
                cout << endl;
                cout << "Ruch gracza " << i + 1 << endl;
                gracze[i].wykonajRuch();
            }
        }
    }

    cout << endl << "KONIEC GRY" << endl << endl;

    for (int i = 0; i < liczbaGraczy; i++)
    {
        cout << "Gracz " << i + 1 << ":" << endl;
        gracze[i].pokazKarty();
        cout << endl;
    }
}

void Kasyno::tasujKarty()
{
    srand(time(NULL));

    for (int i = 0; i < 100; i++)
    {
        int a = rand() % 52;
        int b = rand() % 52;

        Karta temp = talia[a];
        talia[a] = talia[b];
        talia[b] = temp;
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

bool Kasyno::czyWszyscySpasowali()
{
    for (int i = 0; i < liczbaGraczy; i++)
    {
        if (!gracze[i].czyPass())
        {
            return false;
        }
    }

    return true;
}
