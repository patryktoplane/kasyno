#pragma once
#include "Karta.h"

class Gracz
{
private:
    Karta* reka[10];
    int liczbaKart;
    int sumaPunktow;

public:
    Gracz();
    void wezKarte(Karta* _karta);
    void pokazKarty();
};
