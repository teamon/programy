#include <iostream>

using namespace std;

int main (int argc, char const *argv[])
{
	int tab[5], sum, max, min;
	
	// wczytaj
	for(int * p = tab; p < tab + 5; p++) cin >> *p;

	max = min = *tab;
	for(int * p = tab; p < tab + 5; p++){
		cout << *p << endl;
		if(*p > max) max = *p;
		if(*p < min) min = *p;
	} 
	
	cout << "max = " << max << endl;
	cout << "min = " << min << endl;
	
	return 0;
}