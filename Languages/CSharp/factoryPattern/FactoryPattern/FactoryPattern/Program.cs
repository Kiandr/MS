using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FactoryPattern
{
    class Program
    {
        static void Main(string[] args)
        {
            factoryImplementation factory = new factoryImplementation();
            var a = factory.printSavingAccountBalace("CITI-xx:xx");
            var b = factory.printSavingAccountBalace("NATIONAL-xx:xx");
            Console.WriteLine(a.PrintSaving());
            Console.WriteLine(b.PrintSaving());

        }
    }
}
