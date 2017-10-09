#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;

struct Probka
{
double t;
double x;

};

    vector <Probka> wczytaj (string nazwa)
    {
     vector <Probka> tab;
     ifstream plik(nazwa);

     string linia;
     while(getline(plik,linia))
     {
        Probka p1;
        stringstream ss(linia);
         double x1, x2;
         ss >> x1;
         ss.ignore();
         ss >> x2;

         p1.t = x1;
         p1.x = x2;

        tab.push_back (p1);

     }



     plik.close();

    return tab;
    }





int main(int argc, char* argv[])
{
    if (argc!=2)
    {
        return -1;
    }
    cout << argv[1]<<endl;

    string nazwa_pliku = argv[1];

    vector <Probka> dane = wczytaj (nazwa_pliku);



    return 0;
}
