using System;

namespace D_210228
{
    class No_1110
    {
        static int cycle = 0;

        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());

            Console.Write(Calculate(n, n));
        }

        static int Calculate(int n, int goal)
        {
            int result = 10 * (n % 10); //10의 자리수 결정

            if (n < 10)
                result += n;
            else
                result += (n / 10 + n % 10) % 10; //1의 자리 수 결정

            if (result != goal)
                Calculate(result, goal);

            return ++cycle;
        }
    }
}
