using System;

namespace D_210208
{
    class No_2420
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            
            int N = Convert.ToInt32(input[0]);
            int M = Convert.ToInt32(input[1]);

            uint result;

            if (N >= M)
                result = (uint)(N - M);
            else
                result = (uint)(M - N);

            Console.WriteLine(result);
        }
    }
}