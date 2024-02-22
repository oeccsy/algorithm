#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n;
    int m;
    deque<int> a;
    int answer = 0;
    int count;
    
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        a.push_back(i);    
    }

    cin >> m;

    for(int i=0; i<m; i++)
    {
        int input;
        cin >> input;

        count = 0;
        
        while(true)
        {
            if(a.front() == input)
            {
                if(count <= a.size()/2)
                {
                    answer += count;
                }
                else
                {
                    answer += a.size() - count;
                }

                a.pop_front();
                
                break;
            }
            else
            {
                a.push_back(a.front());
                a.pop_front();
                count++;
            }
        }
    }

    cout << answer;
}