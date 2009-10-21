#include <iostream>
#include <math.h>

using namespace std;

int main (int argc, char const *argv[])
{
  int x, n;
  float sum = 0;
  cin >> x >> n;
  
  for(int i=1; i<=n; i++)
  {
    sum += 1/ pow(x, i);
  }
  
  cout << sum << endl;
  return 0;
}