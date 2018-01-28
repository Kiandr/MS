using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace singletone
{
    /// <summary>
    /// This is thread safe short.
    /// </summary>
    public sealed class singleTonSimpleSafe {

        /// <summary>
        /// Simple, thread safe instance. Only one will be intialied. 
        /// The problem is if the program looses the reffrence while being in the memory 
        /// CLR wont clean it. 
        /// </summary>
        private readonly static singleTonSimpleSafe instance = new singleTonSimpleSafe();
        /// <summary>
        /// Getter, mind the Captical I
        /// </summary>
        public singleTonSimpleSafe Instance {
            get {
                return instance;
            }
        }
        /// <summary>
        /// Simple Constructor
        /// </summary>
        public singleTonSimpleSafe() { }

    }
    /// <summary>
    /// This is thread safe, detailed
    /// </summary>
    public sealed class singleTonThreadSafe {
        /// <summary>
        /// This is the private instance. 
        /// </summary>
        private static singleTonThreadSafe instance;
        /// <summary>
        /// This is also private locker 
        /// </summary>
        private readonly static object locker = new object();

        /// <summary>
        /// This is a customized getter, mind the capital I
        /// </summary>
        public static singleTonThreadSafe Instance {
            get {
                // wrap initialization around a locker
                lock (locker) {
                    if (instance == null)
                        instance = new singleTonThreadSafe();
                    return instance;

                }
            }

        }

        /// <summary>
        /// This is constructor
        /// </summary>
        public singleTonThreadSafe() { }

    }
    /// <summary>
    /// This is not a thread safe implementation. 
    /// </summary>
    public sealed class singleTonNoThreadSafe
    {
        /// <summary>
        /// This is the main instance of the object
        /// </summary>
        private static singleTonNoThreadSafe instance;
        /// <summary>
        /// This is getter, mind the captical I
        /// </summary>
        public static singleTonNoThreadSafe Instance {
            get {
                // This is not thread safe, thus we use lock
                if (instance == null)
                    instance = new singleTonNoThreadSafe();
                return instance;
            }
        }
        /// <summary>
        /// This is constructor
        /// </summary>
        public singleTonNoThreadSafe() { }

    }

    public sealed class notSingleTon
    {
        /// <summary>
        /// This is the main instance of the object
        /// </summary>
        public notSingleTon instance { get; set; }

        /// <summary>
        /// This is constructor
        /// </summary>
        public notSingleTon() {

        }

    }
}
