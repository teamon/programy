#include <iostream>
#include <math.h>

using namespace std;

int main (int argc, char const *argv[])
{
	int x,n;
	float s=0;
	cout << "n = ";
	cin >> n;
	cout << "x = ";
	cin >> x;
	for(int i=0; i<n; i++) s += 1.0/pow(x,n);
	cout << "suma = " << s << endl;
	return 0;
}