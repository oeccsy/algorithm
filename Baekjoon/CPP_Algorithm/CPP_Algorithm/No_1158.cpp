#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    list<int> people;
    int n,k;
    cin >> n >> k;

    for(int i=1; i<=n; i++)
    {
        people.push_back(i);
    }

    auto target = people.begin();

    cout << "<";
    
    while(true)
    {
        for(int i=1; i<k; i++)
        {
            target++;
            if(target == people.end())
            {
                target = people.begin();
            }
        }

        cout << *target;
        target = people.erase(target);
        if(target == people.end())
        {
            target = people.begin();
        }

        if(people.empty())
        {
            cout << ">";
            break;
        }
        else
        {
            cout << ", ";
        }
    }
}

