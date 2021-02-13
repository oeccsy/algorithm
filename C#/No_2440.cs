using System;


namespace D_210213
{
    class No_2439
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < n; i++)
            {
                for (int j = n; j > i; j--)
                {
                    Console.Write('*');
                }

                Console.WriteLine();
            }
        }
    }
}