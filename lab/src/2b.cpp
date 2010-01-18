#include <iostream>

using namespace std;

int main (int argc, char const *argv[])
{
	char c;
	int i=0,j=0;
	while(cin >> c){
		if(c >= 'A' && c <= 'Z') j++;
		if(c == 'k') break;
		i++;
		cout << c << endl;
	}
	
	cout << "Ilosc znakow: " << i << endl;
	cout << "Ilosc duzych: " << j << endl;
	
	return 0;
}