#pragma once
#include "Karta.h"

class Kasyno;

class Gracz
{
private:
    Karta* reka[10];
    int liczbaKart;
    int sumaPunktow;
    bool pass;
    Kasyno* kasyno;

public:
    Gracz();

    void wezKarte(Karta* _karta);
    void pokazKarty();
    void ustawKasyno(Kasyno* _kasyno);
    void wykonajRuch();

    bool czyPass();
};
