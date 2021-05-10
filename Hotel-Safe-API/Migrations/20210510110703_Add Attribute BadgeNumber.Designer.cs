﻿// <auto-generated />
using System;
using Hotel_Safe_API.Models;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Infrastructure;
using Microsoft.EntityFrameworkCore.Metadata;
using Microsoft.EntityFrameworkCore.Migrations;
using Microsoft.EntityFrameworkCore.Storage.ValueConversion;

namespace Hotel_Safe_API.Migrations
{
    [DbContext(typeof(HotelSafeContext))]
    [Migration("20210510110703_Add Attribute BadgeNumber")]
    partial class AddAttributeBadgeNumber
    {
        protected override void BuildTargetModel(ModelBuilder modelBuilder)
        {
#pragma warning disable 612, 618
            modelBuilder
                .HasAnnotation("Relational:MaxIdentifierLength", 128)
                .HasAnnotation("ProductVersion", "5.0.5")
                .HasAnnotation("SqlServer:ValueGenerationStrategy", SqlServerValueGenerationStrategy.IdentityColumn);

            modelBuilder.Entity("Hotel_Safe_API.Models.Appartment", b =>
                {
                    b.Property<Guid>("AppartmentId")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("uniqueidentifier");

                    b.Property<Guid>("HotelId")
                        .HasColumnType("uniqueidentifier");

                    b.Property<string>("Name")
                        .HasColumnType("nvarchar(max)");

                    b.HasKey("AppartmentId");

                    b.HasIndex("HotelId");

                    b.ToTable("Appartments");
                });

            modelBuilder.Entity("Hotel_Safe_API.Models.Hotel", b =>
                {
                    b.Property<Guid>("HotelId")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("uniqueidentifier");

                    b.Property<string>("Name")
                        .HasColumnType("nvarchar(max)");

                    b.HasKey("HotelId");

                    b.ToTable("Hotels");
                });

            modelBuilder.Entity("Hotel_Safe_API.Models.Safe", b =>
                {
                    b.Property<Guid>("SafeId")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("uniqueidentifier");

                    b.Property<Guid>("AppartmentId")
                        .HasColumnType("uniqueidentifier");

                    b.Property<string>("BadgeNumber")
                        .HasColumnType("nvarchar(max)");

                    b.Property<string>("Pin")
                        .HasColumnType("nvarchar(max)");

                    b.Property<DateTime>("PinChanged")
                        .HasColumnType("datetime2");

                    b.Property<string>("PinEncrypted")
                        .HasColumnType("nvarchar(max)");

                    b.HasKey("SafeId");

                    b.HasIndex("AppartmentId");

                    b.ToTable("Safes");
                });

            modelBuilder.Entity("Hotel_Safe_API.Models.Appartment", b =>
                {
                    b.HasOne("Hotel_Safe_API.Models.Hotel", "Hotel")
                        .WithMany("Appartments")
                        .HasForeignKey("HotelId")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.Navigation("Hotel");
                });

            modelBuilder.Entity("Hotel_Safe_API.Models.Safe", b =>
                {
                    b.HasOne("Hotel_Safe_API.Models.Appartment", "Appartment")
                        .WithMany()
                        .HasForeignKey("AppartmentId")
                        .OnDelete(DeleteBehavior.Cascade)
                        .IsRequired();

                    b.Navigation("Appartment");
                });

            modelBuilder.Entity("Hotel_Safe_API.Models.Hotel", b =>
                {
                    b.Navigation("Appartments");
                });
#pragma warning restore 612, 618
        }
    }
}
