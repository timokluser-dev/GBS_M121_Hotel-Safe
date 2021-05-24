using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Hotel_Safe_API.Responses
{
    public class ChangePinResponse : ErrorResponse
    {
        public bool Success { get; set; }
    }
}
