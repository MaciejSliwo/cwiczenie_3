#ifndef SYGNAL_HPP
#define SYGNAL_HPP
#include <vector>
#include "Probka.hpp"
#include <string>


class Sygnal{
public:
void odczyt();
void zapisz (std::vector <Probka> probkix);
double mini (std::vector <Probka> probkix);
double maxi (std::vector <Probka> probkix);
double srednia (std::vector <Probka> probkix);
double calkowanie (std::vector<Probka> probkix);
double dlugosc_vectora(std::vector <Probka> probkiy);
void wczytaj (std::string nazwa);

private:
std::vector <Probka> _wektor;

};

#endif
