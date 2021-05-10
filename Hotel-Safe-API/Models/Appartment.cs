using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace Hotel_Safe_API.Models
{
    public class Appartment
    {
        [Key]
        public Guid AppartmentId { get; set; }
        [Required]
        public string Name { get; set; }

        public Guid HotelId { get; set; }
        public virtual Hotel Hotel { get; set; }

        public virtual ICollection<Safe> Safes { get; set; }
    }
}
