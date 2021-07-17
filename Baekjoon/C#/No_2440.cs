using System;


namespace D_210213
{
    class No_2440
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    Console.Write(' ');
                }

                for (int j = n; j > i; j--)
                {
                    Console.Write('*');
                }

                Console.WriteLine();
            }
        }
    }
}