#include <iostream>

using namespace std;

void menu(){
	cout << "1. Suma" << endl;
	cout << "2. Iloczyn" << endl;
	cout << "3. Koniec" << endl;
}

void suma(){
	int a,b;
	cout << "a = ";
	cin >> a;
	cout << "a = ";
	cin >> b;
	cout << "suma = " << (a+b) << endl;
}

void iloczyn(){
	int a,b;
	cout << "a = ";
	cin >> a;
	cout << "a = ";
	cin >> b;
	cout << "iloczyn = " << (a*b) << endl;
}

int main (int argc, char const *argv[])
{
	int a;
	while(1){
		menu();
		cin >> a;
		switch(a){
			case 1:
				suma();
			break;
			
			case 2:
				iloczyn();
			break;
			
			case 3:
				return 0;
			break;
		}
	}

	return 0;
}