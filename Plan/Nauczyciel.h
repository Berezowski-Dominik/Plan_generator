#ifndef NAUCZYCIEL_H
#define NAUCZYCIEL_H

#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Nauczyciel
{
private:

    string Imie_Nazwisko;
    float Kara;                                             
    float Kara_dop;                                         
    
    map <int, int> Wyklady;                                 
    map <int, int> Cwiczenia;                               
    map <int, int> Laborki;                                 
    
    set <int> Dopuszczalne_terminy;                         
    set <int> Zajete_terminy;                               
    set <int> Terminy_niedostepne;                          
    set <int>::iterator it;
    
    vector <int> Plan;                                      
    vector <int> Laby_w_planie;                              
    
    public:
    
    int Dostepny_wykl(int numer_przedmiotu);                    
    int Dostepny_cw(int numer_przedmiotu);                      
    int Dostepny_lab(int numer_przedmiotu);                     
    int Szukaj_dop_terminu(int termin);
    int Numer_zajecia(int termin);
    int Ile_lab_w_planie();
    int Termin_labek(int ktore);
    int Ile_zajec();

    void Godziny_wykl(int numer_przedmiotu, int ilosc_godzin);
    void Godziny_cw(int numer_przedmiotu, int ilosc_godzin);
    void Godziny_labek(int numer_przedmiotu, int ilosc_godzin);
    
    void Dodanie_dop_terminu(int termin);
    void Dodanie_zaj_terminu(int termin);
    void Dodanie_niedos_terminu(int termin);
    void Dodanie_do_planu(int numer_zajecia, int termin);
    void Dodanie_do_lab(int termin);
    
    void Usuniecie_zaj_terminu(int termin);
    void Usuniecie_lab(int termin);
    
    void Wypisz_przedmioty();
    void Wypisz_poz_w_plan(int numer_terminu);
    float Zwroc_kare();                                         
    string Zwroc_imie_i_nazwisko();
    
    float Oblicz_kare();                                        
    void Zwieksz_kare_dop();
    void Zmniejsz_kare_dop();
    
    set <int>::iterator Pierwszy_dop_termin();
    set <int>::iterator Ostatni_dop_termin();
    
    vector <int>::iterator Pierwszy_lab_termin();
    vector <int>::iterator Ostatni_lab_termin();
    
    set <int>::iterator Pierwszy_zaj_termin();
    set <int>::iterator Ostatni_zaj_termin();
    
    set <int>::iterator Pierwszy_niedop_termin();
    set <int>::iterator Ostatni_niedop_termin();
    
    Nauczyciel(string imie_nazwisko);
    ~Nauczyciel();
};

#endif // NAUCZYCIEL_H
