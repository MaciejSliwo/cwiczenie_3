#include "Sygnal.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

void Sygnal::wczytaj (string nazwa)
    {
     ifstream plik(nazwa);

     string linia;
     while(getline(plik,linia))
     {

        stringstream ss(linia);
         double _t, _x;
         ss >> _t;
         ss.ignore();
         ss >> _x;

         //cout<< _t;
         //cout<< _x;

        _wektor.push_back (Probka(_t,_x)) ;
     }
     plik.close();

    }

void Sygnal::odczyt()
{
    for (int i =0; i < _wektor.size(); i++)
    {
    cout<<_wektor[i].t<<" ";
    cout<<_wektor[i].x<<endl;
    }
}

void Sygnal::zapisz (vector <Probka> _wektor) //string nazwa)
{
    ofstream plik("out.csv");  //ofstream plik(nazwa)
    //plik << "Maciej Sliwonik";
    for (int i = 0; i <= _wektor.size(); i++)
    {
    plik << _wektor[i].t << ", " << _wektor[i].x << endl;
    }
plik.close();
}

    double Sygnal::mini (vector <Probka> _wektor)
    {

    double minimum = 10000.0;

    //numeric_limits<double>::max();
    for (int i = 0; i < _wektor.size(); i++)
        {
     if (_wektor[i].x < minimum)
     {
     minimum = _wektor[i].x;
     }
}
 return minimum;

}

    double Sygnal::maxi (vector <Probka> _wektor)
    {

    double maximum = -10000.0;

    //numeric_limits<double>::max();
    for (int i = 0; i < _wektor.size(); i++)
        {
     if (_wektor[i].x > maximum)
     {
     maximum = _wektor[i].x;
     }
}
 return maximum;
}

double Sygnal::srednia (vector <Probka> _wektor)
{
     double m = 0.0;
     for (int i = 0; i < _wektor.size(); i++)
        {
     m = m + _wektor[i].x;
     }
     if (_wektor.size() > 0)
        {
     m = m / _wektor.size();

}
return m;
}

double Sygnal::calkowanie (vector<Probka> _wektor)
{
    double dt1, dpole1, calka;
    for (int i = 0; i <= (_wektor.size()) -1; i++)
    {
     dt1 = _wektor[i + 1].t - _wektor[i].t;
     dpole1 = (_wektor[i].x + _wektor[i + 1].x) * dt1 / 2;
    calka = calka + dpole1;
    }
   return calka;
}

double Sygnal::dlugosc_vectora(vector <Probka> probkiy)
{
    double probki_dtp = probkiy[0].t;

    double probki_dt = probkiy[probkiy.size()-1].t;
    double roznica = probki_dt - probki_dtp;

    return roznica;
}
