#include "Zajecia.h"

Zajecia::Zajecia(vector <Przedmiot*> przedmiot,vector <Grupa*> grupa,vector <Nad_grupa*> nad_grupa,int numer)
{
    PRzedmiot = przedmiot;
    GRupa = grupa;
    NAD_grupa = nad_grupa;
    Numer = numer;
}

int Zajecia::Mozliwosc_zmiany()
{
    set <int> Zajete_godziny;                                                                           
    int dodanie_dop = -1;
    
    do
    {
        Zajete_godziny.clear();     
        dodanie_dop++;              
        
        if(dodanie_dop == 0)        
        {                                                                                                
            Zajete_godziny.insert(NAuczyciel[0]->Pierwszy_zaj_termin(),NAuczyciel[0]->Ostatni_zaj_termin());
            Zajete_godziny.insert(NAuczyciel[0]->Pierwszy_dop_termin(),NAuczyciel[0]->Ostatni_dop_termin());
            Zajete_godziny.insert(SAla[0]->Pierwszy_zaj_termin(),SAla[0]->Ostatni_zaj_termin());               
            Zajete_godziny.insert(GRupa[0]->Pierwszy_zaj_termin(),GRupa[0]->Ostatni_zaj_termin());
        }
        else if(dodanie_dop == 1)   
        {
            Zajete_godziny.insert(NAuczyciel[0]->Pierwszy_zaj_termin(),NAuczyciel[0]->Ostatni_zaj_termin());
            Zajete_godziny.insert(SAla[0]->Pierwszy_zaj_termin(),SAla[0]->Ostatni_zaj_termin());               
            Zajete_godziny.insert(GRupa[0]->Pierwszy_zaj_termin(),GRupa[0]->Ostatni_zaj_termin());
        }
        
    }while(Zajete_godziny.size() == 20 && dodanie_dop == 0);
    
    Wolne_terminy.clear();                                                                              
    
    for(int i = 0; i < 20; i++)                                                                         
    {
        Wolne_terminy.push_back(i);
    }
    
    if(Zajete_godziny.size() == 20 && dodanie_dop == 1)         
    {
        cout << "Brak mozliwosci na przestawienie zajecia " << Numer << endl;
        return 0;
    }
    else if(Zajete_godziny.size() < 20 && dodanie_dop == 1)     
    {
        cout << "Przestawienie zajecia w miejsce niekorzystne dla nauczyciela " << endl;
        NAuczyciel[0]->Zwieksz_kare_dop();                      
    }
    
    if(Zajete_godziny.size() != 0)                                                                         
    {
        for(auto i = Zajete_godziny.rbegin(); i != Zajete_godziny.rend(); i++)                              
        {                                                                                                   
            Wolne_terminy.erase(Wolne_terminy.begin()+*i);                                                                                                        
        }
    }
    
    return 1;
}

void Zajecia::Termin_zajec(int losowa)
{
    for(int i = 0; i < 20; i++)                 
    {
        Wolne_terminy.push_back(i);         
    }
    
    int dodanie_dop = -1;                       
    int ile_woln_ter = 0;                       
    
    set <int> Zajete_godziny;                              
    
    do
    {
        Zajete_godziny.clear();                 
        dodanie_dop++;
        
        if(dodanie_dop == 0)                     
        {
            Zajete_godziny.insert(NAuczyciel[0]->Pierwszy_zaj_termin(),NAuczyciel[0]->Ostatni_zaj_termin());                
            Zajete_godziny.insert(NAuczyciel[0]->Pierwszy_dop_termin(),NAuczyciel[0]->Ostatni_dop_termin());                
            Zajete_godziny.insert(SAla[0]->Pierwszy_zaj_termin(),SAla[0]->Ostatni_zaj_termin());                            
        }
        else if(dodanie_dop == 1)               
        {
            Zajete_godziny.insert(NAuczyciel[0]->Pierwszy_zaj_termin(),NAuczyciel[0]->Ostatni_zaj_termin());    
            Zajete_godziny.insert(SAla[0]->Pierwszy_zaj_termin(),SAla[0]->Ostatni_zaj_termin());                
        }
        
        if(GRupa[0] == NULL)                    
        {  
            Zajete_godziny.insert(NAD_grupa[0]->Pierwszy_zaj_termin(),NAD_grupa[0]->Ostatni_zaj_termin());    
        }                                                                                                       
        else if(GRupa[0] != NULL)                                                                                       
        {
            Zajete_godziny.insert(GRupa[0]->Pierwszy_zaj_termin(),GRupa[0]->Ostatni_zaj_termin());             
        }                                      
        
    }while(Zajete_godziny.size() == 20 && dodanie_dop == 0);    
                                                                  

    if(Zajete_godziny.size() == 20 && dodanie_dop == 1)         
    {
        cout << "Brak terminow na przydzielenie zajecia !!!" << Numer << endl;
    }
    else if(Zajete_godziny.size() < 20 && dodanie_dop == 1)     
    {
        NAuczyciel[0]->Zwieksz_kare_dop();                      
    }
    
    if(Zajete_godziny.size() != 0)                                                                         
    {
        for(auto i = Zajete_godziny.rbegin(); i != Zajete_godziny.rend(); i++)                               
        {                                                                                                   
            Wolne_terminy.erase(Wolne_terminy.begin()+*i);                                                                                                        
        }
    }

    if(Wolne_terminy.size() > 0)                                                            
    {
        int wartosc = Numer + losowa;
        
        if(wartosc % 2 == 0)                                                                
        {
            ile_woln_ter = 0;
        }
        else if(wartosc % 2 == 1)                                                           
        {
            ile_woln_ter = Wolne_terminy.size()/8;
        }
    
        Termin = Wolne_terminy[ile_woln_ter];
        
        NAuczyciel[0]->Dodanie_do_planu(Numer,Wolne_terminy[ile_woln_ter]);                     
        NAuczyciel[0]->Dodanie_zaj_terminu(Wolne_terminy[ile_woln_ter]);                        
        
        SAla[0]->Dodanie_do_planu(Numer,Wolne_terminy[ile_woln_ter]);                           
        SAla[0]->Dodanie_zaj_terminu(Wolne_terminy[ile_woln_ter]);                              
        
        if(GRupa[0] == NULL)                                                                                        
        {
            if(NAD_grupa[0]->grupa_cw(0) == NULL)                                                                   
            {
                int ilosc_laborek = NAD_grupa[0]->grupa_lab()->size();
                for(int i = 0; i < ilosc_laborek; i++)
                {
                    NAD_grupa[0]->grupa_lab(i)->Dodanie_do_planu(Wolne_terminy[ile_woln_ter],Numer);
                    NAD_grupa[0]->grupa_lab(i)->Dodanie_zaj_terminu(Wolne_terminy[ile_woln_ter]);
                }
                NAD_grupa[0]->Dodanie_zaj_terminu(Wolne_terminy[ile_woln_ter]);                                     
            }
            else if(NAD_grupa[0]->grupa_cw(0) != NULL)                                                              
            {
                int ilosc_cwiczen = NAD_grupa[0]->grupa_cw()->size();
                
                NAD_grupa[0]->Dodanie_zaj_terminu(Wolne_terminy[ile_woln_ter]);                                                                    
                
                for(int i = 0; i < ilosc_cwiczen; i++)                                                              
                {                                                                                                   
                    NAD_grupa[0]->grupa_cw(i)->Dodanie_zaj_terminu(Wolne_terminy[ile_woln_ter]);                    
                }
                
                int ilosc_laborek = NAD_grupa[0]->grupa_lab()->size();
            
                for(int i = 0; i < ilosc_laborek; i++)                                                              
                {                                                                                                   
                    NAD_grupa[0]->grupa_lab(i)->Dodanie_do_planu(Wolne_terminy[ile_woln_ter],Numer);                
                    NAD_grupa[0]->grupa_lab(i)->Dodanie_zaj_terminu(Wolne_terminy[ile_woln_ter]);                   
                }
            }
        }
        else if(GRupa[0] != NULL)
        {
            GRupa[0]->Dodanie_do_planu(Wolne_terminy[ile_woln_ter],Numer);                                 
            GRupa[0]->Dodanie_zaj_terminu(Wolne_terminy[ile_woln_ter]);                                    
            NAuczyciel[0]->Dodanie_do_lab(Wolne_terminy[ile_woln_ter]);                                    
            GRupa[0]->Dodanie_do_lab(Wolne_terminy[ile_woln_ter]);                                         
        }                                                                  
    }
}

void Zajecia::Zmiana_terminu()
{
    int wolne_terminy = Wolne_terminy.size();
    int termin = rand() % wolne_terminy;                                                    
    
    set <int>::iterator it;
    
    GRupa[0]->Usuniecie_zaj_terminu(Termin);                                                
    NAuczyciel[0]->Usuniecie_zaj_terminu(Termin);                                           
    SAla[0]->Usuniecie_zaj_terminu(Termin);                                                 
    
    if(NAuczyciel[0]->Szukaj_dop_terminu(Termin))                                           
        NAuczyciel[0]->Zmniejsz_kare_dop();                                                 
    
    GRupa[0]->Usuniecie_lab(Termin);                                                        
    NAuczyciel[0]->Usuniecie_lab(Termin);
    
    GRupa[0]->Dodanie_do_planu(Termin,0);                                                   
    NAuczyciel[0]->Dodanie_do_planu(0,Termin);
    SAla[0]->Dodanie_do_planu(0,Termin);
    
    Termin = Wolne_terminy[termin];                                                         
    
    GRupa[0]->Dodanie_do_planu(Termin,Numer);                                               
    NAuczyciel[0]->Dodanie_do_planu(Numer,Termin);                                                                                             
    SAla[0]->Dodanie_do_planu(Numer,Termin);
    
    GRupa[0]->Dodanie_zaj_terminu(Termin);                                                  
    NAuczyciel[0]->Dodanie_zaj_terminu(Termin);                                             
    SAla[0]->Dodanie_zaj_terminu(Termin);
    
    GRupa[0]->Dodanie_do_lab(Termin);                                                       
    NAuczyciel[0]->Dodanie_do_lab(Termin);                                                  
    
    GRupa[0]->Oblicz_kare();                                                                
    NAuczyciel[0]->Oblicz_kare();                                                           
}
string Zajecia::Zwroc_imie_i_nazwisko_nauczyciela()
{
    return NAuczyciel[0]->Zwroc_imie_i_nazwisko();
}
vector <Nauczyciel*> *Zajecia::nauczyciel()
{
    return &NAuczyciel;
}
Przedmiot *Zajecia::przedmiot()
{
    return PRzedmiot[0];
}
Sala *Zajecia::sala()
{
    return SAla[0];
}
vector <Sala*> *Zajecia::dodaj_sale()
{
    return &SAla;
}
Grupa *Zajecia::grupa()
{
    return GRupa[0];
}
Nad_grupa *Zajecia::nad_grupa()
{
    return NAD_grupa[0];
}

Zajecia::~Zajecia()
{
    
    
}

