#include <iostream>
#include <vector>

#include "Nauczyciel.h"

using namespace std;

Nauczyciel::Nauczyciel(string imie_nazwisko)
{
    Imie_Nazwisko = imie_nazwisko;
    Kara = 0;
    Kara_dop = 0;       
    Plan.resize(20);
}
void Nauczyciel::Godziny_wykl(int numer_przedmiotu, int ilosc_godzin)
{
    Wyklady[numer_przedmiotu] = ilosc_godzin;
}

void Nauczyciel::Godziny_cw(int numer_przedmiotu, int ilosc_godzin)
{
    Cwiczenia[numer_przedmiotu] = ilosc_godzin;
}

void Nauczyciel::Godziny_labek(int numer_przedmiotu, int ilosc_godzin)
{
    Laborki[numer_przedmiotu] = ilosc_godzin;
}
set <int>::iterator Nauczyciel::Pierwszy_dop_termin()
{
    return Dopuszczalne_terminy.begin();
}
set <int>::iterator Nauczyciel::Ostatni_dop_termin()
{
    return Dopuszczalne_terminy.end();
}
void Nauczyciel::Dodanie_dop_terminu(int termin)
{
    Dopuszczalne_terminy.insert(termin);
}
int Nauczyciel::Szukaj_dop_terminu(int termin)
{
    if(Dopuszczalne_terminy.count(termin))
        return 1;
    else
        return 0;
}
set <int>::iterator Nauczyciel::Pierwszy_zaj_termin()
{
    return Zajete_terminy.begin();
}
set <int>::iterator Nauczyciel::Ostatni_zaj_termin()
{
    return Zajete_terminy.end();
}
void Nauczyciel::Dodanie_zaj_terminu(int termin)
{
    Zajete_terminy.insert(termin);
}
void Nauczyciel::Usuniecie_zaj_terminu(int termin)
{
    Zajete_terminy.erase(Zajete_terminy.find(termin));
}
void Nauczyciel::Dodanie_niedos_terminu(int termin)
{
    Terminy_niedostepne.insert(termin);
}
void Nauczyciel::Dodanie_do_planu(int numer_zajecia, int termin)
{
    Plan[termin] = numer_zajecia;
}
int Nauczyciel::Numer_zajecia(int termin)
{
    if(Plan[termin] != 0)
        return Plan[termin];
    else 
        return 0;
}
int Nauczyciel::Ile_lab_w_planie()
{
    return Laby_w_planie.size();
}
void Nauczyciel::Dodanie_do_lab(int termin)
{
    Laby_w_planie.push_back(termin);
}
vector <int>::iterator Nauczyciel::Pierwszy_lab_termin()
{
    return Laby_w_planie.begin();
}
vector <int>::iterator Nauczyciel::Ostatni_lab_termin()
{
    return Laby_w_planie.end();
}
int Nauczyciel::Dostepny_wykl(int numer_przedmiotu)
{
    if(Wyklady[numer_przedmiotu] != 0)
    {
        Wyklady[numer_przedmiotu]--;                                            
        return 1;
    }
    else
        return 0;
}
int Nauczyciel::Termin_labek(int ktore)
{
    return Laby_w_planie[ktore];
}
void Nauczyciel::Usuniecie_lab(int termin)
{
    vector <int>::iterator itt = find(Laby_w_planie.begin(), Laby_w_planie.end(), termin);
    Laby_w_planie.erase(itt);
}
int Nauczyciel::Dostepny_cw(int numer_przedmiotu)
{
    if(Cwiczenia[numer_przedmiotu] != 0)
    {
        Cwiczenia[numer_przedmiotu]--;                                         
        return 1;
    }
    else
        return 0;
}
int Nauczyciel::Dostepny_lab(int numer_przedmiotu)
{
    if(Laborki[numer_przedmiotu] != 0)
    {
        Laborki[numer_przedmiotu]--;                                            
        return 1;
    }
    else
        return 0;
}
string Nauczyciel::Zwroc_imie_i_nazwisko()
{
    return Imie_Nazwisko;
}
void Nauczyciel::Zwieksz_kare_dop()
{
    Kara_dop+=0.25;
}
void Nauczyciel::Zmniejsz_kare_dop()
{
    Kara_dop-=0.25;
}
float Nauczyciel::Oblicz_kare()
{
    float kara = 0;                                                             
    int wszys_zajec_nauczyciela = Zajete_terminy.size();                        
    
    int zajecia_obecne = 0;                                                     
    int zajecia_nastepne = 0;                                                   
    int pomocnicza = 0;                                                         
    
    int pier_zaj_w_nas_dniu = 0;                                                
    
    it = Zajete_terminy.begin();                                                
    zajecia_obecne = *it;                                                       
    ++it; 
    zajecia_nastepne = *it;                                                      
                                                                                
    
    for(int j = 0; j < wszys_zajec_nauczyciela+1; j++)
    {
        if(zajecia_obecne >= pier_zaj_w_nas_dniu)                               
        {                                                                       
            pier_zaj_w_nas_dniu += 4;                                           
        }
        
        if(zajecia_obecne < pier_zaj_w_nas_dniu)                                            
        {
            if(zajecia_nastepne < pier_zaj_w_nas_dniu)                                      
            {
                if(zajecia_obecne == 0){pomocnicza = zajecia_nastepne;}
                else if(zajecia_obecne == 1){pomocnicza = zajecia_nastepne-1;}
                else{pomocnicza = zajecia_nastepne % zajecia_obecne;}
                        
                
                if(pomocnicza == 2)
                {
                    kara+=1;
                }
                else if(pomocnicza == 3)
                {
                    kara+=2;
                }
            }

            zajecia_obecne = zajecia_nastepne;                                                  
            it++;                                                                               
            zajecia_nastepne = *it;                                                                      
        }                                         
    }
    
    Kara = kara + Kara_dop;                                                                     
    
    return Kara;                                                                                
}
float Nauczyciel::Zwroc_kare()
{
    return Kara;
}
void Nauczyciel::Wypisz_poz_w_plan(int numer_terminu)
{
    cout << Plan[numer_terminu] << " ";
}
int Nauczyciel::Ile_zajec()
{
    return Zajete_terminy.size();
}
void Nauczyciel::Wypisz_przedmioty()
{
    for(map<int,int>::iterator it = Laborki.begin();it != Laborki.end(); ++it)
    {
        cout << "Przedmiot: " << it->first << "Ilosc godzin:" << it->second;
        cout << endl;
    }
}
set <int>::iterator Nauczyciel::Pierwszy_niedop_termin()
{
    return Terminy_niedostepne.begin();
}
set <int>::iterator Nauczyciel::Ostatni_niedop_termin()
{
    return Terminy_niedostepne.end();
}
Nauczyciel::~Nauczyciel()
{
}

