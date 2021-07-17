using System;

namespace D_210215
{
    class No_2443
    {
        static void Main(string[] args)
        {
            int input = Convert.ToInt32(Console.ReadLine());

            for(int i=0; i<input; i++)
            {
                for(int j = 0; j<i; j++)
                {
                    Console.Write(' ');
                }

                for(int j = 0; j<2*(input-i)-1 ;j++)
                {
                    Console.Write('*');
                }

                Console.WriteLine();
            }
        }
    }
}