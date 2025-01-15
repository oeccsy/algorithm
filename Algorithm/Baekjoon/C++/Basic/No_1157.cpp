#include <iostream>

using namespace std;

int main()
{
  int arr[26] ={0,};
  char input[1000010];

  int maxCount = 0;
  char output = '?';
  bool isTwoMaxValue = true;
  
  cin >> input;

  for(int i = 0; input[i] != '\0'; i++)
  {
    int arr_index = 0;
    if(input[i] < 'a') //input의 글자를 하나씩 읽는다.
      arr_index = input[i]-'A';
    else
      arr_index = input[i]-'a';

    arr[arr_index]++;
  }

  for(int i=0; i<26; i++)
  {
    if((int)arr[i] > maxCount)
    {
      isTwoMaxValue = false;
      maxCount = arr[i];
      output = 'A' + i;
    }
    else if ((int)arr[i] == maxCount)
    {
      isTwoMaxValue = true;
      output = '?';
    }
  }

  cout <<output;
}