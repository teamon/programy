#include <stdio.h>
#include <string.h>

void zamien(char * text, char * old_str, char * new_str){
	char * p = text;
	int o_len = strlen(old_str);
	int n_len = strlen(new_str);

	do {
		p = strstr(text, old_str);
		if(p){
			memmove(p + n_len, p + o_len, strlen(p + o_len) + 1);
			memcpy(p, new_str, n_len);
		}
	} while(p);
}

int main (int argc, char const *argv[])
{
	char t[200] = "Ala ma kota o Ola ma Asa";
	printf("%s\n", t);
	zamien(t, "ma", "miala");
	printf("%s\n", t);
	return 0;
}