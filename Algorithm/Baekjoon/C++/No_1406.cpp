#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    list<char> editor;
    list<char>::iterator cursor; //커서가 몇번째 index의 왼쪽에 있는지 나타냄
    int m;
    
    string input;
    cin >> input;

    for(auto c : input)
    {
        editor.push_back(c);
    }

    cursor = editor.end();

    cin >> m;

    for(int i=0; i<m; i++)
    {
        char oper;
        char text;
        cin >> oper;

        if(oper == 'L')
        {
            if(cursor == editor.begin()) continue;

            cursor--; //.operator--();
        }
        else if(oper == 'D')
        {
            if(cursor == editor.end()) continue;

            cursor++; //.operator++();
        }
        else if(oper == 'B')
        {
            if(cursor == editor.begin()) continue;

            auto erase_target = cursor;
            erase_target--;
            editor.erase(erase_target);
        }
        else if(oper == 'P')
        {
            cin >> text;
            
            editor.insert(cursor, text);
        }
    }

    for(auto it=editor.begin(); it!=editor.end(); it++)
    {
        cout << *it;
    }
    
}