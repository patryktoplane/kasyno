#include "Bot.h"
#include "Kasyno.h"
#include <iostream>
using namespace std;

Bot::Bot()
{
    limitPunktow = 0;
    odwaga = 0;
}

void Bot::ustawBota(int _limitPunktow, int _odwaga)
{
    limitPunktow = _limitPunktow;
    odwaga = _odwaga;
}

void Bot::wykonajRuch()
{
    if (pass == true)
    {
        return;
    }

    cout << "Karty bota:" << endl;
    pokazKarty();

    if (sumaPunktow < limitPunktow + odwaga)
    {
        cout << "Bot dobiera karte." << endl;
        wezKarte(kasyno->dajKarte());

        if (sumaPunktow > 21)
        {
            cout << "Bot przekroczyl 21 punktow." << endl;
            pass = true;
        }
    }
    else
    {
        cout << "Bot pasuje." << endl;
        pass = true;
    }
}
