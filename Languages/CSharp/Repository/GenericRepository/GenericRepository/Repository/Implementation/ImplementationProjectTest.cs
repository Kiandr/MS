using System;
using System.Collections.Generic;
using GenericRepository.Models;
using GenericRepository.Repository.Interfaces;
using GenericRepository.DbContextTest;
using System.Linq;

namespace GenericRepository.Repository.Implementation
{
    public class ImplementationProjectTest: IInterfacesProjectTest<testModel>
    {
        private DbContextTestEntities _context { get; set; }

        // Parameterless constructor
       public ImplementationProjectTest() {
            _context = new DbContextTestEntities();
        }

        public void Creat(testModel incomingModel)
        {

            Random rnd = new Random();
            _context.testModels.Add(new testModel() { personId = rnd.Next(1,1000), firstName=incomingModel.firstName, lastName = incomingModel.lastName});
            _context.SaveChanges();
           // throw new NotImplementedException();
        }

        public void Delete(testModel incomingModel)
        {
            throw new NotImplementedException();
        }

        public IList<testModel> GetAll()
        {

            var data = (from m in _context.testModels
                        where m.personId >0
                       select m).ToList();


            var list = new List<testModel>();
            foreach (var item in data)
                list.Add(item);

            return list;
        }

        public void Update(testModel incomingModel)
        {
            throw new NotImplementedException();
        }
    }
}