#include <iostream>

using namespace std;

int moje_strlen(char * c){
	int i = 0;
	while(*(c++) != '\0') i++;
	return i;
}

char * moje_strupr(char * c){
	char * p = c;
	while(*p){
		if(*p >= 'a' && *p <= 'z') *p -= 32;
		p++;
	}
	return c;
}

char * moje_strcpy(char * to, char * from){
	char * pto = to;
	char * pfrom = from;
	while(*pfrom) *pto++ = *pfrom++;
	return from;
}

int main (int argc, char const *argv[])
{
	char s[100];
	char n[100];
	cin >> s;
	cout << "strlen = " << moje_strlen(s) << endl;
	cout << "strupr = " << moje_strupr(s) << endl;
	moje_strcpy(n, s);
	cout << "strcpy = " << n << endl;
	return 0;
}