using Microsoft.EntityFrameworkCore;

namespace Hotel_Safe_API.Models
{

    public class HotelSafeContext : DbContext
    {
        public DbSet<Hotel> Hotels { get; set; }
        public DbSet<Appartment> Appartments { get; set; }
        public DbSet<Safe> Safes { get; set; }

        public HotelSafeContext()
        {

        }

        public HotelSafeContext(DbContextOptions<HotelSafeContext> options) : base(options)
        {

        }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {

        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {

        }
    }
}
