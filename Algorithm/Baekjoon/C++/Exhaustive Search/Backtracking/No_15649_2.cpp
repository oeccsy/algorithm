#include <iostream>

using namespace std;

int n,m;
int selected[8];
bool is_used[9];

void Select(int index)
{
    if(index < 0)
        return;
    if(index == m)
    {
        for(int i=0; i<m; i++)
        {
            cout << selected[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    //현재 state에서 할 수 있는 step을 순회한다.
    for(int i=1; i<=n; i++)
    {
        if(is_used[i]) continue;
        is_used[i] = true;
        selected[index] = i;
        
        //해당 Step에서의 다음 Step을 진행한다
        Select(index+1);
        is_used[i] = false;
    }
}

int main()
{
    cin >> n >> m;
    Select(0);
}