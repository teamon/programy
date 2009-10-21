#include <iostream>
#include <math.h>

using namespace std;

char t[256];

int main (int argc, char * const argv[]) {
	unsigned char a, min, x = 1;
	
	char bit = 5;
	int m = pow(2, bit-1);
	int n = m * 2;
	
	for(int j=0; j<n; j++){
		if(t[j]) continue;
		
		min = x = j;
		
		for(int i=0; i<bit; i++){
			a = (x & m) / m;
			x = x << 1;
			
			if(x >= n) x = x - n;
			
			x = x | a;
			if(x < min) min = x;
			t[x] = 1;
		}
		
		cout << j << " => " << (int)min << endl;
	}
	
	
	return 0;
}
