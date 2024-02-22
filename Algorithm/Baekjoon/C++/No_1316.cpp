#include <iostream>

using namespace std;

void Input();
void Output();
void ArrInit();
void Check(char str[]);

int n;
int answer=0;
int arr[26]={0,};

char str[100];

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

  for(int i =0; i<n; i++)
  {
    cin >> str;
    Check(str);
    ArrInit();
  }
}

void Output()
{
  cout << answer;
}

void ArrInit()
{
  for(int i =0; i<26; i++)
  {
    arr[i] =0;
  }
}

void Check(char str[])
{
  char checker = str[0];
  int i = 1;

  arr[checker-'a']++;

  while(str[i] != '\0')
  {
    char curChar = str[i];

    if(curChar != checker)
    {
      checker = curChar;

      if(arr[curChar-'a'] != 0)
        return;
    }
      
    arr[curChar-'a']++;
    i++;
  }

  answer++;
}