#ifndef SALA_H
#define SALA_H

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Sala
{
private:
    int Numer;
    vector <int> Plan;
    set <int> Zajete_terminy; 
    
    public:
    
    int Zwroc_numer();
    void Dodanie_do_planu(int numer_zajecia, int termin);
    void Dodanie_zaj_terminu(int termin);
    void Usuniecie_zaj_terminu(int termin);
    
    set <int>::iterator Pierwszy_zaj_termin();
    set <int>::iterator Ostatni_zaj_termin();
    
    Sala(int numer);
    ~Sala();
};

#endif // SALA_H
