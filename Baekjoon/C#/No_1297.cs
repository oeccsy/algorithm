using System;

namespace D_210208
{
    class No_1297
    {
        static void Main(string[] args)
        {
            double l; //대각선의 길이
            double a, b, k; //너비와 높이의 비율을 ak:bk 로 한다.

            string[] input = Console.ReadLine().Split(' ');

            l = Convert.ToDouble(input[0]);
            a = Convert.ToDouble(input[1]);
            b = Convert.ToDouble(input[2]);

            k = Math.Sqrt(l * l / (a * a + b * b));

            a *= k;
            b *= k;

            Console.WriteLine($"{(int)a} {(int)b}");

        }
    }
}
