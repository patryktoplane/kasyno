#include "Kasyno.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

Kasyno::Kasyno(int _liczbaGraczy, int _liczbaBotow)
{
    aktualnaKarta = 0;

    liczbaGraczy = _liczbaGraczy;
    liczbaBotow = _liczbaBotow;

    gracze = new Gracz[liczbaGraczy];
    boty = new Bot[liczbaBotow];

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

    for (int i = 0; i < liczbaBotow; i++)
    {
        boty[i].ustawKasyno(this);
    }

    for (int i = 0; i < liczbaBotow; i++)
    {
        if (i == 0)
        {
            boty[i].ustawBota(19, rand() % 3);
        }
        else if (i == 1)
        {
            boty[i].ustawBota(17, rand() % 3);
        }
        else
        {
            boty[i].ustawBota(15, rand() % 3);
        }
    }

    tasujKarty();
}

Kasyno::~Kasyno()
{
    delete[] gracze;
    delete[] boty;
}

void Kasyno::graj()
{
    resetujGre();

    cout << endl;
    cout << "Rozdanie dwoch pierwszych kart." << endl;

    for (int i = 0; i < liczbaGraczy; i++)
    {
        gracze[i].wezKarte(dajKarte());
        gracze[i].wezKarte(dajKarte());
    }

    for (int i = 0; i < liczbaBotow; i++)
    {
        boty[i].wezKarte(dajKarte());
        boty[i].wezKarte(dajKarte());
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

        for (int i = 0; i < liczbaBotow; i++)
        {
            if (!boty[i].czyPass())
            {
                cout << endl;
                cout << "Ruch bota " << i + 1 << endl;
                boty[i].wykonajRuch();
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

    for (int i = 0; i < liczbaBotow; i++)
    {
        cout << "Bot " << i + 1 << ":" << endl;
        boty[i].pokazKarty();
        cout << endl;
    }

    pokazWyniki();
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

    for (int i = 0; i < liczbaBotow; i++)
    {
        if (!boty[i].czyPass())
        {
            return false;
        }
    }

    return true;
}

void Kasyno::pokazWyniki()
{
    int najlepszyWynik = -1;

    for (int i = 0; i < liczbaGraczy; i++)
    {
        if (gracze[i].getSumaPunktow() <= 21)
        {
            if (gracze[i].getSumaPunktow() > najlepszyWynik)
            {
                najlepszyWynik = gracze[i].getSumaPunktow();
            }
        }
    }

    for (int i = 0; i < liczbaBotow; i++)
    {
        if (boty[i].getSumaPunktow() <= 21)
        {
            if (boty[i].getSumaPunktow() > najlepszyWynik)
            {
                najlepszyWynik = boty[i].getSumaPunktow();
            }
        }
    }

    if (najlepszyWynik == -1)
    {
        cout << endl << "Wszyscy przekroczyli 21 punktow. Brak zwyciezcy." << endl;
        return;
    }

    cout << endl;
    cout << "Najlepszy wynik: " << najlepszyWynik << endl;
    cout << "Wygrywa:" << endl;

    for (int i = 0; i < liczbaGraczy; i++)
    {
        if (gracze[i].getSumaPunktow() == najlepszyWynik)
        {
            cout << "Gracz " << i + 1 << endl;
        }
    }

    for (int i = 0; i < liczbaBotow; i++)
    {
        if (boty[i].getSumaPunktow() == najlepszyWynik)
        {
            cout << "Bot " << i + 1 << endl;
        }
    }
}

void Kasyno::resetujGre()
{
    aktualnaKarta = 0;
    tasujKarty();

    for (int i = 0; i < liczbaGraczy; i++)
    {
        gracze[i].resetujGracza();
    }

    for (int i = 0; i < liczbaBotow; i++)
    {
        boty[i].resetujGracza();
    }
}
