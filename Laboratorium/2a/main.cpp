#include <iostream>

using namespace std;

int main (int argc, char const *argv[])
{
  int height;
  
  cout << "Podaj wzrost: ";
  cin >> height;
  
  if(height < 150) cout << "niski";
  else if(height < 180) cout << "średni";
  else cout << "wysoki";
  
  cout << endl;
  
  return 0;
}