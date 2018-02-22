using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace delegateCSharp
{
    public class delegateClass
    {
        
        // public member 
        public void DoWork() {
            Console.WriteLine("Do work function was called");
        }

        public  delegate void DoWorkDelegate();
    }
}
    /*
    The goal of this class is to build a delegate and test it. 
     
     */
