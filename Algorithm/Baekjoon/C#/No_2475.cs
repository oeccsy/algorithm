using System;

namespace D_210131
{
    class No_2475
    {
        static void Main(string[] args)
        {
            string[] input_num = Console.ReadLine().Split(' ');
            int[] num = new int[5];

            int sum = 0;

            for (int i = 0; i<5; i++)
            {
                num[i] = Convert.ToInt32(input_num[i]);
                sum += num[i] * num[i];
            }

            Console.WriteLine(sum%10);
           
            
        }
    
    }
}
