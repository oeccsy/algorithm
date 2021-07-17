  using System;

namespace D_210225
{
    class No_1193
    {
         static void Main(string[] args)
        {
            string input = Console.ReadLine(); // X값 입력
            int X = Convert.ToInt32(input);

            int a = 1, b = 1; // b/a 분자 분모 선언
            int i = 1; // a+b 의 값을 나타내는 변수

            for (; X > 0; i++) // a+b의 값 구하기
                X = X - i;

            if (i % 2 == 1) // i, X값에 따라 a, b의 값 결정
            {
                a = a - X;
                b = i - a;
            }
            else
            {
                b = b - X;
                a = i - b;

            }
                Console.WriteLine("{0}/{1}", b, a);
        }
    }
}
