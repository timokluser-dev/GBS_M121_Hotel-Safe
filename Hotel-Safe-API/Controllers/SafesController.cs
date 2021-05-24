using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Hotel_Safe_API.Models;
using Hotel_Safe_API.Attributes;
using System.Security.Cryptography;
using System.Text;
using Microsoft.AspNet.OData;
using Microsoft.AspNet.OData.Routing;
using Hotel_Safe_API.Responses;
using Hotel_Safe_API.Parameters;

namespace Hotel_Safe_API.Controllers
{
    [ApiKey]
    [Route("api/[controller]")]
    [ApiController]
    [EnableQuery()]
    public class SafesController : ControllerBase
    {
        private readonly HotelSafeContext _context;

        public SafesController(HotelSafeContext context)
        {
            _context = context;
        }

        // GET: api/Safes
        [HttpGet]
        public async Task<ActionResult<IEnumerable<Safe>>> GetSafes()
        {
            return await _context.Safes.ToListAsync();
        }

        // GET: api/Safes/5
        [HttpGet("{id}")]
        public async Task<ActionResult<Safe>> GetSafe(Guid id)
        {
            var safe = await _context.Safes.FindAsync(id);

            if (safe == null)
            {
                return NotFound();
            }

            return safe;
        }

        // PUT: api/Safes/5
        [HttpPut("{id}")]
        public async Task<IActionResult> PutSafe(Guid id, Safe safe)
        {
            if (id != safe.SafeId)
            {
                return BadRequest();
            }

            UpdatePinIfSpecified(safe);

            _context.Entry(safe).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!SafeExists(id))
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }

            return NoContent();
        }

        // POST: api/Safes
        [HttpPost]
        public async Task<ActionResult<Safe>> PostSafe(Safe safe)
        {
            UpdatePinIfSpecified(safe);

            _context.Safes.Add(safe);
            await _context.SaveChangesAsync();

            return CreatedAtAction("GetSafe", new { id = safe.SafeId }, safe);
        }

        // DELETE: api/Safes/5
        [HttpDelete("{id}")]
        public async Task<IActionResult> DeleteSafe(Guid id)
        {
            var safe = await _context.Safes.FindAsync(id);
            if (safe == null)
            {
                return NotFound();
            }

            _context.Safes.Remove(safe);
            await _context.SaveChangesAsync();

            return NoContent();
        }

        // POST: api/Safes/5/ChangePin
        [HttpPost("{id}/ChangePin")]
        public async Task<ActionResult<ChangePinResponse>> ChangePin(Guid id, ChangePinParameter parameter)
        {
            var response = new ChangePinResponse() { Success = true };
            var encryptedPin = parameter.EncryptedPin;

            if (!IsValidSha256(encryptedPin))
            {
                response.Error = "No valid hashed Pin found. Only hashed Pins are allowed";
                response.Success = false;
                return BadRequest(response);
            }

            var safe = await _context.Safes.FindAsync(id);
            safe.EncryptedPin = encryptedPin;

            UpdatePinIfSpecified(safe);

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (Exception)
            {
                response.Success = false;
                return StatusCode(500, response);
            }

            return Ok(response);
        }

        // POST: api/Safes/5/CanOpen
        [HttpPost("{id}/CanOpen")]
        public async Task<ActionResult<CanOpenResponse>> CanOpen(Guid id, CanOpenParameter parameter)
        {
            var response = new CanOpenResponse() { IsBlocked = false };
            var encryptedPin = parameter.EncryptedPin;
            var badgeNumber = parameter.BadgeNumber;

            var safe = await _context.Safes.FindAsync(id);

            var masterPinIsValid = safe.Appartment.Hotel.EncryptedPinMaster == encryptedPin && parameter.BadgeNumber == null;
            var hotelHasMasterPin = safe.Appartment.Hotel.EncryptedPinMaster != null;
            var pinIsValid = safe.EncryptedPin == encryptedPin;
            var pinIsInvoked = safe.EncryptedPin == null;
            var badgeIsValid = safe.BadgeNumber == badgeNumber || (safe.BadgeNumber == null && badgeNumber == null);

            var canOpen = (pinIsValid && badgeIsValid && !pinIsInvoked) || (masterPinIsValid && hotelHasMasterPin);
            var badgeRequired = safe.BadgeNumber != null && badgeNumber == null && !masterPinIsValid;

            response.CanOpen = canOpen;
            response.BadgeRequired = badgeRequired;

            if ((!canOpen && !badgeRequired && parameter.BadgeNumber != null) || (!canOpen && !badgeRequired))
            {
                safe.FailedAttempts++;
            }
            else if (canOpen && !badgeRequired)
            {
                safe.FailedAttempts = 0;
            }

            BlockSafeIfLimitReached(safe);
            response.IsBlocked = safe.IsBlocked;

            await _context.SaveChangesAsync();

            return Ok(response);
        }

        private bool SafeExists(Guid id)
        {
            return _context.Safes.Any(e => e.SafeId == id);
        }

        private static bool IsValidSha256(string sha256)
        {
            return (sha256.Length == 64);
        }

        private static void UpdatePinIfSpecified(Safe safe)
        {
            if (safe.EncryptedPin == "" || safe.EncryptedPin == null || !IsValidSha256(safe.EncryptedPin))
            {
                safe.EncryptedPin = null;
            }

            safe.PinChanged = DateTime.Now;
        }

        private static void BlockSafeIfLimitReached(Safe safe)
        {
            // at nth failed request the safe will be blocked
            var blockLimit = 3;

            if (safe.FailedAttempts >= blockLimit)
            {
                safe.EncryptedPin = null;
                safe.BadgeNumber = null;

                safe.FailedAttempts = 0;
            }
        }
    }
}
