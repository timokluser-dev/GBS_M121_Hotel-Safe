using Microsoft.EntityFrameworkCore.Migrations;

namespace Hotel_Safe_API.Migrations
{
    public partial class PinColumnrenamed : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.RenameColumn(
                name: "PinEncrypted",
                table: "Safes",
                newName: "EncryptedPin");
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.RenameColumn(
                name: "EncryptedPin",
                table: "Safes",
                newName: "PinEncrypted");
        }
    }
}
