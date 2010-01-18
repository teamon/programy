#include <iostream>

using namespace std;

int main (int argc, char const *argv[])
{
	int w;
	cout << "Podaj wzrost: ";
	cin >> w;
	if(w > 180)	cout << "wysoki";
	else if(w > 150) cout << "sredni";
	else cout << "niski";
	cout << endl;
	return 0;
}