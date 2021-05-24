using Microsoft.EntityFrameworkCore.Migrations;

namespace Hotel_Safe_API.Migrations
{
    public partial class AddMasterPin : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<int>(
                name: "FailedAttempts",
                table: "Safes",
                type: "int",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<string>(
                name: "EncryptedPinMaster",
                table: "Hotels",
                type: "nvarchar(max)",
                nullable: true);
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "FailedAttempts",
                table: "Safes");

            migrationBuilder.DropColumn(
                name: "EncryptedPinMaster",
                table: "Hotels");
        }
    }
}
