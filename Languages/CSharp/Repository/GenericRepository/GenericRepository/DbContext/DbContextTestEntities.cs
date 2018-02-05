
using GenericRepository.Models;
using System.Data.Entity;

namespace GenericRepository.DbContextTest
{
    // Its a partial class
    public partial class DbContextTestEntities: DbContext
    {
        // Contructor shall be also public
        public DbContextTestEntities() : base("name=DefaultConnection") {
    
        }
        public virtual DbSet<testModel> testModels { get; set; }
    }
}