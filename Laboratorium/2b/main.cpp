#include <iostream>

using namespace std;

int main (int argc, char const *argv[])
{
  int a,b,c;
  
  cin >> a >> b >> c;
  
  if(a > b)
  {
    if(a > c)
    {
      if(b > c) // a > b > c
      {
        
      }
      else // a > c > b
      {
        
      }
    }
    else
    {
      if(b > c) // b > c > a
      {
        
      }
      else // c > b > a
      {
        
      }
    }
  } 
  else // a < b
  {
    if(a > c)
    {
      if(b > c) //  b a c
      {
        
      }
      else // a > c > b
      {
        
      }
    }
    else
    {
      if(b > c) // b > c > a
      {
        
      }
      else // c > b > a
      {
        
      }
    }
  }
  return 0;
}