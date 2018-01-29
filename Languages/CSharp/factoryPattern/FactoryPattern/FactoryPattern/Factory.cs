using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FactoryPattern
{
    public interface ISavingAccount {
        /// <summary>
        /// This prints remaining of saving accout 
        /// </summary>
        /// <param name="accountName"> string containing account prefix - number </param>
       string PrintSaving();

    }


    /// <summary>
    /// This is Citi Bank Class for saving accounts 
    /// </summary>
    public class CitiBank : ISavingAccount
    {

        public string  PrintSaving()
        {
            var builder = new StringBuilder(); 
            builder.Append("Remaining of Saving Account of Citi Bank is xx CAD");
            return builder.ToString();
        }
    }

    /// <summary>
    /// This is National Class for saving account
    /// </summary>
    public class NationalBank : ISavingAccount
    {
        public string PrintSaving()
        {

            var builder = new StringBuilder();
            builder.Append("Remaining of Saving Account of National Bank is xx CAD");
            return builder.ToString();
        }
    }

    /// <summary>
    /// This is the contract that itnerface dictates for factory implementation 
    /// </summary>
    public interface IFactory {
        ISavingAccount printSavingAccountBalace(string accountName);
    }

    /// <summary>
    /// This is factory implementation
    /// </summary>
    public class factoryImplementation : IFactory
    {
        public ISavingAccount printSavingAccountBalace(string accountName)
        {

            if (accountName.Contains("CITI"))
                return new CitiBank();
            else if (accountName.Contains("NATIONAL"))
                return new NationalBank();

            else throw new Exception("The account you entered does not math with data base! Try National or Citi Prefix");

        }
    }
}
