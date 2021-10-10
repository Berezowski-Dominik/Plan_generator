#ifndef GRUPA_NAD_H
#define GRUPA_NAD_H

#include <vector>

#include "Grupa.h"

using namespace std;

class Nad_grupa
{
private:
    int Rodzaj;                                                     
    int Numer;                                                      
    set < int > Zajete_terminy;                                     
    vector <Grupa*> Grupy_lab;                                      
    vector <Nad_grupa*> Grupy_cw;                                  
    
public:
    set <int>::iterator Pierwszy_zaj_termin();
    set <int>::iterator Ostatni_zaj_termin();
    
    vector <Grupa*> *grupa_lab();
    Grupa* grupa_lab(int numer_grupy);
    
    vector <Nad_grupa*> *grupa_cw();
    Nad_grupa* grupa_cw(int numer_grupy);
    
    void Dodanie_zaj_terminu(int termin);
    
    int Zwroc_rodzaj();
    int Zwroc_numer_grupy();
    
    Nad_grupa(int rodzaj, int numer);
    ~Nad_grupa();
};

#endif // GRUPA_NAD_H
