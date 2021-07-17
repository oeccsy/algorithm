using System;

namespace D_210131
{
    class No_1550
    {
        static void Main(string[] args)
        {
            string input_num = Console.ReadLine(); //숫자 입력
            int num = Convert.ToInt32(input_num, 16); //입력받은 숫자를 16진법으로 받아들인다.

            Console.WriteLine(num); //10진법으로 출력
        }

    }
}
