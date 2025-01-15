#include <iostream>

using namespace std;

int n;
char num[101];
int total =0;

int main()
{
  cin >> n;
  cin.ignore();
  cin.getline(num, 101);
  
  for(int i=0; i<n; i++)
  {
    total += (int)num[i]-'0';
  }

  cout << total;
}