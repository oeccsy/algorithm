#include <iostream>
#include <utility>

using namespace std;

char classroom[5][5];
bool is_used[5][5];

pair<int, int> selected[7];
int result = 0;

void Select(int index, pair<int,int> min)
{
    if(index == 7)
    {
        for(int i=0; i<7; i++)
        {
            cout << selected[i].first << selected[i].second << " ";
        }
        cout << '\n';
        
        int count_s = 0;
        
        for(int i=0; i<7; i++)
        {
            if(classroom[selected[i].first][selected[i].second] == 'S')
                count_s++;
        }

      
            result++;
        
        return;
    }

    for(int i=min.first; i<5; i++)
    {
        for(int j=min.second; j<5; j++)
        {
            if(is_used[i][j]) continue;
            
            selected[index] = {i,j};

            is_used[i][j] = true;
            Select(index+1, {i,j});
            is_used[i][j] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            char input;
            cin >> input;
            classroom[i][j] = input;
        }
    }

    Select(0, {0,0});

    cout << result;
}