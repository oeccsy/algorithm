#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    
    cin >> t;

    for(int i=0; i<t; i++)
    {
        list<char> password = {};
        string input;
        cin >> input;

        auto cursor = password.begin();
        
        for(auto c : input)
        {
            auto erase_target = cursor;
            
            switch (c)
            {
                case '<':
                    if(cursor == password.begin()) break;
                    cursor--;
                    break;
                case '>':
                    if(cursor == password.end()) break;
                    cursor++;
                    break;
                case '-':
                    if(cursor == password.begin()) break;
                    erase_target--;
                    password.erase(erase_target);
                    break;
                default :
                    password.insert(cursor, c);
                    break;
            }
        }
        
        for(auto c : password)
        {
            cout << c;
        }

        cout << '\n';
    }
}

