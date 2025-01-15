#include <iostream>

using namespace std;

int arr[10001]= {0,};
int n;

void Input();
void Output();

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Input();
  Output();
}

void Input()
{
  cin >> n;

  for(int i=0; i<n; i++)
  {
    int input;
    cin >> input;

    arr[input]++;
  }
}

void Output()
{
  int value=0;

  for(int i=0; i<n;)
  {
    if(arr[value] > 0)
    {
      cout << value <<'\n';
      arr[value]--;
      i++;
    }
    else
    {
      value++;
    }
    
  }
}