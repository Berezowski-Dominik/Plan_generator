#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <map>
#include <cmath>
#include <set>
#include <ctime>
#include <algorithm>
#include <sys/stat.h>

#include "Przedmiot.h"
#include "Nauczyciel.h"
#include "Nad_grupa.h"
#include "Grupa.h"
#include "Zajecia.h"
#include "Sala.h"

using namespace std;

int Wczytanie_Przedmiotow(vector<vector<Przedmiot>>&Przedmioty_Lab,vector<vector<Przedmiot>>&Przedmioty_Cw,vector<vector<Przedmiot>>&Przedmioty_Wykl);

int Wczytanie_Nauczycieli(vector < Nauczyciel> &Nauczyciele);

void Wczytanie_Grup(vector <vector<Nad_grupa>> &Grupy_Wyk, vector <vector<Nad_grupa>> &Grupy_Cw, vector<vector<Grupa>> &Grupy_Lab);

void Wczytanie_Sal(vector <Sala> &Sala_Wykl,vector <Sala> &Sala_Cw,vector <Sala> &Sala_Lab);

int Czy_istnieje_plik(const char* nazwa_pliku);                    

void Podzial_nauczycieli_i_przedmiotow();                           

void Dop_godz_nauczycieli(vector < Nauczyciel> &Nauczyciele);  

void Niedop_godz_nauczycieli(vector < Nauczyciel> &Nauczyciele);

void Grup_Wyk_Podz(vector <vector<Nad_grupa>> &Grupy_Wyk,vector <vector<Grupa>> &Grupy_Lab,vector <vector<Nad_grupa>> &Grupy_Cw);

void Grup_Cw_Podz(vector<vector<Nad_grupa>> &Grupy_Cw, vector <vector<Grupa>> &Grupy_Lab);

void Wczytanie_nauczycieli_wykladow(vector <vector<Przedmiot>> &Przedmioty_Wykl,vector <Nauczyciel> &Nauczyciele);

void Wczytanie_nauczycieli_cwiczen(vector <vector<Przedmiot>> &Przedmioty_Cw,vector < Nauczyciel> &Nauczyciele);

void Wczytanie_nauczycieli_laborek(vector <vector<Przedmiot>> &Przedmioty_Lab,vector < Nauczyciel> &Nauczyciele);

void Zajecia_wykladowe(vector <Zajecia> &Zajecie,vector<vector<Przedmiot>> &Przedmioty_Wykl,vector <vector<Nad_grupa>> &Grupy_Wyk,vector<Sala> &Sala_Wykl,int &il_wykl);

void Zajecia_cwiczeniowe(vector <Zajecia> &Zajecie,vector<vector<Przedmiot>> &Przedmioty_Cw,vector <vector<Nad_grupa>> &Grupy_Cw,vector<Sala> &Sala_Cw, int &il_wykl_i_cw);

void Zajecia_laborki(vector <Zajecia> &Zajecie,vector <vector<Przedmiot>> &Przedmioty_Lab,vector <vector<Grupa>> &Grupy_Lab,vector<Sala> &Sala_Lab);

void Zajecia_nauczyciele(vector<Zajecia> &Zajecie,vector<Nauczyciel> &Nauczyciele,int il_wykl,int il_wykl_i_cw);

void Tworzenie_harmonogramu(vector <Zajecia> &Zajecie);

void Wypisanie_danych_harmonogramu(vector <Zajecia> &Zajecie,vector <vector<Grupa>> &Grupy_Lab, vector <Nauczyciel> &Nauczyciele);

float Kara_laczna_grup(vector<vector<Grupa>> &Grupy_Lab);

float Kara_laczna_nauczycieli(vector <Nauczyciel> &Nauczyciele);

float Ogolna_kara_planu(vector <vector<Grupa>> &Grupy_Lab,vector <Nauczyciel> &Nauczyciele);

void Poprawianie_grupy(vector <Zajecia> &Zajecie,vector <float>::iterator &it, vector <float> &kara_grupy, vector <Grupa*> &Grupy_Lab, int &najg_grupa);

void Poprawianie_nauczycieli(vector <Zajecia> &Zajecie,vector <float>::iterator &it, vector <float> &kara_nauczy, vector <Nauczyciel> &Nauczyciele, int &najg_nauczy);

void Poprawianie_harmonogramu(vector <Zajecia> &Zajecie,vector <vector<Grupa>> &Grupy_Lab,vector <Nauczyciel> &Nauczyciele, vector <Sala> Sala_Lab, int ile_popraw);

void Wypisywanie_planow_grup(vector <vector<Grupa>> &Grupy_Lab,vector <Zajecia> &Zajecie_Naj); 

void Wypisywanie_planow_nauczycieli(vector <Nauczyciel> &Nauczyciele_Naj,vector <Zajecia> &Zajecie_Naj);   

int main(int argc, char **argv)
{
    srand(time(NULL));
    
    fstream plik;
    
    vector<vector<Przedmiot>>Przedmioty_Lab;
    vector<vector<Przedmiot>>Przedmioty_Cw;
    vector<vector<Przedmiot>>Przedmioty_Wykl;
    
    vector<vector<Grupa>>Grupy_Lab;
    vector<vector<Nad_grupa>>Grupy_Cw;
    vector<vector<Nad_grupa>>Grupy_Wykl;
    
    vector <Sala> Sala_Wykl;
    vector <Sala> Sala_Cw;
    vector <Sala> Sala_Lab;
    
    vector <Zajecia> Zajecie;
    
    vector<Nauczyciel>Nauczyciele;
    
    int il_wykl = 0;                                                                
    int il_wykl_i_cw = 0;                                                           
    
    if(Czy_istnieje_plik("wyklady_nauczyciele.csv") == 0)                           
    {
        cout << "Brak koniecznych pilkow do stworzenia planiu !!!" << endl;         
        cout << "Uzupelnij stworzone plik w katalogu programu: " << endl;
        cout << "wyklady_nauczyciele.csv,cwiczenia_nauczyciele.csv,laborki_nauczyciele.csv" << endl;
        Podzial_nauczycieli_i_przedmiotow();                                        
    }
    else if(Czy_istnieje_plik("wyklady_nauczyciele.csv") != 0)                                  
    {
         Wczytanie_Przedmiotow(Przedmioty_Lab,Przedmioty_Cw,Przedmioty_Wykl);                   
         Wczytanie_Nauczycieli(Nauczyciele);                                                    
         Wczytanie_Grup(Grupy_Wykl,Grupy_Cw,Grupy_Lab);                                         
         Wczytanie_Sal(Sala_Wykl,Sala_Cw,Sala_Lab);                                             
         Grup_Wyk_Podz(Grupy_Wykl,Grupy_Lab,Grupy_Cw);                                          
         Grup_Cw_Podz(Grupy_Cw,Grupy_Lab);                                                      
         Wczytanie_nauczycieli_wykladow(Przedmioty_Wykl,Nauczyciele);                           
         Wczytanie_nauczycieli_cwiczen(Przedmioty_Cw,Nauczyciele);                              
         Wczytanie_nauczycieli_laborek(Przedmioty_Lab,Nauczyciele);                             
         Zajecia_wykladowe(Zajecie,Przedmioty_Wykl,Grupy_Wykl,Sala_Wykl,il_wykl);               
         Zajecia_cwiczeniowe(Zajecie,Przedmioty_Cw,Grupy_Cw,Sala_Cw,il_wykl_i_cw);              
         Zajecia_laborki(Zajecie,Przedmioty_Lab,Grupy_Lab,Sala_Lab);                            
         Zajecia_nauczyciele(Zajecie,Nauczyciele,il_wykl,il_wykl_i_cw);                         
         Tworzenie_harmonogramu(Zajecie);                                                       
         Poprawianie_harmonogramu(Zajecie,Grupy_Lab,Nauczyciele,Sala_Lab,10);                    
         cout <<"Kara najlepszego rozwiazania wynosi: " << Ogolna_kara_planu(Grupy_Lab,Nauczyciele) << endl; 
         Wypisywanie_planow_grup(Grupy_Lab,Zajecie);    
         Wypisywanie_planow_nauczycieli(Nauczyciele,Zajecie);
    }
    
    return 0;
}
void Wypisywanie_planow_nauczycieli(vector <Nauczyciel> &Nauczyciele,vector <Zajecia> &Zajecie)
{
    int ilosc_nauczycieli = Nauczyciele.size();
    
    string nazwa_pliku;                                         
    ofstream plik;                                               
    
    nazwa_pliku.append("plany_nauczycieli.csv");
    plik.open(nazwa_pliku,ios::out);
    
    string do_pliku;
    
    for(int i = 0; i < ilosc_nauczycieli; i++)                                          
    {
        do_pliku.append(Nauczyciele[i].Zwroc_imie_i_nazwisko());
        do_pliku.append("\n");        
        
        for(int j = 0; j < 4; j++)                                                      
        {
            for(int k = 0; k < 20; k+=4)
            {
                if(Nauczyciele[i].Numer_zajecia(k+j) != 0)                              
                {
                    do_pliku.append(Zajecie[Nauczyciele[i].Numer_zajecia(k+j)-1].przedmiot()->Zwroc_nazwe());
                    do_pliku.append(" ");
                    do_pliku.append(to_string(Zajecie[Nauczyciele[i].Numer_zajecia(k+j)-1].sala()->Zwroc_numer()));
                    do_pliku.append(" ");
                    if(Zajecie[Nauczyciele[i].Numer_zajecia(k+j)-1].nad_grupa() == NULL)
                    {
                        do_pliku.append(Zajecie[Nauczyciele[i].Numer_zajecia(k+j)-1].grupa()->Zwroc_kierunek());
                        do_pliku.append(to_string(Zajecie[Nauczyciele[i].Numer_zajecia(k+j)-1].grupa()->Zwroc_stopien()));
                        do_pliku.append(to_string(Zajecie[Nauczyciele[i].Numer_zajecia(k+j)-1].grupa()->Zwroc_rocznik()));
                        do_pliku.append(to_string(3));
                        do_pliku.append(to_string(Zajecie[Nauczyciele[i].Numer_zajecia(k+j)-1].grupa()->Zwroc_numer()));
                    }
                    if(Zajecie[Nauczyciele[i].Numer_zajecia(k+j)-1].nad_grupa() != NULL)
                    {
                        do_pliku.append(Zajecie[Nauczyciele[i].Numer_zajecia(k+j)-1].nad_grupa()->grupa_lab(0)->Zwroc_kierunek());
                        do_pliku.append(to_string(Zajecie[Nauczyciele[i].Numer_zajecia(k+j)-1].nad_grupa()->grupa_lab(0)->Zwroc_stopien()));
                        do_pliku.append(to_string(Zajecie[Nauczyciele[i].Numer_zajecia(k+j)-1].nad_grupa()->grupa_lab(0)->Zwroc_rocznik()));
                        do_pliku.append(to_string(Zajecie[Nauczyciele[i].Numer_zajecia(k+j)-1].nad_grupa()->Zwroc_rodzaj()));
                        do_pliku.append(to_string(Zajecie[Nauczyciele[i].Numer_zajecia(k+j)-1].nad_grupa()->Zwroc_numer_grupy()));
                    }
                    do_pliku.append(",");
                }
                else                                                                    
                {
                    do_pliku.append("Wolne,");
                }
            }
            do_pliku.append("\n"); 
            plik << do_pliku;
            do_pliku.clear();                                                  
        }
        do_pliku.append("\n");
    }
    plik.close();
}

void Wypisywanie_planow_grup(vector <vector<Grupa>> &Grupy_Lab,vector <Zajecia> &Zajecie)
{
    int ilosc_zbiorow_grup = Grupy_Lab.size();
    int ilosc_grup = 0;
    
    string nazwa_pliku;                                         
    ofstream plik;                                               
    
    for(int l = 0; l < ilosc_zbiorow_grup; l++)
    {
        nazwa_pliku.append(Grupy_Lab[l][0].Zwroc_kierunek());
        nazwa_pliku.append(to_string(Grupy_Lab[l][0].Zwroc_stopien()));
        nazwa_pliku.append(to_string(Grupy_Lab[l][0].Zwroc_rocznik()));
        nazwa_pliku.append(".csv");
        
        plik.open(nazwa_pliku,ios::out);
        
        nazwa_pliku.clear();
    
        string do_pliku;
    
        ilosc_grup = Grupy_Lab[l].size();                                           
    
        for(int i = 0; i < ilosc_grup; i++)                                         
        {
            do_pliku.append("Grupa");
            do_pliku.append(to_string(Grupy_Lab[l][i].Zwroc_numer()));
            do_pliku.append("\n");        
            
            for(int j = 0; j < 4; j++)                                              
            {
                for(int k = 0; k < 20; k+=4)
                {
                    if(Grupy_Lab[l][i].Zwroc_numer_zaj(k+j) != 0)                     
                    {
                        do_pliku.append(Zajecie[Grupy_Lab[l][i].Zwroc_numer_zaj(k+j)-1].przedmiot()->Zwroc_nazwe());
                        do_pliku.append(" ");
                        do_pliku.append(Zajecie[Grupy_Lab[l][i].Zwroc_numer_zaj(k+j)-1].Zwroc_imie_i_nazwisko_nauczyciela());
                        do_pliku.append(" ");
                        do_pliku.append(to_string(Zajecie[Grupy_Lab[l][i].Zwroc_numer_zaj(k+j)-1].sala()->Zwroc_numer()));
                        do_pliku.append(",");
                    }
                    else                                                            
                    {
                        do_pliku.append("Wolne,");
                    }
                }
                do_pliku.append("\n"); 
                plik << do_pliku;
                do_pliku.clear();                                           
            }
            do_pliku.append("\n");
        }
        plik.close();
    }
}
void Podzial_nauczycieli_i_przedmiotow()                                    
{
    vector<Nauczyciel> nauczyciele;                                         
    
    vector<vector<Przedmiot>> przedmioty_lab;
    vector<vector<Przedmiot>> przedmioty_cw;
    vector<vector<Przedmiot>> przedmioty_wykl;
    
    vector<vector<Grupa>> grupy_lab;
    vector<vector<Nad_grupa>> grupy_cw;
    vector<vector<Nad_grupa>> grupy_wykl;
    
    Wczytanie_Nauczycieli(nauczyciele);                                     
    
    Wczytanie_Przedmiotow(przedmioty_lab,przedmioty_cw,przedmioty_wykl);    
    
    Wczytanie_Grup(grupy_wykl,grupy_cw,grupy_lab);                          
    
    int ilosc_zbiorow_wykladow = przedmioty_wykl.size();                    
    int ilosc_zbiorow_cwiczen = przedmioty_cw.size();
    int ilosc_zbiorow_laborek = przedmioty_lab.size();
    
    int ilosc_nauczycieli = nauczyciele.size();
    int ilosc_wykladow = 0;
    int ilosc_cwiczen = 0;
    int ilosc_laborek = 0;
    
    ofstream plik;
    plik.open("wyklady_nauczyciele.csv",ios::out);
    
    for(int i = 0; i < ilosc_zbiorow_wykladow; i++)                         
    {
        ilosc_wykladow = przedmioty_wykl[i].size();                         
        
        for(int j = 0; j < ilosc_wykladow; j++)
        {
            plik << ",";
            plik << przedmioty_wykl[i][j].Zwroc_nazwe();
        }
        plik << ",Ilosc grup-";
        plik << grupy_wykl[i].size();
        plik << ",";
    }
    plik << "\n";
    for(int i = 0; i < ilosc_nauczycieli; i++)                              
    {
        plik << nauczyciele[i].Zwroc_imie_i_nazwisko();
        plik << ",\n";
    }
    plik.close();
    
    plik.open("cwiczenia_nauczyciele.csv",ios::out);
    
    for(int i = 0; i < ilosc_zbiorow_cwiczen; i++)                          
    {
        ilosc_cwiczen = przedmioty_cw[i].size();                            
        
        for(int j = 0; j < ilosc_cwiczen; j++)
        {
            plik << ",";
            plik << przedmioty_cw[i][j].Zwroc_nazwe();
        }
        plik << ",Ilosc grup-";
        plik << grupy_cw[i].size();
        plik << ",";
    }
    plik << "\n";
    for(int i = 0; i < ilosc_nauczycieli; i++)                          
    {
        plik << nauczyciele[i].Zwroc_imie_i_nazwisko();
        plik << ",\n";
    }
    plik.close();
    
    plik.open("laborki_nauczyciele.csv",ios::out);
    
    for(int i = 0; i < ilosc_zbiorow_laborek; i++)                      
    {
        ilosc_laborek = przedmioty_lab[i].size();                       
        
        for(int j = 0; j < ilosc_laborek; j++)
        {
            plik << ",";
            plik << przedmioty_lab[i][j].Zwroc_nazwe();
        }
        plik << ",Ilosc grup-";
        plik << grupy_lab[i].size();
        plik << ",";
    }
    plik << "\n";
    for(int i = 0; i < ilosc_nauczycieli; i++)                          
    {
        plik << nauczyciele[i].Zwroc_imie_i_nazwisko();
        plik << ",\n";
    }
    plik.close();
}

float Ogolna_kara_planu(vector <vector<Grupa>> &Grupy_Lab,vector <Nauczyciel> &Nauczyciele)               
{
    return Kara_laczna_grup(Grupy_Lab) + Kara_laczna_nauczycieli(Nauczyciele);
}
void Poprawianie_nauczycieli(vector <Zajecia> &Zajecie,vector <float>::iterator &it, vector <float> &kara_nauczy, vector <Nauczyciel> &Nauczyciele, int &najg_nauczy)
{
    vector <int> pozyc_labek;           
                                        
        
    vector <int> sprawdz_nauczy;        
                                       
                                        
                                            
    int labki = 0;                     
            
    int ile_spraw_naucz = 0;            
    
    int i = 0;                          
        
    while(i == 0)                       
    { 
        int ilosc_labek = Nauczyciele[najg_nauczy].Ile_lab_w_planie();                          
        for(int i = 0; i < ilosc_labek; i++)                                                                           
        {                                                                                       
            pozyc_labek.push_back(Nauczyciele[najg_nauczy].Termin_labek(i));
        }
            
        ilosc_labek++;                              
                                                    
        pozyc_labek.push_back(20);                  
            
        labki = ilosc_labek-1;                      
            
        do                                          
        {       
            pozyc_labek.erase(pozyc_labek.begin()+labki);                                                                                   
            ilosc_labek--;                                  
                                                                                                        
            labki = rand() % ilosc_labek;                                                                  
                
        }while((!Zajecie[Nauczyciele[najg_nauczy].Numer_zajecia(pozyc_labek[labki])-1].Mozliwosc_zmiany()) || (ilosc_labek == 0));
            
        if(ilosc_labek == 0)                                        
        {
            i--;                                                    
            kara_nauczy[najg_nauczy] = 0;                           
            sprawdz_nauczy.push_back(najg_nauczy);                  
                
            it = max_element(kara_nauczy.begin(),kara_nauczy.end());                                
            najg_nauczy = distance(kara_nauczy.begin(), it);                                        
        }
        else                                                                            
        {
            Zajecie[Nauczyciele[najg_nauczy].Numer_zajecia(pozyc_labek[labki])-1].Zmiana_terminu();
            kara_nauczy[najg_nauczy] = Nauczyciele[najg_nauczy].Zwroc_kare();           
            
            ile_spraw_naucz = sprawdz_nauczy.size();   
            for(int i = 0; i < ile_spraw_naucz; i++)                 
            {                                                       
                kara_nauczy[sprawdz_nauczy[i]] = Nauczyciele[sprawdz_nauczy[i]].Zwroc_kare();
            }
        }
    
        sprawdz_nauczy.clear();                                             
        pozyc_labek.clear();
        
        it = max_element(kara_nauczy.begin(),kara_nauczy.end());            
        najg_nauczy = distance(kara_nauczy.begin(), it);                  

        i++;
    }
}
void Poprawianie_grupy(vector <Zajecia> &Zajecie,vector <float>::iterator &it, vector <float> &kara_grupy, vector <Grupa*> &Grupy_Lab,int &najg_grupa)
{
    vector <int> pozyc_labek;           
                                        
        
    vector <int> sprawdzone_grupy;      
                                        
                                        
                                            
    int labki = 0;                      
        
    int ile_spraw_grup = 0;             
    
    int i = 0;                          
        
    while(i == 0)                       
    { 
        int ilosc_labek = Grupy_Lab[najg_grupa]->Ile_lab_w_planie();                            
        for(int i = 0; i < ilosc_labek; i++)                                                                          
        {                                                                                       
            pozyc_labek.push_back(Grupy_Lab[najg_grupa]->Termin_labek(i));
        }
            
        ilosc_labek++;                              
                                                    
        pozyc_labek.push_back(20);                  
            
        labki = ilosc_labek-1;                      
            
        do                                          
        {       
            pozyc_labek.erase(pozyc_labek.begin()+labki);                                                                                   
            ilosc_labek--;                                  
                                                                                                        
            labki = rand() % ilosc_labek;                                                                  
                
        }while((!Zajecie[Grupy_Lab[najg_grupa]->Zwroc_numer_zaj(pozyc_labek[labki])-1].Mozliwosc_zmiany()) || (ilosc_labek == 0));
            
        if(ilosc_labek == 0)                                        
        {
            i--;                                                    
            kara_grupy[najg_grupa] = 0;                             
            sprawdzone_grupy.push_back(najg_grupa);                 
                
            it = max_element(kara_grupy.begin(),kara_grupy.end());                                  
            najg_grupa = distance(kara_grupy.begin(), it);                                          
        }
        else                                                                
        {
            Zajecie[Grupy_Lab[najg_grupa]->Zwroc_numer_zaj(pozyc_labek[labki])-1].Zmiana_terminu();
            kara_grupy[najg_grupa] = Grupy_Lab[najg_grupa]->Zwroc_kare();    
            
            ile_spraw_grup = sprawdzone_grupy.size();   
            for(int i = 0; i < ile_spraw_grup; i++)                   
            {                                                       
                kara_grupy[sprawdzone_grupy[i]] = Grupy_Lab[sprawdzone_grupy[i]]->Zwroc_kare();
            }
        }
    
        sprawdzone_grupy.clear();                                       
        pozyc_labek.clear();
        
        it = max_element(kara_grupy.begin(),kara_grupy.end());          
        najg_grupa = distance(kara_grupy.begin(), it);                  

        i++;
    }
}
float Kara_laczna_grup(vector<vector<Grupa>> &Grupy_Lab)
{
    int ilosc_zbiorow_grup = Grupy_Lab.size();
    float suma_kar = 0;
    
    for(int j = 0; j < ilosc_zbiorow_grup;j++)
    {
        int ilosc_grup = Grupy_Lab[j].size();
        
        for(int i = 0; i < ilosc_grup; i++)
        {
            suma_kar += Grupy_Lab[j][i].Oblicz_kare();
        }
    }
    
    return suma_kar;
}

float Kara_laczna_nauczycieli(vector < Nauczyciel> &Nauczyciele)
{
    int ilosc_nauczycieli = Nauczyciele.size();
    float suma_kar = 0;
    
    for(int i = 0; i < ilosc_nauczycieli; i++)
    {
        suma_kar += Nauczyciele[i].Oblicz_kare();
    }
    
    return suma_kar;
}
void Grup_Cw_Podz(vector <Nad_grupa> &Grupy_Cw, vector <Grupa> &Grupy_Lab,vector <Nad_grupa> &Grupy_Wyk)
{
    int Wszystkie_gr_lab = Grupy_Lab.size();               
    float nie_przydzielone_gr_lab = Grupy_Lab.size();       
    int ilosc_gr_do_stworzenia = Grupy_Cw.size();         
    float wielkosc_nowa_gr_cwiczeniowa = 0;       
    
    for (int i = ilosc_gr_do_stworzenia; i > 0; i--)               
    {
        wielkosc_nowa_gr_cwiczeniowa = round(nie_przydzielone_gr_lab / i);

        for(int j = 0; j < wielkosc_nowa_gr_cwiczeniowa; j++)
        {
            Grupy_Cw[ilosc_gr_do_stworzenia - i].grupa_lab()->push_back(&Grupy_Lab[j + Wszystkie_gr_lab - nie_przydzielone_gr_lab]);
        }
        
        nie_przydzielone_gr_lab -= wielkosc_nowa_gr_cwiczeniowa;
    }
}
int Wczytanie_Nauczycieli(vector < Nauczyciel> &Nauczyciele)
{
    fstream plik;
    plik.open("nauczyciele.csv", ios::in | ios::out);
    
    if(plik.is_open())
    {
        cout << "Poprawne otwarcie pliku z nauczycielami" << endl; 

        string linia;                                           
        string czesc;
        vector <string> dane;
        int i = 0;
        
        while(!plik.eof())                                              
        {
            plik >> linia;
            
            if(linia == ";")                                            
            {
                break;
                return 1;
            }
            else
            {
                if(linia == "")
                    cout << "Blad w wierszu " << i << endl;
                else
                    Nauczyciele.push_back({linia});                         
            }
            i++;
        }
        plik.close();
    }
    else
        cout<<"Nie udało się otworzyć pliku z nauczycielami";
        
    return 1;
}
void Dop_godz_nauczycieli(vector < Nauczyciel> &Nauczyciele)
{
    fstream plik;
    plik.open("dop_term_nauczycieli.csv", ios::in | ios::out);
    
    int numer = 0;
    
    if(plik.is_open())
    {
        cout << "Plik z dopuszczalnymi terminami nauczycieli otwarty" << endl << endl;
        
        string linia;                                           
        string czesc;
        vector <string> dane;
        
        int ile_godzin = 0;                                     
        
        while(!plik.eof())                                      
        {
            plik >> linia;
            
            if(linia == ";")
                break;
        
            stringstream strumien(linia);
            while(getline(strumien,czesc,','))
            {
                dane.push_back(czesc);
            }
            
            if(dane[0] == "")                                    
            {                                                   
                dane.erase(dane.begin(), dane.end());
                numer++;                                        
                continue;                                       
            }
            else if(dane[0] != "")                              
            {                                                   
                ile_godzin = dane.size();                       
                for(int i = 0; i < ile_godzin; i++)
                {
                    Nauczyciele[numer].Dodanie_dop_terminu(stoi(dane[i])-1);     
                }
                dane.erase(dane.begin(), dane.end());
                numer++;
            }
        }
        plik.close();
    }
    else
        cout<<"Nie udało się otworzyć pliku z dopuszczalnymi terminami nauczycieli";
}
void Niedop_godz_nauczycieli(vector < Nauczyciel> &Nauczyciele)
{
    fstream plik;
    plik.open("niedop_term_nauczycieli.csv", ios::in | ios::out);
    
    int numer = 0;
    
    if(plik.is_open())
    {
        cout << "Plik z niedopuszczalnymi terminami nauczycieli otwarty" << endl << endl;
        
        string linia;                                           
        string czesc;
        vector <string> dane;
        
        int ile_godzin = 0;                                     
        
        while(!plik.eof())                                      
        {
            plik >> linia;
            
            if(linia == ";")
                break;
        
            stringstream strumien(linia);
            while(getline(strumien,czesc,','))
            {
                dane.push_back(czesc);
            }
            
            if(dane[0] == "")                                    
            {                                                   
                dane.erase(dane.begin(), dane.end());
                numer++;                                        
                continue;                                        
            }
            else if(dane[0] != "")                              
            {                                                   
                ile_godzin = dane.size();                       
                for(int i = 0; i < ile_godzin; i++)
                {
                    Nauczyciele[numer].Dodanie_niedos_terminu(stoi(dane[i])-1);    
                    Nauczyciele[numer].Dodanie_zaj_terminu(stoi(dane[i])-1);                         
                }
                dane.erase(dane.begin(), dane.end());
                numer++;
            }
        }
        plik.close();
    }
    else
        cout<<"Nie udało się otworzyć pliku z niedopuszczalnymi terminami nauczycieli";
}
int Wczytanie_Przedmiotow(vector<vector<Przedmiot>>&Przedmioty_Lab,vector<vector<Przedmiot>>&Przedmioty_Cw,vector<vector<Przedmiot>>&Przedmioty_Wykl)
{
    string linia;                                           
    string czesc;
    vector <string> dane;
        
    int numer_wyk = 0;
    int numer_cw = 0;
    int numer_lab = 0;
    
    int przedmioty = 0;                                     
    int numer_wiersza = 1;                                  
        
    Przedmioty_Wykl.push_back(vector<Przedmiot>());         
    Przedmioty_Cw.push_back(vector<Przedmiot>());           
    Przedmioty_Lab.push_back(vector<Przedmiot>());          
    
    fstream plik;
    plik.open("przedmioty.csv", ios::in | ios::out);
    if(plik.is_open())
	{
        cout << "Poprawne otwarcie pliku z przedmiotami" << endl;
        
        while(!plik.eof())                                          
        {
            plik >> linia;                                          
                
            stringstream strumien(linia);
            while(getline(strumien,czesc,','))
            {
                dane.push_back(czesc);
            }
            if(dane[0] == "" && dane[1] == "")                      
            {                                                   
                Przedmioty_Wykl.push_back(vector<Przedmiot>());            
                Przedmioty_Cw.push_back(vector<Przedmiot>());           
                Przedmioty_Lab.push_back(vector<Przedmiot>());
                przedmioty++;                                       
            }
            else if(dane[0] == ";")                                 
            {
                break;
                return 1;
            }
            else                                                    
            {
                if(dane[0] == "") {cout << "Brak nazwy przedmiotu w wierszu " << numer_wiersza << endl; return 0;}
                if((dane[1] == "") || ((dane[1] != "1") && (dane[1] != "2") && (dane[1] != "3"))) {cout << "Bledna wartosc w 2 kolumnie wiersza " << numer_wiersza << endl; return 0;}
                if((dane[2] == "") || ((dane[2] != "1") && (dane[2] != "2"))) {cout << "Bledna wartosc w 3 kolumnie wiersza " << numer_wiersza << endl; return 0;}
                
                if(stoi(dane[1]) == 1)                              
                {
                    Przedmioty_Wykl[przedmioty].push_back({dane[0],stoi(dane[1]),stoi(dane[2]),numer_wyk});
                    numer_wyk++;
                }
                else if(stoi(dane[1]) == 2)                         
                {
                    Przedmioty_Cw[przedmioty].push_back({dane[0],stoi(dane[1]),stoi(dane[2]),numer_cw});
                    numer_cw++;
                }
                else if(stoi(dane[1]) == 3)                         
                {
                    Przedmioty_Lab[przedmioty].push_back({dane[0],stoi(dane[1]),stoi(dane[2]),numer_lab});
                    numer_lab++;
                }
            }
            numer_wiersza++;                                        
            dane.erase(dane.begin(), dane.end());
        }
        plik.close();
    }
    else
        cout<<"Nie udało się otworzyć pliku z przedmiotami";
        
    return 1;
}
int Czy_istnieje_plik(const char* nazwa_pliku)                  
{
    struct stat bufor;
    if (stat(nazwa_pliku,&bufor) == 0)                          
        return 1;
    else
        return 0;
}
void Wczytanie_Grup(vector<vector<Nad_grupa>>&Grupy_Wyk, vector<vector<Nad_grupa>>&Grupy_Cw, vector<vector<Grupa>>&Grupy_Lab)
{
    string linia;                                           
    string czesc;
    vector <string> dane;
        
    int zbior_grup = 0;       
    int j = 0;
    
    fstream plik;
    plik.open("grupy.csv", ios::in | ios::out);
    if(plik.is_open())
	{
        while(!plik.eof())                                          
        {
            plik >> linia;                                          
                
            stringstream strumien(linia);
            while(getline(strumien,czesc,','))
            {
                dane.push_back(czesc);
            }
            if(dane[0] != "" && dane[0] != ";")                         
            {
                Grupy_Wyk.push_back(vector<Nad_grupa>());               
                Grupy_Cw.push_back(vector<Nad_grupa>());                
                Grupy_Lab.push_back(vector<Grupa>());                   
                
                if(dane[1] == "" || dane[2] == "" || dane[3] == "" || dane[4] == "" || dane[5] == "")
                    cout << "Blad w wierszu " << j << endl;
                else
                {
                    for(int i = 0; i < stoi(dane[3]); i++)                  
                    {
                        Grupy_Wyk[zbior_grup].push_back({1,i+1});
                    }
                    for(int i = 0; i < stoi(dane[4]); i++)                                          
                    {
                        Grupy_Cw[zbior_grup].push_back({2,i+1});
                    }
                    for(int i = 0; i < stoi(dane[5]); i++)                                          
                    {
                        Grupy_Lab[zbior_grup].push_back({dane[0],stoi(dane[1]),stoi(dane[2]),i+1});
                    }
                    zbior_grup++;  
                } 
            }
            else if(dane[0] == ";")                                                             
            {
                break;
            }
            j++;
            dane.erase(dane.begin(), dane.end());
        }
        plik.close();
    }
    else
        cout<<"Nie udało się otworzyć pliku z przedmiotami";
}                
void Wczytanie_Sal(vector <Sala> &Sala_Wykl,vector <Sala> &Sala_Cw,vector <Sala> &Sala_Lab)
{
    fstream plik;
    plik.open("sale.csv", ios::in | ios::out);
    if(plik.is_open())
    {
        string linia;                                           
        string czesc;
        
        vector <string> dane;
        
        while(!plik.eof())                                      
        {
            plik >> linia;
                
            stringstream strumien(linia);
            while(getline(strumien,czesc,','))
            {
                dane.push_back(czesc);
            }
            if(dane[0] != "" && dane[0] != ";")                  
            {
                if(stoi(dane[0]) == 1)
                {
                    for(int i = 0; i < stoi(dane[1]); i++)      
                    {
                        if(dane[2+i] == "")
                        {
                            cout << "Brak numeru sali wykladowej" << endl;
                        }
                        else
                        {
                            Sala_Wykl.push_back({stoi(dane[2+i])}); 
                        }
                    }
                }
                else if(stoi(dane[0]) == 2)
                {
                    for(int i = 0; i < stoi(dane[1]); i++)      
                    {
                        if(dane[2+i] == "")
                        {
                            cout << "Brak numeru sali cwiczeniowej" << endl;
                        }
                        else
                        {
                            Sala_Cw.push_back({stoi(dane[2+i])}); 
                        }
                    }
                }
                else if(stoi(dane[0]) == 3)
                {
                    for(int i = 0; i < stoi(dane[1]); i++)      
                    {
                        if(dane[2+i] == "")
                        {
                            cout << "Brak numeru sali laboratoryjnej" << endl;
                        }
                        else
                        {
                            Sala_Lab.push_back({stoi(dane[2+i])}); 
                        }
                    }
                }
            }
            else if(dane[0] == ";")                             
            {
                break;
            }
            dane.erase(dane.begin(), dane.end());
        }
        plik.close();
    }
    else
        cout<<"Nie udało się otworzyć pliku z salami";
}
void Grup_Wyk_Podz(vector<vector<Nad_grupa>> &Grupy_Wyk,vector<vector<Grupa>> &Grupy_Lab,vector <vector<Nad_grupa>> &Grupy_Cw)
{
    int ilosc_rocznikow = Grupy_Wyk.size();                                          
    
    for(int k = 0; k < ilosc_rocznikow; k++)
    {
        int Wszystkie_gr_lab = Grupy_Lab[k].size();               
        int nie_przydzielone_gr_lab = Grupy_Lab[k].size();
     
        int Wszystkie_gr_cw = Grupy_Cw[k].size();               
        int nie_przydzielone_gr_cw = Grupy_Cw[k].size(); 
 
        int ilosc_gr_do_stworzenia = Grupy_Wyk[k].size();         
        int wielkosc_nowa_gr_wykladowa = 0;  
        
        for (int i = ilosc_gr_do_stworzenia; i > 0; i--)
        {
            wielkosc_nowa_gr_wykladowa = round(nie_przydzielone_gr_cw / i);

            for(int j = 0; j < wielkosc_nowa_gr_wykladowa; j++)
            {
                Grupy_Wyk[k][ilosc_gr_do_stworzenia - i].grupa_cw()->push_back(&Grupy_Cw[k][j + Wszystkie_gr_cw - nie_przydzielone_gr_cw]);
            }
            nie_przydzielone_gr_cw -= wielkosc_nowa_gr_wykladowa;
        } 

        for (int i = ilosc_gr_do_stworzenia; i > 0; i--)
        {
            wielkosc_nowa_gr_wykladowa = round(nie_przydzielone_gr_lab / i);

            for(int j = 0; j < wielkosc_nowa_gr_wykladowa; j++)
            {
                Grupy_Wyk[k][ilosc_gr_do_stworzenia - i].grupa_lab()->push_back(&Grupy_Lab[k][j + Wszystkie_gr_lab - nie_przydzielone_gr_lab]);
            }
            
            nie_przydzielone_gr_lab -= wielkosc_nowa_gr_wykladowa;
        }
    }
}
void Grup_Cw_Podz(vector<vector<Nad_grupa>> &Grupy_Cw, vector <vector<Grupa>> &Grupy_Lab)
{
    int ilosc_rocznikow = Grupy_Cw.size();
    
    for(int k = 0; k < ilosc_rocznikow; k++)
    {
        int Wszystkie_gr_lab = Grupy_Lab[k].size();               
        float nie_przydzielone_gr_lab = Grupy_Lab[k].size();       
        int ilosc_gr_do_stworzenia = Grupy_Cw[k].size();         
        float wielkosc_nowa_gr_cwiczeniowa = 0;   
    
        for (int i = ilosc_gr_do_stworzenia; i > 0; i--)               
        {
            wielkosc_nowa_gr_cwiczeniowa = round(nie_przydzielone_gr_lab / i);

            for(int j = 0; j < wielkosc_nowa_gr_cwiczeniowa; j++)
            {
                Grupy_Cw[k][ilosc_gr_do_stworzenia - i].grupa_lab()->push_back(&Grupy_Lab[k][j + Wszystkie_gr_lab - nie_przydzielone_gr_lab]);
            }
        
            nie_przydzielone_gr_lab -= wielkosc_nowa_gr_cwiczeniowa;
        }
    }
}
void Wczytanie_nauczycieli_wykladow(vector <vector<Przedmiot>> &Przedmioty_Wykl,vector <Nauczyciel> &Nauczyciele)
{
    fstream plik;
    plik.open("wyklady_nauczyciele.csv", ios::in | ios::out);
    
    if(plik.is_open())
    {
        cout << "Plik z nauczycielami wykladow otwarty" << endl << endl;
        
        string linia;                                           
        string czesc;
        int numer_nauczyciela = 0;                               
        int numer_wykladu = 0;                                  
        int ile_wykladow = 0;                                   
        int ile_wykl_wcze = 0;                                  
        vector <string> dane;
        
        int il_zbiorow_wykladow = Przedmioty_Wykl.size();
        
        while(!plik.eof())                                      
        {
            plik >> linia;
        
            stringstream strumien(linia);
            while(getline(strumien,czesc,','))
            {
                dane.push_back(czesc);
            }
            
            if(dane[0] != "" && dane[0] != ";")                                         
            { 
                numer_wykladu = 0;
                
                ile_wykladow = Przedmioty_Wykl[0].size();                               
                ile_wykl_wcze = 0;                                                        
                
                for(int j = 0; j < il_zbiorow_wykladow;j++)                              
                {
                    for(int i = numer_wykladu; i < ile_wykladow; i++)
                    {
                        if(stoi(dane[i]) != 0)
                        {
                            Nauczyciele[numer_nauczyciela].Godziny_wykl(i,stoi(dane[i]));
                            Przedmioty_Wykl[j][i-ile_wykl_wcze].Dodaj_nauczyciela(numer_nauczyciela);
                        }
                        else if(stoi(dane[i]) == "")
                        {
                            cout << "Blad w pliku nauczyciele_wykladow wiersz " << numer_nauczyciela << endl;
                        }
                        numer_wykladu++;
                    }
                    ile_wykl_wcze = ile_wykladow;                                       
                    ile_wykladow += Przedmioty_Wykl[j+1].size();
                }
            }
            else if(dane[0] == ";")                                                     
            {
                break;
            }
            dane.erase(dane.begin(), dane.end());
            numer_nauczyciela++;                                                        
        }
        plik.close();
    }
    else
        cout<<"Nie udało się otworzyć pliku z nauczycielami wykladow przedmiotow";
}
void Wczytanie_nauczycieli_cwiczen(vector<vector<Przedmiot>> &Przedmioty_Cw,vector <Nauczyciel> &Nauczyciele)
{
    fstream plik;
    plik.open("cwiczenia_nauczyciele.csv", ios::in | ios::out);
    
    if(plik.is_open())
    {
        cout << "Plik z nauczycielami cwiczeniami otwarty" << endl << endl;
        
        string linia;                                           
        string czesc;
        int numer_nauczyciela = 0;                               
        int numer_cwiczenia = 0;                                
        int ile_cwiczen = 0;                                   
        int ile_cw_wcze = 0;                                    
        vector <string> dane;
        
        int il_zbiorow_cwiczen = Przedmioty_Cw.size();
        
        while(!plik.eof())                                      
        {
            plik >> linia;
        
            stringstream strumien(linia);
            while(getline(strumien,czesc,','))
            {
                dane.push_back(czesc);
            }
            
            if(dane[0] != "" && dane[0] != ";")                                         
            { 
                numer_cwiczenia = 0;
                
                ile_cwiczen = Przedmioty_Cw[0].size();                                  
                ile_cw_wcze = 0;                                                        
                
                for(int j = 0; j < il_zbiorow_cwiczen;j++)                              
                {
                    for(int i = numer_cwiczenia; i < ile_cwiczen; i++)
                    {
                        if(stoi(dane[i]) != 0)
                        {
                            Nauczyciele[numer_nauczyciela].Godziny_cw(i,stoi(dane[i]));
                            Przedmioty_Cw[j][i-ile_cw_wcze].Dodaj_nauczyciela(numer_nauczyciela);
                        }
                        else if(stoi(dane[i]) == "")
                        {
                            cout << "Blad w pliku nauczyciele_cwiczen wiersz:" << numer_nauczyciela << endl;
                        }
                        numer_cwiczenia++;
                    }
                    ile_cw_wcze = ile_cwiczen;                                          
                    ile_cwiczen += Przedmioty_Cw[j+1].size();
                }
            }
            else if(dane[0] == ";")                                                     
            {
                break;
            }
            dane.erase(dane.begin(), dane.end());
            numer_nauczyciela++;                                                        
        }
        plik.close();
    }
    else
        cout<<"Nie udało się otworzyć pliku z nauczycielami cwiczen przedmiotow";
}
void Wczytanie_nauczycieli_laborek(vector <vector<Przedmiot>> &Przedmioty_Lab,vector < Nauczyciel> &Nauczyciele)
{
    fstream plik;
    plik.open("laborki_nauczyciele.csv", ios::in | ios::out);
    
    if(plik.is_open())
    {
        cout << "Plik z nauczycielami laborek otwarty" << endl << endl;
        
        string linia;                                           
        string czesc;
        int numer_nauczyciela = 0;                               
        int numer_laborek = 0;                                  
        int ile_laborek = 0;                                   
        int ile_lab_wcze = 0;                                   
        vector <string> dane;
        
        int il_zbiorow_labek = Przedmioty_Lab.size();
        
        while(!plik.eof())                                      
        {
            plik >> linia;
        
            stringstream strumien(linia);
            while(getline(strumien,czesc,','))
            {
                dane.push_back(czesc);
            }
            
            if(dane[0] != "" && dane[0] != ";")                                         
            { 
                numer_laborek = 0;
                
                ile_laborek = Przedmioty_Lab[0].size();                                 
                ile_lab_wcze = 0;                                                        
                
                for(int j = 0; j < il_zbiorow_labek;j++)                                
                {
                    for(int i = numer_laborek; i < ile_laborek; i++)
                    {
                        if(stoi(dane[i]) != 0)
                        {
                            Nauczyciele[numer_nauczyciela].Godziny_labek(i,stoi(dane[i]));
                            Przedmioty_Lab[j][i-ile_lab_wcze].Dodaj_nauczyciela(numer_nauczyciela);
                        }
                        else if(stoi(dane[i]) == "")
                        {
                            cout << "Blad w pliku nauczyciele_laborek wiersz: " << numer_nauczyciela << endl;
                        }
                        numer_laborek++;
                    }
                    ile_lab_wcze = ile_laborek;                                         
                    ile_laborek += Przedmioty_Lab[j+1].size();
                }
            }
            else if(dane[0] == ";")                                                     
            {
                break;
            }
            dane.erase(dane.begin(), dane.end());
            numer_nauczyciela++;                                                        
        }
        plik.close();
    }
    else
        cout<<"Nie udało się otworzyć pliku z nauczycielami laborek przedmiotow";
}
void Zajecia_wykladowe(vector <Zajecia>&Zajecie,vector<vector<Przedmiot>>&Przedmioty_Wykl,vector<vector<Nad_grupa>>&Grupy_Wykl,vector<Sala>&Sala_Wykl,int &il_wykl)
{
   
    
    int ile_zbior_gr_wykl = Grupy_Wykl.size();                      
    int ile_zbior_wykl = Przedmioty_Wykl.size();                            
    
    int ilosc_wykladow = 0;                                         
    int ilosc_grup = 0;                                             
    
    int maks_ile_grup = 0;                                          
    int maks_ile_wykl = 0;                                           
    
    vector<vector<Przedmiot>>::iterator it1 = Przedmioty_Wykl.begin();
    vector<vector<Nad_grupa>>::iterator it2 = Grupy_Wykl.begin();
    
    for(;it1 != Przedmioty_Wykl.end() && it2 != Grupy_Wykl.end();it1++,it2++)   
    {
        ilosc_wykladow = it1->size();
        ilosc_grup = it2->size();
        
        if(maks_ile_wykl < ilosc_wykladow)
            maks_ile_wykl = ilosc_wykladow;                         
        if(maks_ile_grup < ilosc_grup)
            maks_ile_grup = ilosc_grup;                             
    }
    
    int numer_zajecia = 0;                                          
    
    if(ile_zbior_gr_wykl == ile_zbior_wykl)                         
    {                                                               
        for(int k = 0; k < maks_ile_wykl; k++)                                                      
        {
            for(int i = 0; i < maks_ile_grup; i++)                                                  
            {
                for(int j = 0; j < ile_zbior_wykl; j++)                                              
                {
                    ilosc_wykladow = Przedmioty_Wykl[j].size();     
                    ilosc_grup = Grupy_Wykl[j].size();                
   
                    if(k < ilosc_wykladow && i < ilosc_grup)                            
                    {
                        Zajecie.push_back({{&Przedmioty_Wykl[j][k]},{NULL},{&Grupy_Wykl[j][i]},(numer_zajecia+1)});
                        numer_zajecia++;
                    }
                }
            }
        }
        int sala_wykl = 0;
        int ilosc_sal = Sala_Wykl.size();                               
        int ilosc_zajec = Zajecie.size();                               
    
        for(int i = 0; i < ilosc_zajec; i++)
        {
            if(sala_wykl == ilosc_sal)
                sala_wykl = 0;
       
            Zajecie[i].dodaj_sale()->push_back({&Sala_Wykl[sala_wykl]});
            sala_wykl++;
        }
        
        il_wykl = Zajecie.size();                                       
    }
    else
    {
        cout << "Zbiory wykladow i grup wykladowych nie sa sobie rowne" << endl;
    }
}
void Zajecia_cwiczeniowe(vector <Zajecia> &Zajecie,vector<vector<Przedmiot>> &Przedmioty_Cw,vector <vector<Nad_grupa>> &Grupy_Cw,vector<Sala> &Sala_Cw,int &il_wykl_i_cw)
{
    int ile_zbior_gr_cw = Grupy_Cw.size();                              
    int ile_zbior_cw = Przedmioty_Cw.size();                                 
    
    int ilosc_cwiczen = 0;                                              
    int ilosc_grup = 0;                                                 
    
    int maks_ile_grup = 0;                                              
    int maks_ile_cw = 0;                                              
    
    vector<vector<Przedmiot>>::iterator it1 = Przedmioty_Cw.begin();
    vector<vector<Nad_grupa>>::iterator it2 = Grupy_Cw.begin();
    
    for(;it1 != Przedmioty_Cw.end() && it2 != Grupy_Cw.end();it1++,it2++)   
    {
        ilosc_cwiczen = it1->size();
        ilosc_grup = it2->size();
        
        if(maks_ile_cw < ilosc_cwiczen)
            maks_ile_cw = ilosc_cwiczen;                         
        if(maks_ile_grup < ilosc_grup)
            maks_ile_grup = ilosc_grup;                             
    }
    
    int numer_zajecia = Zajecie.size();                             
    int ilosc_wykladow = Zajecie.size();
 
    if(ile_zbior_gr_cw == ile_zbior_cw)                              
    {                                                               
        for(int k = 0; k < maks_ile_cw; k++)                        
        {
            for(int i = 0; i < maks_ile_grup; i++)                  
            {
                for(int j = 0; j < ile_zbior_cw; j++)                                              
                {
                    ilosc_cwiczen = Przedmioty_Cw[j].size();        
                    ilosc_grup = Grupy_Cw[j].size();                  
   
                    if(k < ilosc_cwiczen && i < ilosc_grup)                             
                    {
                        Zajecie.push_back({{&Przedmioty_Cw[j][k]},{NULL},{&Grupy_Cw[j][i]},(numer_zajecia+1)});
                        numer_zajecia++;
                    }
                }
            }
        }
        int sala_cw = 0;
        int ilosc_sal = Sala_Cw.size();                                     
        int ilosc_zajec = Zajecie.size();                                   
    
        for(int i = ilosc_wykladow; i < ilosc_zajec; i++)
        {
            if(sala_cw == ilosc_sal)
                sala_cw = 0;
       
            Zajecie[i].dodaj_sale()->push_back({&Sala_Cw[sala_cw]});
            sala_cw++;
        }
        
        il_wykl_i_cw = Zajecie.size();                                      
    }
    else
    {
        cout << "Zbiory cwiczen i grup cwiczeniowych nie sa sobie rowne" << endl;
    }
}
void Zajecia_laborki(vector <Zajecia> &Zajecie,vector <vector<Przedmiot>> &Przedmioty_Lab,vector<vector<Grupa>> &Grupy_Lab,vector<Sala> &Sala_Lab)
{
    
    int ile_zbior_gr_lab = Grupy_Lab.size();                              
    int ile_zbior_lab = Przedmioty_Lab.size();                                 
    
    int ilosc_laborek = 0;                                              
    int ilosc_grup = 0;                                                 
    
    int maks_ile_grup = 0;                                              
    int maks_ile_lab = 0;                                              
    
    vector<vector<Przedmiot>>::iterator it1 = Przedmioty_Lab.begin();
    vector<vector<Grupa>>::iterator it2 = Grupy_Lab.begin();
    
    for(;it1 != Przedmioty_Lab.end() && it2 != Grupy_Lab.end();it1++,it2++)   
    {
        ilosc_laborek = it1->size();
        ilosc_grup = it2->size();
        
        if(maks_ile_lab < ilosc_laborek)
            maks_ile_lab = ilosc_laborek;                         
        if(maks_ile_grup < ilosc_grup)
            maks_ile_grup = ilosc_grup;                             
    }
    
    int numer_zajecia = Zajecie.size();                             
    int ilosc_wykl_i_cw = Zajecie.size();
 
    if(ile_zbior_gr_lab == ile_zbior_lab)                           
    {                                                               
        for(int k = 0; k < maks_ile_lab; k++)                       
        {
            for(int i = 0; i < maks_ile_grup; i++)                   
            {
                for(int j = 0; j < ile_zbior_lab; j++)                                              
                {
                    ilosc_laborek = Przedmioty_Lab[j].size();        
                    ilosc_grup = Grupy_Lab[j].size();                  
   
                    if(k < ilosc_laborek && i < ilosc_grup)                                  
                    {
                        Zajecie.push_back({{&Przedmioty_Lab[j][k]},{&Grupy_Lab[j][i]},{NULL},numer_zajecia+1});
                        numer_zajecia++;
                    }
                }
            }
        }
        int sala_lab = 0;
        int ilosc_sal = Sala_Lab.size();                                     
        int ilosc_zajec = Zajecie.size();                                    
    
        for(int i = ilosc_wykl_i_cw; i < ilosc_zajec; i++)                   
        {
            if(sala_lab == ilosc_sal)
                sala_lab = 0;
       
            Zajecie[i].dodaj_sale()->push_back({&Sala_Lab[sala_lab]});
            sala_lab++;
        }
    }
    else
    {
        cout << "Zbiory laborek i grup laboratoryjnych nie sa sobie rowne" << endl;
    }
}
void Zajecia_nauczyciele(vector<Zajecia> &Zajecie,vector<Nauczyciel> &Nauczyciele,int il_wykl,int il_wykl_i_cw)
{
    int ilosc_zajec = Zajecie.size();
    
    for(int i = 0; i < il_wykl; i++)                                                  
    {
        if(Nauczyciele[Zajecie[i].przedmiot()->Zwroc_nauczyciela()].Dostepny_wykl(Zajecie[i].przedmiot()->Zwroc_numer()))
        {
            Zajecie[i].nauczyciel()->push_back(&Nauczyciele[Zajecie[i].przedmiot()->Zwroc_nauczyciela()]);
        }
        else 
        {
            Zajecie[i].przedmiot()->Nastepny_nauczyciel();
            Nauczyciele[Zajecie[i].przedmiot()->Zwroc_nauczyciela()].Dostepny_wykl(Zajecie[i].przedmiot()->Zwroc_numer());
            Zajecie[i].nauczyciel()->push_back(&Nauczyciele[Zajecie[i].przedmiot()->Zwroc_nauczyciela()]);
        }
    }
    for(int i = il_wykl; i < il_wykl_i_cw; i++)                                                  
    {
        if(Nauczyciele[Zajecie[i].przedmiot()->Zwroc_nauczyciela()].Dostepny_cw(Zajecie[i].przedmiot()->Zwroc_numer()))
        {
            Zajecie[i].nauczyciel()->push_back(&Nauczyciele[Zajecie[i].przedmiot()->Zwroc_nauczyciela()]);
        }
        else 
        {
            Zajecie[i].przedmiot()->Nastepny_nauczyciel();
            Nauczyciele[Zajecie[i].przedmiot()->Zwroc_nauczyciela()].Dostepny_cw(Zajecie[i].przedmiot()->Zwroc_numer());
            Zajecie[i].nauczyciel()->push_back(&Nauczyciele[Zajecie[i].przedmiot()->Zwroc_nauczyciela()]);
        }
    }
    for(int i = il_wykl_i_cw; i < ilosc_zajec; i++)                                                  
    {
        if(Nauczyciele[Zajecie[i].przedmiot()->Zwroc_nauczyciela()].Dostepny_lab(Zajecie[i].przedmiot()->Zwroc_numer()))
        {
            Zajecie[i].nauczyciel()->push_back(&Nauczyciele[Zajecie[i].przedmiot()->Zwroc_nauczyciela()]);
        }
        else 
        {
            Zajecie[i].przedmiot()->Nastepny_nauczyciel();
            Nauczyciele[Zajecie[i].przedmiot()->Zwroc_nauczyciela()].Dostepny_lab(Zajecie[i].przedmiot()->Zwroc_numer());
            Zajecie[i].nauczyciel()->push_back(&Nauczyciele[Zajecie[i].przedmiot()->Zwroc_nauczyciela()]);
        }
    }
}
void Tworzenie_harmonogramu(vector <Zajecia> &Zajecie)
{
    int ilosc_zajec = Zajecie.size();
    
    for(int i = 0; i < ilosc_zajec; i++)
    {
        int losowa = rand() % 2;
        
        Zajecie[i].Termin_zajec(losowa);
    }
}
void Wypisanie_danych_harmonogramu(vector <Zajecia> &Zajecie,vector <vector<Grupa>> &Grupy_Lab, vector <Nauczyciel> &Nauczyciele)
{
    int ilosc_nauczycieli = Nauczyciele.size();
    int ilosc_zajec = 0;
    set <int>::iterator it;
    
    for(int i = 0; i < ilosc_nauczycieli; i++)
    {
        cout << "Plan nauczyciela " << i+1 << endl;
        for(int j = 0; j < 20; j++)
        {
            Nauczyciele[i].Wypisz_poz_w_plan(j);
        }
        cout << endl;
        
        ilosc_zajec = Nauczyciele[i].Ile_zajec();
        
        cout << "Ilosc zajec nauczyciela: " << ilosc_zajec << endl;
        it = Nauczyciele[i].Pierwszy_zaj_termin();
        cout << "Zajecie pierwsze: " << *it << endl;
        it = --Nauczyciele[i].Ostatni_zaj_termin();
        cout << "Zajecie ostatnie: " << *it << endl;
        cout << "Kara: " << Nauczyciele[i].Oblicz_kare() << endl;
        
        cout << "Godziny dopuszczalne: ";
        for(it = Nauczyciele[i].Pierwszy_dop_termin(); it != Nauczyciele[i].Ostatni_dop_termin(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
        
        cout << "Terminy wykluczone: ";
        for(it = Nauczyciele[i].Pierwszy_niedop_termin(); it != Nauczyciele[i].Ostatni_niedop_termin(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
        
        cout << "Zajete terminy: ";
        for(it = Nauczyciele[i].Pierwszy_zaj_termin(); it != Nauczyciele[i].Ostatni_zaj_termin(); it++)
        {
            cout << *it << " ";
        }
        cout << endl << endl;
    }
    
    cout << "Suma kar dla nauczycieli: " << Kara_laczna_nauczycieli(Nauczyciele) << endl << endl;
    
    int ile_zbior_grup = Grupy_Lab.size();
    int ilosc_grup = 0;
    
    for(int k = 0; k < ile_zbior_grup; k++)
    {
        ilosc_grup = Grupy_Lab[k].size();
        
        for(int i = 0; i < ilosc_grup; i++)
        {
            cout << "Plan Grupy " << i+1 << endl;
            for(int j = 0; j < 20; j++)
            {
                cout << Grupy_Lab[k][i].Zwroc_numer_zaj(j) << " ";
            }
            cout << endl;
            
            ilosc_zajec = Grupy_Lab[k][i].Ile_zajec();
            
            cout << "Ilosc zajec grup: " << ilosc_zajec << endl;
            it = Grupy_Lab[k][i].Pierwszy_zaj_termin();
            cout << "Zajecie pierwsze: " << *it << endl;
            it = --Grupy_Lab[k][i].Ostatni_zaj_termin();
            cout << "Zajecie ostatnie: " << *it << endl;
            cout << "Kara planu: " << Grupy_Lab[k][i].Oblicz_kare() << endl;
            
            cout << "Zajete terminy: ";
            for(it = Grupy_Lab[k][i].Pierwszy_zaj_termin(); it != Grupy_Lab[k][i].Ostatni_zaj_termin(); it++)
            {
                cout << *it << " ";
            }
            cout << endl << endl;
        }
    }
    
    cout << "Suma kar dla grup: " << Kara_laczna_grup(Grupy_Lab) << endl << endl;
    
    cout << "Kara laczna dla grup i nauczycieli: " << Kara_laczna_nauczycieli(Nauczyciele) + Kara_laczna_grup(Grupy_Lab) << endl << endl;
}
void Poprawianie_harmonogramu(vector <Zajecia> &Zajecie,vector <vector<Grupa>> &Grupy_Lab,vector <Nauczyciel> &Nauczyciele, vector <Sala> Sala_Lab, int ile_popraw)
{
    vector <Sala> Sala_Lab_Naj = Sala_Lab;                                       
    vector <vector<Grupa>> Grupy_Lab_Naj = Grupy_Lab;                           
    vector <Nauczyciel> Nauczyciele_Naj = Nauczyciele;                          
    vector <Zajecia> Zajecie_Naj = Zajecie;                                     
    
    vector <float> kara_grupy;                                                  
    vector <float> kara_nauczyciel;                                             
    vector <float>::iterator it;                                                
    
    vector <Nauczyciel*> nauczyciele_labek;                                       
    vector <Grupa*> grupy;                                                      
    
    int ilosc_zbiorow_grup = Grupy_Lab.size();                                 
    int ilosc_grup = 0;                                                         
    int ilosc_nauczy = Nauczyciele.size();                                      
    int il_nauczy_lab = 0;                      
                                                
    int najg_nauczy = 0;                                                        
    int najg_grupa = 0;                                                         
       
    int ile_zmian = 0;                                                          
    
    for(int i = 0; i < ilosc_zbiorow_grup; i++)                                 
    {                                                                           
        ilosc_grup = Grupy_Lab[i].size();
                                                                        
        for(int j = 0; j < ilosc_grup; j++)
        {
            grupy.push_back({&Grupy_Lab[i][j]});                                
        }
    }
    
    ilosc_grup = grupy.size();                                                  
    for(int i = 0; i < ilosc_grup; i++)                                                              
    {                                                                                           
        kara_grupy.push_back({grupy[i]->Oblicz_kare()});                                        
    }                                                                                           
    cout << endl;
    
    it = max_element(kara_grupy.begin(),kara_grupy.end());                                      
    najg_grupa = distance(kara_grupy.begin(), it);                                              
    
    for(int i = 0; i < ilosc_nauczy; i++)                                                       
    {
        if(Nauczyciele[i].Ile_lab_w_planie() != 0)                                          
            nauczyciele_labek.push_back({&Nauczyciele[i]});                                 
    }
    
    il_nauczy_lab = nauczyciele_labek.size();                                               
    
    for(int i = 0; i < il_nauczy_lab; i++)
    {
        kara_nauczyciel.push_back(nauczyciele_labek[i]->Oblicz_kare());                     
    }
    
    it = max_element(kara_nauczyciel.begin(),kara_nauczyciel.end());                            
    najg_nauczy = distance(kara_nauczyciel.begin(), it);                                        
    
    cout << "Ogolna wartosc kary planu: " << Ogolna_kara_planu(Grupy_Lab,Nauczyciele) << endl;
    
    for(int i = 0; i < ile_popraw; i++)
    {
        Poprawianie_grupy(Zajecie,it,kara_grupy,grupy,najg_grupa);
        Poprawianie_nauczycieli(Zajecie,it,kara_nauczyciel,Nauczyciele,najg_nauczy);
        
        if(Ogolna_kara_planu(Grupy_Lab,Nauczyciele) < Ogolna_kara_planu(Grupy_Lab_Naj,Nauczyciele_Naj))   
        {                                                                  
            Sala_Lab_Naj = Sala_Lab;                                               
            Grupy_Lab_Naj = Grupy_Lab;                                               
            Nauczyciele_Naj = Nauczyciele;                                      
            Zajecie_Naj = Zajecie;      
            ile_zmian = 0;                                                  
        }
        else if(ile_zmian == 2)                                             
        {                                                                   
            Sala_Lab = Sala_Lab_Naj;                                        
            Grupy_Lab = Grupy_Lab_Naj;                                               
            Nauczyciele = Nauczyciele_Naj;                                      
            Zajecie = Zajecie_Naj;     
            
            for(int i = 0; i < ilosc_grup; i++)                              
            {                                                               
                kara_grupy[i] = grupy[i]->Zwroc_kare();           
            } 
            for(int i = 0; i < il_nauczy_lab; i++)                           
            {                                                               
                kara_nauczyciel[i] = Nauczyciele[i].Zwroc_kare();           
            } 
            
            ile_zmian = 0;                                                  
        }
        cout << "Ogolna wartosc kary planu: " << Ogolna_kara_planu(Grupy_Lab,Nauczyciele) << endl;
    }
    Sala_Lab = Sala_Lab_Naj;                                                
    Grupy_Lab = Grupy_Lab_Naj;                                               
    Nauczyciele = Nauczyciele_Naj;                                      
    Zajecie = Zajecie_Naj;     
}
