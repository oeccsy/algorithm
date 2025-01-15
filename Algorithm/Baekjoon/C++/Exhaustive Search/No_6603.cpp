#include <iostream>

using namespace std;

int k;
int set[49];
bool is_used[49];
int selected[6];

void Select(int index)
{
    if(index == 6)
    {
        for(int i=0; i<6; i++)
        {
            cout << selected[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=0; i<k; i++)
    {
        if(is_used[i]) continue;
        if(index > 0 && selected[index-1] > set[i]) continue;
        
        selected[index] = set[i];
        is_used[i] = true;
        Select(index+1);
        is_used[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true)
    {
        cin >> k;
        if(k == 0) break;

        for(int i=0; i<k; i++)
        {
            int input;
            cin >> input;

            set[i] = input;
        }

        Select(0);
        
        cout << '\n';
    }
}