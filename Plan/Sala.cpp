#include "Sala.h"

Sala::Sala(int numer)
{
    Numer = numer;
    Plan.resize(20);
}
int Sala::Zwroc_numer()
{
    return Numer;
}
void Sala::Dodanie_do_planu(int numer_zajecia, int termin)
{
    Plan[termin] = numer_zajecia;
}
void Sala::Dodanie_zaj_terminu(int termin)
{
    Zajete_terminy.insert(termin);
}
void Sala::Usuniecie_zaj_terminu(int termin)
{
    Zajete_terminy.erase(Zajete_terminy.find(termin));
}
set <int>::iterator Sala::Pierwszy_zaj_termin()
{
    return Zajete_terminy.begin();
}
set <int>::iterator Sala::Ostatni_zaj_termin()
{
    return Zajete_terminy.end();
}

Sala::~Sala()
{
}

