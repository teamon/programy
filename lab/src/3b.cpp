#include <iostream>

using namespace std;

int main (int argc, char const *argv[]){
	float T[10];

	for(int i=0; i<10; i++){
	  cout << "Tab[" << (i+1) << "] = ";
	  cin >> T[i];
	}

	float sum = 0;
	float max, min;
	int p,z,n;
	max = min = T[0];

	for(int i=0; i<10; i++){
	  sum += T[i];
	  if(T[i] > max) max = T[i];
	  if(T[i] < min) min = T[i];
	  if(T[i] > 0) p++;
	  else if(T[i] == 0) z++;
	  else n++;
	}

	cout << "Suma: " << sum << endl;
	cout << "Srednia: " << (sum / 10) << endl;
	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
	cout << "Dodatnich: " << p << endl;
	cout << "Zerowych: " << z << endl;
	cout << "Ujemnych: " << n << endl;

	return 0;
}