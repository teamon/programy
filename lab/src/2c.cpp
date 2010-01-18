#include <iostream>

using namespace std;


int main (int argc, char const *argv[])
{
	int a,i=1, max, min,sum;
	char c;
	
	cout << "Podaj liczbe: ";
	cin >> a;
	max = a;
	min = a;
	sum = a;
	
	while(1){
		cout << "Koniec?[T/N] ";
		cin >> c;
		if(c == 'T') break;
		
		cout << "Podaj liczbe: " << endl;
		cin >> a;
		
		if(a > max) max = a;
		if(a < min) min = a;
		sum += a;
	}
	
	cout << "srednia = " << (sum/i) << endl;
	cout << "max = " << max << endl;
	cout << "min = " << min << endl;
	return 0;
}