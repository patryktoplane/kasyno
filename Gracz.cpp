#include "Gracz.h"
using namespace std;

Gracz::Gracz()
{
    liczbaKart = 0;
    sumaPunktow = 0;

    for (int i = 0; i < 10; i++)
    {
        reka[i] = nullptr;
    }
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
