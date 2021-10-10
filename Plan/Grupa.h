#ifndef GRUPA_H
#define GRUPA_H

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Grupa
{
private:
    string Kierunek;
    int Stopien;
    int Rocznik;
    int Numer;
    float Kara;
    
    vector <int> Plan;
    vector <int> Laby_w_planie;                                   
    set <int> Zajete_terminy;                                     
    set <int>::iterator it;
    
public:
    float Oblicz_kare();
    float Zwroc_kare();
    string Zwroc_kierunek();
    int Zwroc_stopien();
    int Zwroc_rocznik();
    int Zwroc_numer();
    int Zwroc_numer_zaj(int termin);
    int Ile_lab_w_planie();
    int Termin_labek(int ktore);
    int Ile_zajec();
    void Dodanie_do_lab(int termin);
    void Dodanie_do_planu(int termin, int numer_zajecia);            
    void Usuniecie_zaj_terminu(int termin);
    void Usuniecie_lab(int termin);
    void Dodanie_zaj_terminu(int termin);
    
    set <int>::iterator Pierwszy_zaj_termin();
    set <int>::iterator Ostatni_zaj_termin();
    
    Grupa(string kierunek, int stopien, int rocznik, int numer);
    ~Grupa();
};

#endif // GRUPA_H