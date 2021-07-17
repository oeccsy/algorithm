using System;

namespace D_210201
{
    class No_8370
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n1 = Convert.ToInt32(input[0]);
            int k1 = Convert.ToInt32(input[1]);
            int n2 = Convert.ToInt32(input[2]);
            int k2 = Convert.ToInt32(input[3]);

            Console.WriteLine(n1 * k1 + n2 * k2);
        }
    }
}