using Microsoft.EntityFrameworkCore.Migrations;

namespace Hotel_Safe_API.Migrations
{
    public partial class AddPinColumn : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropPrimaryKey(
                name: "PK_apiKeys",
                table: "apiKeys");

            migrationBuilder.RenameTable(
                name: "apiKeys",
                newName: "ApiKeys");

            migrationBuilder.AddColumn<string>(
                name: "Pin",
                table: "Safes",
                type: "nvarchar(max)",
                nullable: true);

            migrationBuilder.AddPrimaryKey(
                name: "PK_ApiKeys",
                table: "ApiKeys",
                column: "ApiKeyId");
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropPrimaryKey(
                name: "PK_ApiKeys",
                table: "ApiKeys");

            migrationBuilder.DropColumn(
                name: "Pin",
                table: "Safes");

            migrationBuilder.RenameTable(
                name: "ApiKeys",
                newName: "apiKeys");

            migrationBuilder.AddPrimaryKey(
                name: "PK_apiKeys",
                table: "apiKeys",
                column: "ApiKeyId");
        }
    }
}
