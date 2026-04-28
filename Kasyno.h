#pragma once
#include "Karta.h"
#include "Gracz.h"
#include "Bot.h"

class Kasyno
{
private:
    Karta talia[52];

    Gracz* gracze;
    Bot* boty;

    int aktualnaKarta;
    int liczbaGraczy;
    int liczbaBotow;

public:
    Kasyno(int _liczbaGraczy, int _liczbaBotow);
    ~Kasyno();

    Karta* dajKarte();

    void graj();
    void tasujKarty();
    void pokazWyniki();
    void resetujGre();

    bool czyWszyscySpasowali();
};
