using System;

namespace D_210227
{
    class No_1032
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());

            string[] input = new string[n];
            char[] result;

            for(int i = 0; i<n; i++)
            {
                input[i] = Console.ReadLine();
            }

            result = new char[input[0].Length];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < input[i].Length; j++)
                {
                    if (i == 0)
                        result[j] = input[i][j];
                    else if (result[j] != input[i][j])
                        input[0][j] = '?';
                }
            }

            for(int i =0; i<result.Length; i++)
            {
                Console.Write(result[i]);
            }


        }
    }
}
