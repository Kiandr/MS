using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PolyMorphosim
{
   public abstract class baseClass
    {
        private int  Oz { set; get; }
        public  baseClass(int weight, int deapth, int size) {
            Oz = (weight * deapth * size);

        }

        public int getOz() { return Oz; }

        public virtual void printVal() {

            Console.WriteLine("Base Class Oz is"+Oz.ToString());
        }


    }
}
