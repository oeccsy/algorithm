using System;

namespace D_210225
{
    class No_1152
    {
        static void Main(string[] args)
        {
            /*
            int word = 1;
            string input = Console.ReadLine();

            for (int i = 0; i < input.Length; i++)
            {
                if (input[i] == ' ')
                    word += 1;
            }

            if (input[0] == ' ')
                word -= 1;

            if (input[input.Length - 1] == ' ')
                word -= 1;

            Console.WriteLine(word);
            */

            string[] input = Console.ReadLine().Split(' ');
            int word = input.Length;

            if (input[0] == "")
                word--;
            if (input[input.Length - 1] == "")
                word--;

            Console.Write(word);
            
            
        }
    }
}