using System;

namespace D_210209
{
    class No_3004
    {
        static void Main(string[] args)
        {
            string input_N = Console.ReadLine();
            int N = Convert.ToInt32(input_N);

            int x = 0, y = 0; //x축으로, y축으로 자르는 횟수

            int maximum = (x + 1) * (y + 1); //가능한 최대 조각의 수

            if (N % 2 == 0) //N이 짝수인 경우
            {
                x = N / 2;
                y = N / 2;
                maximum = (x + 1) * (y + 1);
                Console.Write("{0}", maximum);
            }
            else //N이 홀수인 경우
            {
                x = (N / 2) + 1;
                y = N / 2;
                maximum = (x + 1) * (y + 1);
                Console.Write("{0}", maximum);
            }
        }
    }
}
