#include <iostream>
#include <queue>

using namespace std;

int d[5005][5]; //[i]를 [j]자리로 해독한 경우 경우의 수

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string code;
  cin >> code;

  int target_num;
  target_num = code[0] - '0';
  d[0][1] = (0 < target_num && target_num <= 9) ? 1 : 0;

  target_num = 10 * (code[0] - '0') + code[1] - '0';
  d[0][2] = (10 <= target_num && target_num <= 26) ? 1 : 0;
  
  target_num = code[1] - '0';
  d[1][1] = (0 < target_num && target_num <= 9) ? d[0][1] : 0;

  target_num = 10 * (code[1] - '0') + code[2] - '0';
  d[1][2] = (10 <= target_num && target_num <= 26) ? d[0][1] : 0;
  
  for(int i=2; i<code.length(); i++)
  {
    target_num = code[i] - '0';
    d[i][1] = (0 < target_num && target_num <= 9) ? (d[i-1][1] + d[i-2][2]) % 1000000 : 0;

    target_num = 10 * (code[i] - '0') + code[i+1] - '0';
    d[i][2] = (10 <= target_num && target_num <= 26) ? (d[i-1][1] + d[i-2][2]) % 1000000 : 0;
  }

  cout << (d[code.length()-1][1] + d[code.length()-2][2]) % 1000000;
}