using System;

namespace D_210216
{
    class No_2292
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());

            for (int i = 1; ; i++)
            {
                if(n<=1)
                {
                    Console.Write(i);
                    break;
                }

                n -= 6 * i;
            }
            
        }
    }
}
