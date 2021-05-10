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

namespace Hotel_Safe_API.Controllers
{
    [ApiKey]
    [Route("api/[controller]")]
    [ApiController]
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
        public async Task<ActionResult<Safe>> GetSafe(Guid id, [FromQuery] string pin = null, [FromQuery] string badgeNumber = null)
        {
            var safe = await _context.Safes.FindAsync(id);

            bool pinEquals = safe.EncryptedPin == pin;
            bool badgeEquals = safe.BadgeNumber == badgeNumber;
            bool pinAndBadgeEquals = pinEquals && badgeEquals;

            if (pin != null && badgeNumber != null && !pinAndBadgeEquals)
            {
                return NotFound();
            } 
            
            if (pin != null && !pinEquals)
            {
                return NotFound();
            }

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

            safe = SafesController.UpdatePinIfSpecified(safe);

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
            safe = SafesController.UpdatePinIfSpecified(safe);

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

        private bool SafeExists(Guid id)
        {
            return _context.Safes.Any(e => e.SafeId == id);
        }

        private static string EncryptPinUsingSha256(string rawPin)
        {
            using (SHA256 sha256Hash = SHA256.Create())
            {
                byte[] calculatedBytes = sha256Hash.ComputeHash(Encoding.UTF8.GetBytes(rawPin));

                StringBuilder encryptedPin = new();
                for (int i = 0; i < calculatedBytes.Length; i++)
                {
                    encryptedPin.Append(calculatedBytes[i].ToString("x2"));
                }

                return encryptedPin.ToString();
            }
        }

        private static Safe UpdatePinIfSpecified(Safe safe)
        {
            if (safe.Pin != null && safe.Pin != "")
            {
                safe.EncryptedPin = SafesController.EncryptPinUsingSha256(safe.Pin);
                safe.PinChanged = DateTime.Now;
            }

            safe.Pin = null;

            return safe;
        }
    }
}
