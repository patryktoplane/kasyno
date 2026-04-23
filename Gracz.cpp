#include "Gracz.h"
#include "Kasyno.h"
#include <iostream>
using namespace std;

Gracz::Gracz()
{
    liczbaKart = 0;
    sumaPunktow = 0;
    pass = false;
    kasyno = nullptr;

    for (int i = 0; i < 10; i++)
    {
        reka[i] = nullptr;
    }
}

void Gracz::ustawKasyno(Kasyno* _kasyno)
{
    kasyno = _kasyno;
}

void Gracz::wezKarte(Karta* _karta)
{
    if (_karta != nullptr && liczbaKart < 10)
    {
        reka[liczbaKart] = _karta;
        sumaPunktow += _karta->getWartosc();
        liczbaKart++;
    }
}

void Gracz::pokazKarty()
{
    cout << "Karty gracza: ";

    for (int i = 0; i < liczbaKart; i++)
    {
        reka[i]->wypisz();
        cout << " ";
    }

    cout << endl << "Suma punktow: " << sumaPunktow << endl;
}

void Gracz::wykonajRuch()
{
    if (pass)
    {
        return;
    }

    int wybor;

    cout << "Obecne karty:" << endl;
    pokazKarty();

    cout << "1: Pass\n2: Dobierz" << endl;
    cin >> wybor;

    if (wybor == 1)
    {
        pass = true;
    }
    else if (wybor == 2)
    {
        if (kasyno != nullptr)
        {
            wezKarte(kasyno->dajKarte());
        }
    }
}

bool Gracz::czyPass()
{
    return pass;
}
