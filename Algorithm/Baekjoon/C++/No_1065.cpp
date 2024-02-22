#include <iostream>

using namespace std;

int n;
int answer=0;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for(int i=1; i<=n; i++)
  {
    int num = i;

    if(num<100)
    {
      answer++;
      continue;
    }

    if(i ==1000)
      break;
      
    int a1, a2, a3; //a1 + a3 = 2 * a2;
    a1 = (i/100) % 10;
    a2 = (i/10) % 10;
    a3 = i % 10;

    
    if(a1 + a3 == a2 + a2)
    {
      answer++;
    }
  }

  cout << answer;
}