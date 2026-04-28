#pragma once
#include "Gracz.h"

class Bot : public Gracz
{
private:
    int limitPunktow;
    int odwaga;

public:
    Bot();

    void ustawBota(int _limitPunktow, int _odwaga);
    void wykonajRuch();
};
