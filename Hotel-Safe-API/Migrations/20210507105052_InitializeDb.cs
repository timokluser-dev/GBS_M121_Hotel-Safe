using System;
using Microsoft.EntityFrameworkCore.Migrations;

namespace Hotel_Safe_API.Migrations
{
    public partial class InitializeDb : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "Hotels",
                columns: table => new
                {
                    HotelId = table.Column<Guid>(type: "uniqueidentifier", nullable: false),
                    Name = table.Column<string>(type: "nvarchar(max)", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Hotels", x => x.HotelId);
                });

            migrationBuilder.CreateTable(
                name: "Appartments",
                columns: table => new
                {
                    AppartmentId = table.Column<Guid>(type: "uniqueidentifier", nullable: false),
                    Name = table.Column<string>(type: "nvarchar(max)", nullable: true),
                    HotelId = table.Column<Guid>(type: "uniqueidentifier", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Appartments", x => x.AppartmentId);
                    table.ForeignKey(
                        name: "FK_Appartments_Hotels_HotelId",
                        column: x => x.HotelId,
                        principalTable: "Hotels",
                        principalColumn: "HotelId",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "Safes",
                columns: table => new
                {
                    SafeId = table.Column<Guid>(type: "uniqueidentifier", nullable: false),
                    PinChanged = table.Column<DateTime>(type: "datetime2", nullable: false),
                    PinEncrypted = table.Column<string>(type: "nvarchar(max)", nullable: true),
                    AppartmentId = table.Column<Guid>(type: "uniqueidentifier", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Safes", x => x.SafeId);
                    table.ForeignKey(
                        name: "FK_Safes_Appartments_AppartmentId",
                        column: x => x.AppartmentId,
                        principalTable: "Appartments",
                        principalColumn: "AppartmentId",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateIndex(
                name: "IX_Appartments_HotelId",
                table: "Appartments",
                column: "HotelId");

            migrationBuilder.CreateIndex(
                name: "IX_Safes_AppartmentId",
                table: "Safes",
                column: "AppartmentId");
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "Safes");

            migrationBuilder.DropTable(
                name: "Appartments");

            migrationBuilder.DropTable(
                name: "Hotels");
        }
    }
}
