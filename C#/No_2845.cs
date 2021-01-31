using System;

namespace D_210131
{
    class No_2845
    {
        static void Main(string[] args)
        {
            string[] input_LP = Console.ReadLine().Split(' ');
            string[] input_num = Console.ReadLine().Split(' ');

            int LP = Convert.ToInt32(input_LP[0])*Convert.ToInt32(input_LP[1]);
            
            int[] num = new int[5];

            for(int i=0; i<num.Length; i++)
            {
                num[i] = Convert.ToInt32(input_num[i]);
                num[i] = num[i] - LP;

                Console.Write($"{num[i]} ");
            }

        }
    }
}