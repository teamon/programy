#include <iostream>
#include <math.h>

using namespace std;

int main (int argc, char const *argv[])
{
	float a,b,c,d;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	
	d = b*b - 4*a*c;
	if(d < 0){
		cout << "Brak pierwiastkow" << endl;
	} else if(d == 0) {
		cout << "x0 = " << (-b/(2*a)) << endl;
	} else {
		cout << "x1 = " << (-b-sqrt(d)/(2*a)) << endl;
		cout << "x1 = " << (-b+sqrt(d)/(2*a)) << endl;
	}
	return 0;
}