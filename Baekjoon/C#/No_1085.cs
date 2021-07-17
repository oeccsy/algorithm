using System;


namespace D_210212
{
    class No_1085
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');

            int x = Convert.ToInt32(input[0]);
            int y = Convert.ToInt32(input[1]);
            int w = Convert.ToInt32(input[2]);
            int h = Convert.ToInt32(input[3]);

            Distance(x, y, w, h);
            
        }

        static void Distance(int x, int y, int w, int h)
        {
            int distance = x;
            int[] list = { y, w - x, h - y };

            for( int i = 0; i<list.Length; i++)
            {
                if (distance >= list[i])
                    distance = list[i];
            }

            Console.WriteLine(distance);
        }
    }
}
