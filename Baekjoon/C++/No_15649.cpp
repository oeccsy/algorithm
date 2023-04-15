#include <iostream>

using namespace std;

int N;
int M;

void Input();
void Output();

int main()
{
  Input();
  Output();
}

void Input()
{
  // N : 1부터 N까지의 자연수 중에 고를 수 있음
  // M : M개를 고른 수열의 수를 중복 없이 Return 해야함

  scanf("%n %n", &N, &M);
}

void Output()
{
  for(int i=1; i<=N; i++)
  {
    for(int j=1; j<=N; j++)
    {
      if(i == j)
      {
        continue;
      }
      else
      {
        printf("%d %d", i, j);
      }
    }
  }
}