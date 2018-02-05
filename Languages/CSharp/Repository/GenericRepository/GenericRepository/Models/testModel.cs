using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace GenericRepository.Models
{
    public class testModel
    {
        [Key]
        [Column("personId")]
        public int personId { get; set; }
        [Column("firstName")]
        public string firstName { get; set; }
        [Column("lastName")]
        public string lastName { get; set; }
    }
}