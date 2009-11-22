#define DATA_FILE "data.txt"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct User {
	string first_name;
	string last_name;
};

vector<User> users;


void load_database() {
	ifstream f(DATA_FILE);
	if(f.good()){
		while (!f.eof()) {
			User user;
			f >> user.last_name;
			f >> user.first_name;
			users.push_back(user);
		}
	}
	f.close();
}

void save_database() {
	ofstream f(DATA_FILE);
	if (f.good()){
		for(vector<User>::iterator i = users.begin(); i!=users.end(); ++i){
			f << i->last_name;
			f << i->first_name;
		}
	}
	else cout << "Wystąpił błąd podczas zapisu" << endl;
	f.close();
}

int main (int argc, char * const argv[]) {
	int option = 0;
	
	load_database();
	
	
	while(true){
		User user;
		
		cout << "Wybierz pozycję z menu:" << endl;
		cout << "[1] Pokaż listę użytkowników" << endl;
		cout << "[2] Dodaj użytkownika" << endl;
		cout << "[9] Zakończ program" << endl;
		cin >> option;
		system("clear");
		
		switch (option) {
			case 1:
				cout << "Lista użytkowników:" << endl;
				cout << " ID  | NAZWISKO             | IMIĘ       " << endl;
				cout << "-----------------------------------------" << endl;
				for(int i=0; i<users.size(); ++i){
					cout << right << " " << setw(3) << (i+1) << " | ";
					cout << left << setw(20) << users.at(i).last_name << " | ";
					cout << setw(10) << users.at(i).first_name;
					cout << endl;
				}
				cout << endl;
				break;
				
			case 2:
				cout << "Podaj dane nowego użytkownika:" << endl;
				cout << "Imię: ";
				cin >> user.first_name;
				cout << "Nazwisko: ";
				cin >> user.last_name;
				break;
				
			case 9:
				return 0;
				break;
				
				
			default:
				
				break;
		}
		
	}
	
    return 0;
}
