#include <iostream>

using namespace std;

int main (int argc, char const *argv[])
{
  int a,b,c;
  
  cin >> a >> b >> c;
  
  if(a+b>c && a+c>b && b+c>a) cout << "Można zbudować trójkąt";
  else cout << "Nie można zbudować trójkąta";
  cout << endl;
  
  return 0;
}