using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace helloWorld.Interfaces
{
    public interface IStringManipulation
    {
        void helloPrint();
    }

    public abstract class AbstractClass{
        public abstract void printFirsrtName();
        public void printLastName() {
            Console.WriteLine("Davoudi");
        }

    }
    

}
