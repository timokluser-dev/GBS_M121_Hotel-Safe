using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Hotel_Safe_API.Models;
using Hotel_Safe_API.Attributes;
using Microsoft.AspNet.OData;

namespace Hotel_Safe_API.Controllers
{
    [ApiKey]
    [Route("api/[controller]")]
    [ApiController]
    [EnableQuery()]
    public class AppartmentsController : ControllerBase
    {
        private readonly HotelSafeContext _context;

        public AppartmentsController(HotelSafeContext context)
        {
            _context = context;
        }

        // GET: api/Appartments
        [HttpGet]
        public async Task<ActionResult<IEnumerable<Appartment>>> GetAppartments()
        {
            return await _context.Appartments.ToListAsync();
        }

        // GET: api/Appartments/5
        [HttpGet("{id}")]
        public async Task<ActionResult<Appartment>> GetAppartment(Guid id)
        {
            var appartment = await _context.Appartments.FindAsync(id);

            if (appartment == null)
            {
                return NotFound();
            }

            return appartment;
        }

        // PUT: api/Appartments/5
        [HttpPut("{id}")]
        public async Task<IActionResult> PutAppartment(Guid id, Appartment appartment)
        {
            if (id != appartment.AppartmentId)
            {
                return BadRequest();
            }

            _context.Entry(appartment).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!AppartmentExists(id))
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

        // POST: api/Appartments
        [HttpPost]
        public async Task<ActionResult<Appartment>> PostAppartment(Appartment appartment)
        {
            _context.Appartments.Add(appartment);
            await _context.SaveChangesAsync();

            return CreatedAtAction("GetAppartment", new { id = appartment.AppartmentId }, appartment);
        }

        // DELETE: api/Appartments/5
        [HttpDelete("{id}")]
        public async Task<IActionResult> DeleteAppartment(Guid id)
        {
            var appartment = await _context.Appartments.FindAsync(id);
            if (appartment == null)
            {
                return NotFound();
            }

            _context.Appartments.Remove(appartment);
            await _context.SaveChangesAsync();

            return NoContent();
        }

        private bool AppartmentExists(Guid id)
        {
            return _context.Appartments.Any(e => e.AppartmentId == id);
        }
    }
}
