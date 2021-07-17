using System;

namespace D_210131
{
    class No_1000
    {
        static void Main(string[] args)
        {
            string input_AB = Console.ReadLine(); //AB 입력
            string[] string_AB = input_AB.Split(' '); //A와 B구분

            int[] int_AB = new int[2];

            int_AB[0] = int.Parse(string_AB[0]);
            int_AB[1] = int.Parse(string_AB[1]); //A와 B를 int로 변환

            Console.WriteLine($"{int_AB[0] + int_AB[1]}"); //A+B의 값 출력 
        }
    }
}
