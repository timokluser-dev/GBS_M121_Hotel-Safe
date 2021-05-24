using System;
using System.ComponentModel.DataAnnotations;

namespace Hotel_Safe_API.Models
{
    public class Safe
    {
        [Key]
        public Guid SafeId { get; set; }
        public DateTime PinChanged { get; set; }
        public string EncryptedPin { get; set; }
        public string BadgeNumber { get; set; }
        public int FailedAttempts { get; set; } = 0;
        public bool IsBlocked { get { return EncryptedPin == null && BadgeNumber == null; } }

        public Guid AppartmentId { get; set; }
        public virtual Appartment Appartment { get; set; }
    }
}
