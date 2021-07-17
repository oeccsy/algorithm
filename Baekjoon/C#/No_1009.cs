using System;

namespace D_210211
{
    class No_1009
    {
        static void Main(string[] args)
        {
            int T = Convert.ToInt32(Console.ReadLine());
            int a = 0, b = 0;
            int result = 0;

            for(int i = 0; i<T; i++)
            {
                string[] input = Console.ReadLine().Split();
                a = Convert.ToInt32(input[0]);
                b = Convert.ToInt32(input[1]);
                b = b % 4 + 4;

                result = a;

                for(int j = 1; j<b;j++)
                {
                    result *= a;
                    result = result%10;
                    

                }

                if (result == 0)
                    result = 10;
              

                Console.WriteLine(result);


            }

        }
    }
}
