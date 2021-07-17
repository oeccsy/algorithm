using System;

namespace D_210131
{
    class No_3003
    {
        static void Main(string[] args)
        {
            string input_num = Console.ReadLine();
            string[] str_num = input_num.Split(' ');

            int[] num = new int[6];
            int[] whitePiece = { 1, 1, 2, 2, 2, 8 };

            for(int i=0; i<num.Length; i++)
            {
                num[i] = Convert.ToInt32(str_num[i]);
                whitePiece[i] -= num[i];

                Console.Write("{0} ", whitePiece[i]);
            }
        }
    }
}