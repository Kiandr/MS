using Microsoft.VisualStudio.TestTools.UnitTesting;
using singletone;

namespace testSingleTon
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void isSimpleThreadSafe()
        {
            var a = new singleTonSimpleSafe();
            var b = new singleTonSimpleSafe();
            Assert.AreEqual(a.Instance, b.Instance);
        }

        [TestMethod]
        public void isSingleTonThreadSafe()
        {
            Assert.AreEqual(singleTonThreadSafe.Instance, 
                singleTonThreadSafe.Instance);
        }

        [TestMethod]
        public void isSingleTonNoThreadSafe() {
            Assert.AreEqual( singleTonNoThreadSafe.Instance,
                singleTonNoThreadSafe.Instance);
        }

        [TestMethod]
        public void isNotSingleTon() {

            var a = new notSingleTon();
            var b = new notSingleTon();

            Assert.AreEqual(a.instance, b.instance);
        }
    }
}
