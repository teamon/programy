#include <iostream>

using namespace std;

int main (int argc, char const *argv[])
{
  int a, sum, i=1, max, min;
  char ans;
  
  cin >> a;
  sum = a;
  max = min = a;
  
  while(1)
  {
    do 
    {
      cout << "Czy to koniec wprowadzania? (T/N) ";
      cin >> ans;
    } 
    while(ans != 'T' && ans != 'N');
      
    if(ans == 'T')
    {
      cout << "średnia: " << (sum / i) << ", max: " << max << ", min: " << min << endl;
      break;
    }
    
    cin >> a;
    sum += a;
    
    if(a > max) max = a;
    if(a < min) min = a;
    
    i++;
    
  }

  return 0;
}