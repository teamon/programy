#include <iostream>

#define N 5

using namespace std;

void WCZYTAJ_TAB(int * p){
	cout << "Wczytaj tablice" << endl;
	for(int i=0; i<N; i++) {
		cout << "tab[" << i << "] = ";
		cin >> *(p++);
	}
}

void WYPISZ_TAB(int * p){
	for(int i=0; i<N; i++){
		cout << "tab[" << i << "] = " << *(p++) << endl;;
	}
}

void SUMA_TAB(int * a, int * b, int * c){
	for(int i=0; i<N; i++){
		*(c++) = *(a++) + *(b++);
	}
}

int main (int argc, char const *argv[]){
	int A[N], B[N], C[N];
	WCZYTAJ_TAB(A);
	WCZYTAJ_TAB(B);
	
	SUMA_TAB(A, B, C);
	
	WYPISZ_TAB(A);
	WYPISZ_TAB(B);
	WYPISZ_TAB(C);
	
	return 0;
}