#include <iostream>

using namespace std;

int main (int argc, char const *argv[])
{
  char c;
  int j=0, i=0;
  
  while(cin >> c)
  {
    if(c == 'k')
    {
      cout << "Znaków wprowadzonych przed k: " << i << endl;
      cout << "Dużych liter: " << j << endl;
      break;
    }
          
    i++;
    if(c >= 65 && c <= 90) j++;
  }
  return 0;
}