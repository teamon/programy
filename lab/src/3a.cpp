#include <iostream>

using namespace std;

int main (int argc, char const *argv[]){
	float T[10];

	for(int i=0; i<10; i++){
	  cout << "Tab[" << (i+1) << "] = ";
	  cin >> T[i];
	}

	for(int i=0; i<10; i++){
	  cout << T[i] << endl;
	}

	return 0;
}