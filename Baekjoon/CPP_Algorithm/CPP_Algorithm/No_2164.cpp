#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<int> cards;
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        cards.push(i);
    }

    while(cards.size() > 1)
    {
        cards.pop();

        cards.push(cards.front());
        cards.pop();
    }

    cout << cards.front();
}
