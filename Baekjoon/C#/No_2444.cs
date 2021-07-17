using System;

namespace D_210215
{
    class No_2444
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            for (int i = 1; i <=2*n-1; i++)
            {
                if(i<=n)
                {
                    for (int j = 1; j <= n - i; j++)
                    {
                        Console.Write(' ');
                    }

                    for (int j = 1; j <= 2 * i - 1; j++)
                    {
                        Console.Write('*');
                    }
                }
                else
                {
                    for (int j = 1; j <=i-n; j++)
                    {
                        Console.Write(' ');
                    }

                    for (int j = 1; j <= 4*n-1-2*i; j++)
                    {
                        Console.Write('*');
                    }
                }

               

                Console.WriteLine();
            }
        }
    }
}