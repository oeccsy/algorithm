using System;

namespace D_210131
{
    class No_2914
    {
        static void Main(string[] args)
        {
            string[] input_AI = Console.ReadLine().Split();
            int A = Convert.ToInt32(input_AI[0]);
            int I = Convert.ToInt32(input_AI[1]);

            int m = A*(I - 1) + 1;

            Console.Write(m);
            
        }
    }
}