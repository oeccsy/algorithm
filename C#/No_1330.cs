using System;

namespace D_210208

{
    class No_1330
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split();
            int A = Convert.ToInt32(input[0]);
            int B = Convert.ToInt32(input[1]);

            if (A > B)
                Console.Write('>');
            else if (A < B)
                Console.Write('<');
            else
                Console.Write("==");

        }
   
    }
}