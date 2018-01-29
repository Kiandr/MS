using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Generic
{
    class Program
    {
        static void Main(string[] args)
        {
            var list = new linkedList<int>();
            for (int i = 10; i < 20; i++)
                list.addNewNode(new linkedList<int>.node(i));
            list.printList();
        }
    }
}
