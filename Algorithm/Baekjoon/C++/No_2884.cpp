#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h;
    int m;

    int h_alarm = 0;
    int m_alarm = 0;
    
    cin >> h >> m;

    h_alarm = h;
    m_alarm = m - 45;

    if(m_alarm < 0)
    {
        h_alarm -= 1;
        m_alarm += 60;
    }

    if(h_alarm < 0)
    {
        h_alarm += 24;
    }

    cout << h_alarm << " " << m_alarm;
}