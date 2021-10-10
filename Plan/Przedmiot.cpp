#include "Przedmiot.h"

Przedmiot::Przedmiot(std::string nazwa,int rodzaj,int czestosc, int numer)
{
    Nazwa = nazwa;
    Czestosc = czestosc;
    Rodzaj = rodzaj;
    Numer = numer;
}

string Przedmiot::Zwroc_nazwe()
{
    return Nazwa;
}

int Przedmiot::Zwroc_numer()
{
    return Numer;
}

int Przedmiot::Zwroc_nauczyciela()
{
    return Nauczyciele[0];
}
void Przedmiot::Nastepny_nauczyciel()
{
    Nauczyciele.erase(Nauczyciele.begin());
}
void Przedmiot::Dodaj_nauczyciela(int numer_nauczyciela)
{
    Nauczyciele.push_back(numer_nauczyciela);
}
int Przedmiot::Ile_nauczycieli()
{
    return Nauczyciele.size();
}
void Przedmiot::Wypisz_nauczycieli()
{
    for (int i = 0; i < Nauczyciele.size();i++)
        cout << Nauczyciele[i] << " ";
        cout << endl;
}
Przedmiot::~Przedmiot()
{
}


