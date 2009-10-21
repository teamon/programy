#include <iostream>

using namespace std;

int main (int argc, char const *argv[])
{
  int i,j,k;
  
  for(k=0; k<3; k++)
  {
    for(i=1; i<=10; i++) 
    {
      for(j=0; j<10000; j++);
      cout << i << endl;
    }
    for(i=10; i>0; i--)
    {
      for(j=0; j<10000; j++);
      cout << i << endl;
    }
  }

  return 0;
}