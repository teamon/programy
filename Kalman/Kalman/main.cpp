#include <iostream>

#define KR 0.2
#define KQ 0.0003

using namespace std;

int main (int argc, char * const argv[]) {
	int x, x_ = 0;
	double P = 1.0, P_, K;
	
	while(cin >> x){
		P_ = P + KQ;
		K = P_ / (P_ + KR);
		x_ = x_ + K*(x - x_);
		P = (1 - K)*P_;
		cout << x << ' ' << x_ << endl;
	}

	return 0;
}
