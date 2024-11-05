#include <iostream>

using namespace std;

// 기계장치 보았다.
// 기계장치 내부를 볼 수 없다.
// 별빛의 파장을 알려주는 계기판
// 파장의 값을 토대로 별 색상

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int lambda;
    cin >> lambda;

    if(620 <= lambda && lambda <= 780)
    {
        cout << "Red";
    }
    else if (590 <= lambda && lambda < 620)
    {
        cout << "Orange";
    }
    else if(570 <= lambda && lambda < 590)
    {
        cout << "Yellow";
    }
    else if(495 <= lambda && lambda < 570)
    {
        cout << "Green";
    }
    else if(450 <= lambda && lambda < 495)
    {
        cout << "Blue"; 
    }
    else if(425 <= lambda && lambda < 450)
    {
        cout << "Indigo";
    }
    else if(380 <= lambda && lambda < 425)
    {
        cout << "Violet";
    }
}