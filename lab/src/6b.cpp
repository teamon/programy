#include <iostream>

using namespace std;

#define N 5

struct car {
	char brand[100];
	int year;
};

int car_n = 0;

int insert_data(car * p){
	int i=0;
	car c;
	char ans;
	do {
		cout << "Marka: ";
		cin >> c.brand;
		cout << "Rocznik: ";
		cin >> c.year;
		p[i] = c;
		i++;
		
		cout << "Wiecej? [t/n] ";
		cin >> ans;
	} while (ans != 'n' && i < N);
	
	return i;
}

void show_data(car * p, int n){
	car * t;
	for(int i=0 ; i<n; i++){
		t = p++;
		cout << (i+1) << " " << (t->brand) << " (" << (t->year) << ")" <<  endl;
	}
}

void search(car * p, int n){
	char brand[100];
	int year;
	cout << "Marka: ";
	cin >> brand;
	cout << "Rocznik: ";
	cin >> year;
	
	car data[N];
	car * t;
	int j=0;
	for(int i=0; i<n; i++){
		t = p++;
		if(t->year == year && strcmp(t->brand, brand) == 0) data[j++] = *t;
	}
	
	show_data(data, j);
}


int main (int argc, char const *argv[])
{
	car data[N];
	car_n = insert_data(data);
	show_data(data, car_n);
	char ans;
	do {
		search(data, car_n);
		cout << "Jeszcze? [t/n] ";
		cin >> ans;
	} while (ans != 'n');
	return 0;
}