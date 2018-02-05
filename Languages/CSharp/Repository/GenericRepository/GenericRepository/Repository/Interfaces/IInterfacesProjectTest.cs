using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace GenericRepository.Repository.Interfaces
{
    public interface IInterfacesProjectTest<T> where T : new()
    {

        void Creat(T incomingModel);
        void Update(T incomingModel);
        void Delete(T incomingModel);
        IList<T> GetAll();
    }
}