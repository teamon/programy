#include <iostream>
#include <math.h>

using namespace std;

int main (int argc, char const *argv[])
{
	int a,b;
	cout << "Podaj liczbe a:";
	cin >> a;
	cout << "Podaj liczbe b:";
	cin >> b;
	cout << "Suma: " << (a+b) << endl;
	cout << "Iloczyn: " << (a*b) << endl;
	cout << "Potęga: " << pow(a,b) << endl;
	return 0;
}