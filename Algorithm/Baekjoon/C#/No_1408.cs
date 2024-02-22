using System;

namespace D_210307
{
    class No_1408
    {
        static void Main(string[] args)
        {
            string[] input1 = Console.ReadLine().Split(':');
            string[] input2 = Console.ReadLine().Split(':');

            int[] hhmmss = new int[3];
            int zero = 0;

            for (int i = 0; i < 3; i++)
            {
                hhmmss[i] = Convert.ToInt32(input2[i]) - Convert.ToInt32(input1[i]);

                if (hhmmss[2] < 0)
                {
                    hhmmss[2] += 60;
                    hhmmss[1] -= 1;
                }

                if (hhmmss[1] < 0)
                {
                    hhmmss[1] += 60;
                    hhmmss[0] -= 1;
                }

                if (hhmmss[0] < 0)
                    hhmmss[0] += 24;
            }

            for(int i = 0; i<3; i++)
            {
                if (hhmmss[i] < 10)
                    Console.Write(zero);
                Console.Write(hhmmss[i]);

                if (i < 2)
                    Console.Write(":");
            }
        }
    }
}
