#define DATA_FILE "data.txt"

/*
	+ list_users
		// choose user
		+ list_tests(*user)
		+ new_test(*user)
	+ add_user
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Test;
struct User;
struct MenuItem;
void show_menu(MenuItem * items, int count);
void load_database();
void save_database();
void list_user_tests();
void new_user_test();
void list_users();
void add_user();

struct User {
	string first_name;
	string last_name;
	vector<Test> tests;
};
struct Test {
	User * user;
	int result;
};
struct MenuItem {
	string description;
	void (* function)();
};

vector<User> users;
User * current_user;
char operations[4] = { '+', '*', '-', '/' };


/*
//void check_answer(Test &test, int a, int b, int c, char oper){
//	switch(oper){
//		case '+':
//			if(a + b == c) test.result++;
//			break;
//		case '-':
//			if(a - b == c) test.result++;
//			break;
//		case '*':
//			if(a * b == c) test.result++;
//			break;
//	}
//}
*/

void clear_screen(){
	system("clear");
}

int random(int max){
	return rand() % max;
}



int main (int argc, char * const argv[]) {
	load_database();
	
	MenuItem a[] = {
		"Pokaż listę użytkowników", list_users,
		"Dodaj użytkownika", add_user
	};
	show_menu(a, sizeof(a) / sizeof(MenuItem));
	
	save_database();
	return 0;
}
	
	
	/*
	//clear_screen();
	//
	//	while(true){
	//		
	//		clear_screen();
	//		cout << "[1] Pokaż listę użytkowników" << endl;
	//		cout << "[2] Dodaj użytkownika" << endl;
	//		cout << "[0] Zakończ program" << endl;
	//		cout << "Wybierz pozycję z menu: ";
	//		cin >> option;
	//		clear_screen();
	//		
	//		
	//		switch (option) {
	//			case 1:
	//				while (true) {
	//					cout << "Lista użytkowników:" << endl;
	//					cout << " ID  | NAZWISKO             | IMIĘ       " << endl;
	//					cout << "-----------------------------------------" << endl;
	//					for(int i=0; i<users.size(); ++i){
	//						cout << " ";
	//						cout << setw(3) << (i+1) << " | ";
	//						cout << setw(20) << left << users.at(i).last_name << " | ";
	//						cout << setw(10) << users.at(i).first_name;
	//						cout << right << endl;
	//					}
	//					cout << endl;
	//					
	//					int user_id;
	//					
	//					cout << "Podaj ID użytkownika (0 aby powrócić): " << endl;
	//					cin >> user_id;
	//					
	//					if(user_id <= 0) break;
	//					
	//					if (user_id > users.size()) {
	//						cout << "Użytkownik o podanym ID nie istnieje!" << endl;
	//						continue;
	//					}
	//					
	//					User * user = &users[user_id-1];
	//					
	//					
	//					
	//					int opt = -1;
	//					
	//					while(true){
	//						if(opt == 0) break;
	//						
	//						clear_screen();
	//						cout << "Wybrałeś użytkownika: " << user->first_name << " " << user->last_name << endl;
	//						cout << "[1] Pokaż testy użytkownika" << endl;
	//						cout << "[2] Nowy test" << endl;
	//						cout << "[0] Powrót" << endl;
	//						cout << "Wybierz pozycję z menu: ";
	//						cin >> opt;
	//						
	//						switch (opt) {
	//							case 1:
	//								
	//								break;
	//								
	//							case 2:
	//								Test test;
	//								test.user = user;
	//								test.result = 0;
	//								int a,b,c;
	//								char oper;
	//								
	//								for(int i=1; i<=10; i++){
	//									cout << i << ") ";
	//									
	//									a = random(10);
	//									b = random(10);
	//									oper = operations[random(3)];
	//									
	//									cout << a << " " << oper << " " << b << " = ";
	//									cin >> c;
	//									
	//									check_answer(test, a, b, c, oper);
	//								}
	//								
	//								user->tests.push_back(test);
	//								
	//																
	//								cout << "Twój wynik to: " << test.result << "/10" << endl;
	//								cout << "Naciśnij enter aby powrócić";
	//								cin.ignore();
	//								cin.get();
	//								
	//								
	//								break;
	//								
	//								
	//							default:
	//								break;
	//						}
	//					}
	//					
	//					clear_screen();
	//					
	//				}
	//				
	//				
	//				break;
	//				
	//			case 2:
	//				{
	//					User user;
	//					cout << "Podaj dane nowego użytkownika:" << endl;
	//					cout << "Nazwisko: ";
	//					cin >> user.last_name;
	//					cout << "Imię: ";
	//					cin >> user.first_name;
	//					users.push_back(user);
	//					save_database();
	//					cout << "Użytkownik został pomyślnie dodany" << endl;
	//				}
	//				break;
	//				
	//			case 0:
	//				return 0;
	//				break;
	//				
	//				
	//			default:
	//				break;
	//		}
	//		
	//	}
	//	
 //   return 0;
//}//

*/

void show_menu(MenuItem * items, int count){
	int option;
	while(true){
		for(int i = 0; i < count; i++)
			cout << "[" << i+1 << "] " << items[i].description << endl;
		
		cout << "[0] Powrót/Zakończ" << endl;
		cout << "Wybierz opcję z menu: ";
		cin >> option;
		if(option == 0) break;
		if(option > count) {
			cout << "[ERROR] Podana opcja nie istnieje" << endl;
			continue;
		}
		clear_screen();
		items[option-1].function();
	}
}

void load_database() {
	ifstream f(DATA_FILE);
	if(f.good()){
		while (!f.eof()) {
			User user;
			f >> user.last_name;
			f >> user.first_name;
			if(user.last_name != "" && user.first_name != "")
				users.push_back(user);
		}
	}
	f.close();
}
void save_database() {
	ofstream f(DATA_FILE);
	if (f.good()){
		for(vector<User>::iterator i = users.begin(); i!=users.end(); ++i){
			f << i->last_name << endl;
			f << i->first_name << endl;
		}
	}
	else cout << "Wystąpił błąd podczas zapisu" << endl;
	f.close();
}

// tests
void list_user_tests(){
	
}
void new_user_test(){
	
}

// users
void list_users(){
	cout << "Lista użytkowników:" << endl;
	cout << " ID  | NAZWISKO             | IMIĘ       " << endl;
	cout << "-----------------------------------------" << endl;
	for(int i=0; i<users.size(); ++i){
		cout << " ";
		cout << setw(3) << (i+1) << " | ";
		cout << setw(20) << left << users.at(i).last_name << " | ";
		cout << setw(10) << users.at(i).first_name;
		cout << right << endl;
	}
	cout << endl;
	
	int user_id;
	while(true){
		cout << "Podaj ID użytkownika (0 aby powrócić): ";
		cin >> user_id;
		
		if(user_id <= 0) return;
		else if(user_id > users.size()) {
			cout << "[ERROR] Użytkownik o podanym ID nie istnieje!" << endl;
			continue;
		} else {
			break;
		}
	}
	
	current_user = &users[user_id-1];
	
	MenuItem a[] = {
		"Pokaż testy użytkowników", list_user_tests,
		"Nowy test", new_user_test
	};
	show_menu(a, sizeof(a) / sizeof(MenuItem));
	
}
void add_user(){
	
}


