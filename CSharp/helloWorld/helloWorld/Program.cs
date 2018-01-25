using helloKian;
using System;

namespace helloWorld
{
    class Program
    {
        static void Main(string[] args)
        {

            var newClass = new firstClass();
            string input = Console.ReadLine();
            Console.WriteLine(newClass.getValue()+input);
        }
    }
}
