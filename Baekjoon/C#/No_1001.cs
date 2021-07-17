using System;

namespace D_210131
{
    class No_1001
    {
        static void Main(string[] args)
        {
            string[] input_AB = Console.ReadLine().Split(' '); //A, B 입력
            int A = int.Parse(input_AB[0]); //A, B에 입력값 저장
            int B = int.Parse(input_AB[1]);

            Console.WriteLine($"{A - B}"); //출력
        }
    }
}
