#pragma once
#include "Karta.h"

class Kasyno;

class Gracz
{
protected:
    Karta* reka[10];
    Kasyno* kasyno;

    int liczbaKart;
    int sumaPunktow;

    bool pass;

public:
    Gracz();

    void wezKarte(Karta* _karta);
    void pokazKarty();
    void ustawKasyno(Kasyno* _kasyno);
    void wykonajRuch();
    void resetujGracza();

    bool czyPass();
    bool czyPrzegral();

    int getSumaPunktow();
};
