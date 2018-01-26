using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PolyMorphosim;

namespace PolyMorphosim
{
    class Program
    {
        static void Main(string[] args)
        {

            var InstanceB = new drivedClassB(10,10,10);

            InstanceB.printVal();
            var InstanceA = new drivedClassA(10, 10, 10);
   
            InstanceA.printVal();



        }
    }
}
