#pragma once
#include "Karta.h"
#include "Gracz.h"

class Kasyno
{
private:
    Karta talia[52];
    int aktualnaKarta;
    Gracz* gracze;
    int liczbaGraczy;

public:
    Kasyno(int liczbaGraczy);
    ~Kasyno();
    Karta* dajKarte();
    void graj();
    void tasujKarty();
    bool czyWszyscySpasowali();
};
