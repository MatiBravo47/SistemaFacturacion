#pragma once

#include "Usuario.h"
#include "DBHelper.h"

using namespace System;
using namespace System::Data::SqlClient;

namespace SistemaUsuarios
{
    public ref class UsuarioDAO
    {
    public:

        Usuario^ Login(String^ email, String^ password)
        {
            try 
            {
                SqlConnection^ conexion =
                    gcnew SqlConnection(DBHelper::ConnectionString);

                conexion->Open();

                String^ consulta =
                    "SELECT Nombre, Password, Rol "
                    "FROM Usuarios "
                    "WHERE Email = @Email "
                    "AND Password = @Password "
                    "AND Activo = 1";

                SqlCommand^ comando =
                    gcnew SqlCommand(consulta, conexion);

                comando->Parameters->AddWithValue("@Email", email);
                comando->Parameters->AddWithValue("@Password", password);

                SqlDataReader^ lector = 
                    comando->ExecuteReader();

                if (lector->Read())
                {
                    Usuario^ usuario = gcnew Usuario(
                        lector["Nombre"]->ToString(),
                        lector["Password"]->ToString(),
                        lector["Rol"]->ToString());

                    lector->Close();
                    conexion->Close();

                    return usuario;
                }

                lector->Close();
                conexion->Close();
                return nullptr;
            }
            catch (Exception^ ex) 
            {
                MessageBox::Show(ex->Message);
                return nullptr;
            }
        }
    };
}


