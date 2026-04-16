#pragma once
#include "Karta.h"
#include "Gracz.h"

class Kasyno
{
private:
    Karta talia[52];
    int aktualnaKarta;
    Gracz gracze[3];

public:
    Kasyno();
    Karta* dajKarte();
    void graj();
};
