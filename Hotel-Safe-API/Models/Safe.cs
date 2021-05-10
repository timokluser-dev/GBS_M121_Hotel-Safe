using System;
using System.ComponentModel.DataAnnotations;

namespace Hotel_Safe_API.Models
{
    public class Safe
    {
        [Key]
        public Guid SafeId { get; set; }
        public DateTime PinChanged { get; set; }
        public string Pin { get; set; }
        public string EncryptedPin { get; set; }
        public string BadgeNumber { get; set; }

        public Guid AppartmentId { get; set; }
        public virtual Appartment Appartment { get; set; }
    }
}
