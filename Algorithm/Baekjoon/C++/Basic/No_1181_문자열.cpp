#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(string& a, string& b)
{
    if(a.size() != b.size())
    {
        return a.size() < b.size();
    }
    else
    {
        return a < b;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> words;

    for(int i=0; i<n; i++)
    {
        string word;
        cin >> word;

        words.push_back(word);
    }

    sort(words.begin(), words.end(), cmp);
    words.erase(unique(words.begin(), words.end()), words.end());

    for(auto word : words)
    {
        cout << word << '\n';
    }
}