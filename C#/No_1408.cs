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

            /*
            for (int i = 0; i < 3; i++)
                hhmmss[i] = Convert.ToInt32(input2[i]);
                */

            for (int i = 0; i < 3; i++)
            {
                hhmmss[i] = Convert.ToInt32(input2[i]) - Convert.ToInt32(input1[i]);

                if (i == 0 && hhmmss[i] < 0)
                {
                    hhmmss[i] += 24;
                }
                    

                if (i == 1 && hhmmss[i] < 0)
                {
                    hhmmss[i] += 60;
                    hhmmss[i - 1] -= 1;

                        if (hhmmss[i - 1] < 0)
                            hhmmss[i - 1] += 24;      
                }

                if (i == 2 && hhmmss[i] < 0)
                {
                    hhmmss[i] += 60;
                    hhmmss[i - 1] -= 1;

                    if(hhmmss[i-1] <0)
                    {
                        hhmmss[i - 1] += 60;
                        hhmmss[i - 2] -= 1;

                        if (hhmmss[i - 2] < 0)
                            hhmmss[i - 2] += 24;
                    }
                }
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
