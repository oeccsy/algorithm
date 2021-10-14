#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> Edge; //간선 : 가중치, 정점,정점
int parent[1001]; //index는 각각의 정점, value는 해당 정점의 parent

int n = 0;
int m = 0;

void Input();
int Root(int x); //해당 정점의 root를 찾아서 반환하는 함수
void Union(int x, int y); //두 정점 연결 : y가 x에 합류됨, 한번 연결이 완료되면 절대로 번복하지 않음

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int total=0;

  Input();
  sort(Edge.begin(), Edge.end()); //간선 정렬
  for(int i=0; i<m; i++) //그리디 //while에 !Edge.empty()가 나을듯?
  {
    pair<int, pair<int, int>> curValue = Edge[i];

    if(Root(curValue.second.first) != Root(curValue.second.second)) //curValue = vector.begin() -> 안되나?
    {
      Union(curValue.second.first, curValue.second.second);
      total += curValue.first;
    }
    //else pop? pop_back? 내림차순으로 정렬했어야하나?
    
  }

  cout << total;

  return 0;
}

void Input()
{
  cin >> n;
  cin >> m;

  for(int i=0; i<m; i++)
  {
    int v1, v2, l;
    cin >> v1 >> v2 >> l;
    Edge.push_back({l, {v1,v2}});
  }

  //Init
  for(int i=1; i<=n; i++) //int i = 1부터 시작함에 주의해야한다.
  {
    parent[i] = i;
  }
}

int Root(int x)
{
  if(parent[x] == x)
    return x;
  else
  {
    parent[x] = Root(parent[x]); //다음에 빨리 찾을 수 있도록 root를 저장해준다.
    return parent[x];
  }
    
}

void Union(int x, int y)
{
  int x_root = Root(x);
  int y_root = Root(y);
  
  parent[y_root] = x_root; //이게 왜 y는 안되고 y_root만 되는걸까 -> Union은 루트끼리 하지 않으면 꼬임, y 위의 그룹이 잘려서 분리된 그룹이 만들어져버림
}