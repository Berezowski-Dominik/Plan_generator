#include "Grupa.h"

Grupa::Grupa(string kierunek, int stopien, int rocznik, int numer)
{
    Kierunek = kierunek;
    Stopien = stopien;
    Rocznik = rocznik;
    Numer = numer;
    Kara = 0;
    Plan.resize(20);
}

float Grupa::Oblicz_kare()
{
    float kara = 0;                                                             
    int wszys_zajec_grupy = Zajete_terminy.size();                              
    
    int zajecia_obecne = 0;                                                     
    int zajecia_nastepne = 0;                                                   
    int pomocnicza = 0;                                                         
    
    int ilosc_zaje_w_dniu = 0;                                                 
    
    int pier_zaj_w_nas_dniu = 0;                                               
    
    it = Zajete_terminy.begin();                                                
    zajecia_obecne = *it;                                                       
    ++it; 
    zajecia_nastepne = *it;                                                     
                                                                                
                                                                                
    if(zajecia_obecne < 4)                                                      
        kara += zajecia_obecne*0.25;                                            
    
    for(int j = 0; j < wszys_zajec_grupy+1; j++)
    {
        if(zajecia_obecne >= pier_zaj_w_nas_dniu)                              
        {                                                                       
            pier_zaj_w_nas_dniu += 4;                                           
        }
        
        if(zajecia_obecne < pier_zaj_w_nas_dniu)                                            
        {
            ilosc_zaje_w_dniu++;                                                            
            
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
            else if(zajecia_nastepne % pier_zaj_w_nas_dniu >= 4)                    
            {                                                                      
                pier_zaj_w_nas_dniu += 4;                                           
                ilosc_zaje_w_dniu--;                                                
                j--;                                                                
                continue;
            }
            else if(zajecia_nastepne % pier_zaj_w_nas_dniu < 4)                                
            {
                
                if(ilosc_zaje_w_dniu == 1)                                                      
                {                                                                               
                    kara+=0.5;                                      
                }
                ilosc_zaje_w_dniu = 0;                                                          

                if(zajecia_nastepne % pier_zaj_w_nas_dniu == 1)                                 
                {
                    kara+=0.25;
                }
                else if(zajecia_nastepne % pier_zaj_w_nas_dniu == 2)                            
                {
                    kara+=0.5;
                }
                else if(zajecia_nastepne % pier_zaj_w_nas_dniu == 3)                            
                {
                    kara+=0.75;
                }
            }
            
            zajecia_obecne = zajecia_nastepne;                                               
            it++;                                                                            
            zajecia_nastepne = *it;                                                               
                                                                                             
            if(it == Zajete_terminy.end())                                                   
            {
                zajecia_nastepne = pier_zaj_w_nas_dniu+4;
            }
        }                                         
    }
    
    Kara = kara;                                                                            
    
    return kara;
}
string Grupa::Zwroc_kierunek()
{
    return Kierunek;
}
int Grupa::Zwroc_stopien()
{
    return Stopien;
}
int Grupa::Zwroc_rocznik()
{
    return Rocznik;
}
int Grupa::Zwroc_numer()
{
    return Numer;
}
float Grupa::Zwroc_kare()
{
    return Kara;
}
int Grupa::Zwroc_numer_zaj(int termin)
{
    if(Plan[termin] != 0)
        return Plan[termin];
    else 
        return 0;
}
void Grupa::Dodanie_do_planu(int termin, int numer_zajecia)
{
    Plan[termin] = numer_zajecia;
}
int Grupa::Ile_lab_w_planie()
{
    return Laby_w_planie.size();
}
int Grupa::Termin_labek(int ktore)
{
    return Laby_w_planie[ktore];
}
void Grupa::Dodanie_do_lab(int termin)
{
    Laby_w_planie.push_back(termin);
}
void Grupa::Usuniecie_zaj_terminu(int termin)
{
    Zajete_terminy.erase(Zajete_terminy.find(termin));
}
void Grupa::Usuniecie_lab(int termin)
{
    vector <int>::iterator itt = find(Laby_w_planie.begin(), Laby_w_planie.end(), termin);
    Laby_w_planie.erase(itt);
}
int Grupa::Ile_zajec()
{
    return Zajete_terminy.size();
}
set <int>::iterator Grupa::Pierwszy_zaj_termin()
{
    return Zajete_terminy.begin();
}
set <int>::iterator Grupa::Ostatni_zaj_termin()
{
    return Zajete_terminy.end();
}
void Grupa::Dodanie_zaj_terminu(int termin)
{
    Zajete_terminy.insert(termin);
}

Grupa::~Grupa()
{
}

