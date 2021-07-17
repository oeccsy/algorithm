using System;

namespace D_210215
{
    class No_2442
    {
        static void Main(string[] args)
        {
            int input = Convert.ToInt32(Console.ReadLine());

            for(int i=0; i<input; i++)
            {
                for(int j = 0; j<input-i-1; j++)
                {
                    Console.Write(' ');
                }

                for(int j = 0; j<2*i+1; j++)
                {
                    Console.Write('*');
                }

                Console.WriteLine();
            }
        }
    }
}