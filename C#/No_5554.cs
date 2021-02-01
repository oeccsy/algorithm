using System;

namespace D_210201
{
    class No_5554
    {
        static void Main(string[] args)
        {
            int minute = 0;
            int second = 0;

            for (int i = 0; i<4; i++)
            {
                second += Convert.ToInt32(Console.ReadLine());
                
                while(second >=60)
                {
                    minute += 1;
                    second -= 60;
                }
            }

            Console.WriteLine(minute);
            Console.WriteLine(second);

        }
    }
}