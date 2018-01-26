using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PolyMorphosim
{
    public class drivedClassA : baseClass
    {
        public drivedClassA(int weight, int deapth, int size) : base(weight, deapth, size)
        {
        }

        public override void printVal()
        {
            //base.printVal();
            Console.WriteLine("Derived Class A is" + getOz());
        }
    }


    public class drivedClassB : baseClass
    {
        public drivedClassB(int weight, int deapth, int size) : base(weight, deapth, size)
        {
        }
        public override void printVal()
        {
            //base.printVal();
            Console.WriteLine("Derived Class B is" + getOz());
        }
    }
}
