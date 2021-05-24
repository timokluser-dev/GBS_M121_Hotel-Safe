using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Hotel_Safe_API.Responses
{
    public class CanOpenResponse
    {
        public bool CanOpen { get; set; }
        public bool BadgeRequired { get; set; }
        public bool IsBlocked { get; set; }
    }
}
