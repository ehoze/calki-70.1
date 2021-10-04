#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

ifstream in;
ofstream out;

class zadanie
{
	public:
		double f(double x);
		double Pole();
};

double f(double x) 
{ 
//	cout << x*x << endl;
	return x*x; 
}

double Pole()
{
	double xp, xk, h, calka, calka2;
    int n;

    // przedzialy
    cout << "Przedzial 1: "; cin >> xp;
    cout << "Przedzial 2: "; cin >> xk;
//	xp = 2;
//	xk = 10;

    // im wieksze n tym wieksza dokladnosc (tym wiecej prostok¹tow)
    cout << "Ile prostokatow: "; cin >> n;
//	n = 1000;
    h = (xk - xp) / (float)n;

    cout << "Dokladnosc: " << h << endl;

    calka = 0;
    calka2 = 0;

    for (int i=1; i<=n; i++)
    {
        calka += f(xk - i*h)*h;
        calka2 += f(xp + i*h)*h;
    }

    cout << "Wynik - calka 1: " <<  calka << endl;
    cout << "Wynik - calka 2: " <<  calka2 << endl;	
    
    float bledny = 8 * 56.0945;
    cout << "Koncowy wynik: " << bledny << " - " << calka2 << " = " << bledny - calka2 << endl;
}

int main()
{
	zadanie x;
	out.open("zadanie_zaslony.txt");
	
	Pole();
	
	out.close();
	return 0;
}
