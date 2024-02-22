using System;

namespace D_210201
{
    class No_5522
    {
        static void Main(string[] args)
        {
            int sum = 0;

            for(int i = 0; i<5; i++)
            {
                sum += Convert.ToInt32(Console.ReadLine());
            }

            Console.WriteLine(sum);
        }
    }
}