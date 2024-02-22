using System;

namespace D_210301
{
    class No_1145
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split();
            int[] num = new int[5];
            int result = 0;
            int count = 0;

            for(int i = 0; i<input.Length;i++)
            {
                num[i] = Convert.ToInt32(input[i]);
            }

            while (count<3)
            {
                result += 1;
                count = 0;

                for(int i = 0; i<5; i++)
                {
                    if (result % num[i] == 0)
                        count++;
                }
            }

            Console.WriteLine(result);
            
        }
    }
}
