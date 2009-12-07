#define USERS_DATA_FILE "users.txt"
#define TESTS_DATA_FILE "tests.txt"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct Test;
struct User;
struct MenuItem;
void show_menu(MenuItem * items, int count);
void show_menu(MenuItem * items, int count, bool(* break_menu)());
void load_database();
void load_users_database();
void load_tests_database();
void save_users_database();
void save_tests_database();
void save_database();
void list_tests();
void list_user_tests();
void new_user_test();
void list_users();
void add_user();
void delete_user();
void update_user();
bool deleted_user();

struct User {
	unsigned int id;
	string first_name;
	string last_name;
};
struct Test {
	int id;
	int user_id;
	int result;
};
struct MenuItem {
	string description;
	void (* function)();
};

User * users;
Test * tests;
int users_num, tests_num;
int users_max_id, tests_max_id;

User * current_user;
char operations[4] = { '+', '*', '-', '/' };

void clear_screen(){
	system("clear");
}
int random(int max){
	return rand() % max;
}

int main (int argc, char * const argv[]) {
	load_database();

	MenuItem items[] = {
		"Pokaż listę użytkowników", list_users,
		"Dodaj użytkownika", add_user,
		"Pokaż liste testów", list_tests
	};
	show_menu(items, sizeof(items) / sizeof(MenuItem));

	save_database();
	return 0;
}
void load_database() {
	load_users_database();
	load_tests_database();
}

int compare_users(const void * a, const void * b){	
	short c = (((User *)a)->last_name).compare(((User *)b)->last_name);
	if(c == 0) return (((User *)a)->first_name).compare(((User *)b)->first_name);
	else return c;
}
void load_users_database(){
	ifstream f(USERS_DATA_FILE);
	if(f.good()){
		f >> users_num;
		users_max_id = 0;
		users = new User[users_num];
		int i=0;
		while (!f.eof() && i < users_num) {
			User user;
			f >> user.id;
			f >> user.last_name;
			f >> user.first_name;
			if(user.last_name != "" && user.first_name != ""){
				users[i] = user;
				if(user.id > users_max_id) users_max_id = user.id;
				i++;
			}
		}
		f.close();
	}
	
	qsort(users, users_num, sizeof(User), compare_users);
	
}
void load_tests_database(){
	ifstream f(TESTS_DATA_FILE);
	if(f.good()){
		f >> tests_num;
		tests_max_id = 0;
		tests = new Test[tests_num];
		int i=0;
		while (!f.eof() && i < tests_num) {
			Test test;
			f >> test.id;
			f >> test.user_id;
			f >> test.result;
			tests[i] = test;
			if(test.id > tests_max_id) tests_max_id = test.id;
			i++;
			
		}
		f.close();
	}
}

void save_database() {
	save_users_database();
	save_tests_database();
}
void save_users_database(){
	ofstream f(USERS_DATA_FILE);
	if (f.good()){
		f << users_num << endl;
		
		for(User *u = users; u < users+users_num; u++){
			f << u->id << endl;
			f << u->last_name << endl;
			f << u->first_name << endl;
		}
	}
	else cout << "Wystąpił błąd podczas zapisu" << endl;
	f.close();
	
}
void save_tests_database(){
	ofstream f(TESTS_DATA_FILE);
	if (f.good()){
		f << tests_num << endl;
		
		for(Test *t = tests; t < tests+tests_num; t++){
			f << t->id << endl;
			f << t->user_id << endl;
			f << t->result << endl;
		}
	}
	else cout << "Wystąpił błąd podczas zapisu" << endl;
	f.close();
}
	
void show_menu(MenuItem * items, int count){
	show_menu(items, count, NULL);
}
void show_menu(MenuItem * items, int count, bool (* break_menu)()){
	int option;
	while(true){
		if(break_menu && break_menu()) break;
		
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

User * get_user(int user_id){
	for(User * u = users; u<users+users_num; u++)
		if(u->id == user_id) return u;
	return NULL;
}



void list_tests(){
	cout << "Lista testów:" << endl;
	cout << "  ID |  WYNIK | NAZWISKO             | IMIĘ       " << endl;
	cout << "--------------------------------------------------" << endl;
	
	int sum=0;
	User * user;
	
	for(int i=0; i<tests_num; i++){
		cout << " ";
		cout << setw(3) << tests[i].id << " | ";
		cout << setw(3) << tests[i].result << "/10" << " | ";
		
		user = get_user(tests[i].user_id);
		
		cout << setw(20) << left << user->last_name << " | ";
		cout << setw(10) << user->first_name;
		cout << right << endl;
		
		sum += tests[i].result;
	}
	cout << "--------------------------------------------------" << endl;
	cout << "RAZEM: " << sum << "/" << tests_num*10 << " (" << setprecision(2) << (((float)sum)/tests_num*10) << "%)" << endl;	
}

void list_user_tests(){
	cout << "Lista testów:" << endl;
	cout << "  ID |  WYNIK  " << endl;
	cout << "---------------" << endl;
	
	int sum=0,k=0;
	
	for(int i=0; i<tests_num; i++){
		if(tests[i].user_id == current_user->id){
			cout << " ";
			cout << setw(3) << tests[i].id << " | ";
			cout << setw(3) << tests[i].result << "/10" << endl;
			k++;
			sum += tests[i].result;
		}
	}
	cout << "--------------" << endl;
	cout << "RAZEM: " << sum << "/" << k*10 << " (" << setprecision(2) << (((float)sum)/k*10) << "%)" << endl;	
	
}
void new_user_test(){
	Test test;
	test.user_id = current_user->id;
	test.result = 0;
	int a,b,c;
	char oper;
	
	for(int i=1; i<=10; i++){
		cout << i << ") ";
		a = random(10);
		b = random(10);
		oper = operations[random(4)];
		
		if(oper == '/') cout << (a*b);
		else cout << a;
			
		cout << " " << oper << " " << b << " = ";
		cin >> c;
		
		switch(oper){
			case '+':
				if(a + b == c) test.result++;
				break;
			case '-':
				if(a - b == c) test.result++;
				break;
			case '*':
				if(a * b == c) test.result++;
				break;
			case '/':
				if(c == a) test.result++;
				break;
		}
	}
		
	Test * old_tests = tests;
	
	test.id = ++tests_max_id;
	tests_num++;
		
	tests = new Test[tests_num];
	for(int i=0; i<tests_num-1; i++) tests[i] = old_tests[i];
	tests[tests_num-1] = test;
	save_database();
	
	cout << "Twój wynik to: " << test.result << "/10" << endl;
	cout << "Naciśnij enter aby powrócić";
	cin.ignore();
	cin.get();
}



void list_users(){
	cout << "Lista użytkowników:" << endl;
	cout << " ID  | NAZWISKO             | IMIĘ       " << endl;
	cout << "-----------------------------------------" << endl;
	for(int i=0; i<users_num; ++i){
		cout << " ";
		cout << setw(3) << users[i].id << " | ";
		cout << setw(20) << left << users[i].last_name << " | ";
		cout << setw(10) << users[i].first_name;
		cout << right << endl;
	}
	cout << endl;
	
	int user_id;
	while(true){
		cout << "Podaj ID użytkownika (0 aby powrócić): ";
		cin >> user_id;
		
		if(user_id <= 0) return;
		else {
			current_user = get_user(user_id);
			if(current_user == NULL){
				cout << "[ERROR] Użytkownik o podanym ID nie istnieje!" << endl;
				continue;
			} else {
				break;
			}
		}
		
		
	}

	MenuItem items[] = {
		"Pokaż testy użytkownika", list_user_tests,
		"Nowy test", new_user_test,
		"Zmień dane użytkownika", update_user,
		"Usuń użytkownika", delete_user
	};
	show_menu(items, sizeof(items) / sizeof(MenuItem), deleted_user);
}
void add_user(){
	User new_user;
	cout << "Podaj dane nowego użytkownika:" << endl;
	cout << "Nazwisko: ";
	cin >> new_user.last_name;
	cout << "Imię: ";
	cin >> new_user.first_name;
	new_user.id = ++users_max_id;
	users_num++;
	
	User * old_users = users;
	
	users = new User[users_num];
	for(int i=0; i<users_num-1; i++) users[i] = old_users[i];
	users[users_num-1] = new_user;
	
	save_database();
}
void delete_user(){
	User * old_users = users;
	users_num--;
	
	users = new User[users_num];
	int i = 0;
	User * u = old_users;
	
	for(; u < current_user; u++, i++) users[i] = *u;
	for(u++; u<old_users+users_num+1; u++, i++) users[i]= *u;
	
	
	Test * old_tests = tests;
	int count=0;
	for(int j=0; j<tests_num; j++){
		if(tests[j].user_id == current_user->id) count++;
	}
	
	
	tests = new Test[tests_num-count];
	
	for(int j=0, k=0; j<tests_num; j++){
		if(tests[j].user_id != current_user->id) {
			tests[k] = old_tests[j];
			k++;
		}
	}
	
	tests_num -= count;
	
	current_user = NULL;
	save_database();
}
void update_user(){
	cout << "Podaj nowe dane użytkownika:" << endl;
	cout << "Nazwisko: ";
	cin >> current_user->last_name;
	cout << "Imię: ";
	cin >> current_user->first_name;
	save_database();
}

bool deleted_user(){
	return current_user == NULL;
}

