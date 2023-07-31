#include <iostream>
#include <array>

using namespace std;

array<int, 10> number_count = {0, };
int set_count = 0;

void AddNumberSet()
{
    for(int i=0; i<10; i++)
    {
        number_count[i]++;
    }
    
    set_count++;
}

void UseNumber(int number)
{
    if(number_count[number] > 0)
    {
        number_count[number]--;
    }
    else if(number == 6 && number_count[9] > 0)
    {
        number_count[9]--;
    }
    else if(number == 9 && number_count[6] > 0)
    {
        number_count[6]--;
    }
    else
    {
        AddNumberSet();
        UseNumber(number);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int input;
    cin >> input;

    while(true)
    {
        UseNumber(input % 10);
        input /= 10;

        if(input <= 0) break;
    }

    cout << set_count;
}