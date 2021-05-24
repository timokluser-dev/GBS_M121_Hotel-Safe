using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace Hotel_Safe_API.Models
{
    public class Hotel
    {
        [Key]
        public Guid HotelId { get; set; }
        [Required]
        public string Name { get; set; }
        public string EncryptedPinMaster { get; set; }

        public virtual ICollection<Appartment> Appartments { get; set; }
    }
}
