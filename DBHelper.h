#pragma once
using namespace System;

namespace SistemaUsuarios {
    public ref class DBHelper {
    public:
        static String^ ConnectionString =
            "Server=MATIASNOTEBOOK\\SQLEXPRESS;"
            "Database=SistemaFacturacion;"
            "Trusted_Connection=True;"
            "TrustServerCertificate=True;";
    };
}