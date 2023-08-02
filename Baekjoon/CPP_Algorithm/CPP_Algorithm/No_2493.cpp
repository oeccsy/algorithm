#include <iostream>
#include <stack>

using namespace std;

struct Laser
{
    int height;
    int pos;
};

int result[500001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> tower;
    stack<Laser> laser_stack;
    
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int input;
        cin >> input;
        tower.push(input);
    }

    for(int i=0; i<n; i++)
    {
        Laser new_laser = Laser();
        new_laser.height = tower.top();
        new_laser.pos = tower.size();
        laser_stack.push(new_laser);
        tower.pop();

        while(true)
        {
            if(laser_stack.empty())
            {
                break;
            }
            else if(tower.empty())
            {
                result[laser_stack.top().pos] = 0;
                laser_stack.pop();
            }
            else if(tower.top() >= laser_stack.top().height)
            {
                result[laser_stack.top().pos] = tower.size();
                laser_stack.pop();
            }
            else
            {
                break;
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        cout << result[i] << " ";
    }
}
