#include <iostream>

using namespace std;

int main (int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=n; i<100; i+=n) cout << i << endl;
  return 0;
}