using System;

namespace D_210202
{
    class No_1008
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split();

            double A = (double)Convert.ToInt32(input[0]);
            double B = (double)Convert.ToInt32(input[1]);

            Console.WriteLine(A / B);
        }
    }
}
