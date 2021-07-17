using System;

namespace D_210226
{
    class No_1264
    {
        static void Main(string[] args)
        {
            while(true)
            {
                string input = Console.ReadLine();
                int result = 0;
                if (input == "#")
                    break;

                for(int i = 0; i<input.Length; i++)
                {
                    if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U')
                        result++;
                }

                Console.WriteLine(result);
            }
        }
    }
}
