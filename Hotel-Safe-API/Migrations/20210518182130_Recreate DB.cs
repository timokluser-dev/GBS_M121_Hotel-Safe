using Microsoft.EntityFrameworkCore.Migrations;

namespace Hotel_Safe_API.Migrations
{
    public partial class RecreateDB : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "Pin",
                table: "Safes");
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<string>(
                name: "Pin",
                table: "Safes",
                type: "nvarchar(max)",
                nullable: true);
        }
    }
}
