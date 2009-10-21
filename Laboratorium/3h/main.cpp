#include <iostream>

using namespace std;

int main (int argc, char const *argv[])
{
  int i=0, p, x, sum = 0;
  
  while(cin >> x)
  {
    sum += x;
    if(x < 0) i++;
    
    if(sum > 100 || i > 10 || p == x) break;
    p = x;
  }
  
  return 0;
}