using System;

namespace D_210131
{
    class No_3046
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');

            int R1 = Convert.ToInt32(input[0]);
            int S = Convert.ToInt32(input[1]);

            Console.Write(2 * S - R1);
        }
    }
}