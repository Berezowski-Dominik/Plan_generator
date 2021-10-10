#ifndef ZAJECIA_H
#define ZAJECIA_H

#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cmath>

#include "Grupa.h"
#include "Nad_grupa.h"
#include "Nauczyciel.h"
#include "Przedmiot.h"
#include "Sala.h"

using namespace std;

class Zajecia
{
private:
    int Numer;                                                                                              
    int Termin;                                                                                             
    vector <Nauczyciel*> NAuczyciel;
    vector <Przedmiot*> PRzedmiot;
    vector <Nad_grupa*> NAD_grupa;
    vector <Grupa*> GRupa;
    vector <Sala*> SAla;
    vector <int> Wolne_terminy;
    
    
public:
    void Termin_zajec(int losowa);
    int Mozliwosc_zmiany();
    void Zmiana_terminu();
    
    vector <Nauczyciel*> *nauczyciel();
    vector <Sala*> *dodaj_sale();
    
    Przedmiot *przedmiot();
    Sala *sala();
    Grupa *grupa();
    Nad_grupa *nad_grupa();
    
    string Zwroc_imie_i_nazwisko_nauczyciela();
    
    Zajecia(vector <Przedmiot*> przedmiot,vector <Grupa*> grupa,vector <Nad_grupa*> nad_grupa,int numer);
    ~Zajecia();
    
    
    
};

#endif // ZAJECIA_H
