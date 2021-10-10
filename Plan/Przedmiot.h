#ifndef PRZEDMIOT_H
#define PRZEDMIOT_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Przedmiot
{
private:
    string Nazwa;                                                       
    int Numer;                                                          
    int Czestosc;                                                       
    int Rodzaj;                                                         
    vector <int> Nauczyciele;                                           
    
public:
    
    Przedmiot(std::string nazwa,int rodzaj,int czestosc, int numer);
    ~Przedmiot();
    
    string Zwroc_nazwe();
    int Zwroc_numer();
    int Zwroc_nauczyciela();
    int Ile_nauczycieli();
    void Nastepny_nauczyciel();
    void Dodaj_nauczyciela(int numer_nauczyciela);
    void Wypisz_nauczycieli();
    
};

#endif // PRZEDMIOT_H
