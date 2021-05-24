using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Hotel_Safe_API.Parameters
{
    public class CanOpenParameter
    {
        public string EncryptedPin { get; set; }
        public string? BadgeNumber { get; set; }
    }
}
