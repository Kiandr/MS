using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace helloKian
{

    public class firstClass {

        /// <summary>
        /// This is a simple getter or simeple setter
        /// </summary>
        public string encapsulation {get; set;}

        public string customEncapsulation {
            get {
                    return customEncapsulation.ToUpper();
                }

            set {
                    customEncapsulation = value;
                }
        }
        private string instace;
        private char[] arrayCh = { 'K', 'i', 'a', 'n' };
        private int[] intArray = { 100, 200, 300 };
        private Dictionary<int, string> dic = new Dictionary<int, string>();
       enum weekdays { Monday, Tuesday};

        /// <summary>
        /// Constructors should have a public decoration
        /// </summary>
        public firstClass() {

            dic.Add(01, "Kian");

            this.instace = "Kian";
        }
        public string getValue()
        {
            var str = new StringBuilder();

            foreach (var i in arrayCh)
                str.Append(i.ToString());

            String a ="31";
            int age = int.Parse(a);
            return instace + str + age + weekdays.Tuesday +
                intArray.Sum() + dic[1];
                ;
        }

    }

}