using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using FactoryPattern;

namespace testFactory
{
    [TestClass]
    public class FactoryUnitTest
    {
        [TestMethod]
        public void TestMethod1()
        {
            factoryImplementation factory = new factoryImplementation();
            var a = factory.printSavingAccountBalace("CITI-xx:xx");
            var b = factory.printSavingAccountBalace("NATIONAL-xx:xx");
            Assert.AreNotEqual(a.returnSavingInCad(),b.returnSavingInCad());
        }

        [TestMethod]
        public void TestMethod2()
        {
            factoryImplementation factory = new factoryImplementation();
            var a = factory.printSavingAccountBalace("CITI-xx:xx");
            var b = factory.printSavingAccountBalace("CITI-xx:xx");
            Assert.AreEqual(a.returnSavingInCad(), b.returnSavingInCad());
        }
    }
}
