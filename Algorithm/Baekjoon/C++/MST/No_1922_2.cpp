#include <iostream>

using namespace std;

typedef struct Edge
{
  int value;
  int v1;
  int v2;
} Edge;

Edge edgeList[1000001];
Edge tempList[1000001];

int n = 0;
int m = 0;
int parent[1001]; //index는 각각의 정점, value는 해당 정점의 parent

void Input();
void SortEdge(int left, int right);
void Merge(int left, int right);
int Root(int x); //해당 정점의 root를 찾아서 반환하는 함수
void Union(int x, int y); //두 정점 연결 : y가 x에 합류됨, 한번 연결이 완료되면 절대로 번복하지 않음


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int total=0;

  Input();
  SortEdge(0, m-1);
  
  for(int i=0; i<m; i++)
  {
    Edge curEdge = edgeList[i];

    if(Root(curEdge.v1) != Root(curEdge.v2))
    {
      Union(curEdge.v1, curEdge.v2);
      total += curEdge.value;
    }
    
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
    int v1, v2, value;
    cin >> v1 >> v2 >> value;
    Edge newEdge = {value, v1, v2};
    edgeList[i] = newEdge;
  }

  //Init
  for(int i=1; i<=n; i++) //int i = 1부터 시작함에 주의해야한다.
  {
    parent[i] = i;
  }
}

void SortEdge(int left, int right)
{
  if(left < right)
  {
    int k = (left+right)/2;
    SortEdge(left, k);
    SortEdge(k+1, right);
    Merge(left, right);
  }

}

void Merge(int left, int right)
{
  int k = (left+right)/2;
  int low = left;
  int high = k+1;

  for(int i =left; i<=right; i++)
  {
    if(low == k+1)
      tempList[i] = edgeList[high++];
    else if(high == right+1)
      tempList[i] = edgeList[low++];
    else if(edgeList[low].value <= edgeList[high].value)
      tempList[i] = edgeList[low++];
    else
      tempList[i] = edgeList[high++];
  }

  for(int i = left; i<= right; i++)
  {
    edgeList[i] = tempList[i];
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