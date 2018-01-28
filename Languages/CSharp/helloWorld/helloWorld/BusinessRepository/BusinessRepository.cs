using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using  helloWorld.Interfaces;

namespace helloWorld.BusinessRepository
{
    public class StringManipulation : IStringManipulation
    {
        public virtual void helloPrint()
        {
            throw new NotImplementedException();
        }
    }

    public class StringManupulationWrite : AbstractClass
    {
        public override void printFirsrtName()
        {
            throw new NotImplementedException();
        }
    }
}
