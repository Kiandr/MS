using System;

namespace Generic
{
    public class linkedList<T>
    {

        public class node {
            public T data { get; set; }
            public node next { get; set; }
            public node(T incomingData) {
                data = incomingData;
                next = null;
            }
        }
        public node header;
        public void addNewNode(node newNode)
        {

            if (header == null)
            {
                header = new node(newNode.data);
            }
            else
            {
                node prtH = header;
                while (prtH.next != null)
                    prtH = prtH.next;
                prtH.next = new node(newNode.data);
            }
        }
        public void printList() {
            node prtH = header;
            if (prtH == null)
                Console.WriteLine("Header is empty!");
            else {
                while (prtH != null)
                {
                    Console.WriteLine(prtH.data);
                    prtH = prtH.next;
                }
            }
        }
    }
}