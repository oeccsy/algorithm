using System;

namespace D_210201
{
    class No_6749
    {
        static void Main(string[] args)
        {
            int youngestChild = Convert.ToInt32(Console.ReadLine());
            int middleChild = Convert.ToInt32(Console.ReadLine());

            int oldestChild = 2 * middleChild - youngestChild;

            Console.WriteLine(oldestChild);

        }
    }
}