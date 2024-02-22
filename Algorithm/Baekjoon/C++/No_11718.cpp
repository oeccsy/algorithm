#include <iostream>

using namespace std;

char arr[101];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i=0; i<100; i++)
  {
    cin.getline(arr, 101);
    cout << arr << '\n';

    if(arr == "")
      break;
  }
    
  
}