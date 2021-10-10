#include "Nad_grupa.h"

Nad_grupa::Nad_grupa(int rodzaj, int numer)
{
    Rodzaj = rodzaj;
    Numer = numer;
    if(Rodzaj == 2)
        Grupy_cw.push_back(NULL);
}
set <int>::iterator Nad_grupa::Pierwszy_zaj_termin()
{
    return Zajete_terminy.begin();
}
set <int>::iterator Nad_grupa::Ostatni_zaj_termin()
{
    return Zajete_terminy.end();
}
void Nad_grupa::Dodanie_zaj_terminu(int termin)
{
    Zajete_terminy.insert(termin);
}
vector <Grupa*> *Nad_grupa::grupa_lab()
{
    return &Grupy_lab;
}
Grupa* Nad_grupa::grupa_lab(int numer_grupy)
{
    return Grupy_lab[numer_grupy];
}
vector <Nad_grupa*> *Nad_grupa::grupa_cw()
{
    return &Grupy_cw;
}
Nad_grupa* Nad_grupa::grupa_cw(int numer_grupy)
{
    return Grupy_cw[numer_grupy];
}
int Nad_grupa::Zwroc_rodzaj()
{
    return Rodzaj;
}
int Nad_grupa::Zwroc_numer_grupy()
{
    return Numer;
}
Nad_grupa::~Nad_grupa()
{
    
}