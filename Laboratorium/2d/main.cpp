#include <iostream>
#include <limits.h>

using namespace std;

int main (int argc, char const *argv[])
{
  int d1, d2, m1, m2, y1, y2;
  cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
  
  int s1 = d1 + 100*m1 + 10000*y1;
  int s2 = d2 + 100*m2 + 10000*y2;
  
  if(s1 < s2) cout << "Pierwsza data jest wcześniejsza";
  else if(s1 > s2) cout << "Druga data jest wcześniejsza";
  else cout << "Obie daty są równe";
  cout << endl;
  
  
  return 0;
}