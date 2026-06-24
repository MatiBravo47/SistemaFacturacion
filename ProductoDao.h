#pragma once

#include "Producto.h"
#include "DBHelper.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data::SqlClient;
using namespace System::Windows::Forms;

namespace SistemaUsuarios
{
    public ref class ProductoDAO
    {
    public:

        List<Producto^>^ ObtenerTodos()
        {
            List<Producto^>^ productos =
                gcnew List<Producto^>();

            try
            {
                SqlConnection^ conexion =
                    gcnew SqlConnection(
                        DBHelper::ConnectionString);

                conexion->Open();

                String^ consulta =
                    "SELECT * "
                    "FROM Productos "
                    "WHERE Activo = 1";

                SqlCommand^ comando =
                    gcnew SqlCommand(
                        consulta,
                        conexion);

                SqlDataReader^ lector =
                    comando->ExecuteReader();

                while (lector->Read())
                {
                    Producto^ producto =
                        gcnew Producto(
                            Convert::ToInt32(
                                lector["IdProducto"]),
                            lector["Nombre"]->ToString(),
                            Convert::ToDouble(
                                lector["PrecioUnitario"]),
                            Convert::ToInt32(
                                lector["Stock"]),
                            Convert::ToDouble(
                                lector["Descuento"]),
                            Convert::ToBoolean(
                                lector["Activo"])
                        );

                    productos->Add(producto);
                }

                lector->Close();
                conexion->Close();

                return productos;
            }
            catch (Exception^ ex)
            {
                MessageBox::Show(
                    ex->Message,
                    "Error");

                return productos;
            }
        }

        void Agregar(Producto^ producto)
        {
            try
            {
                SqlConnection^ conexion =
                    gcnew SqlConnection(
                        DBHelper::ConnectionString);

                conexion->Open();

                String^ consulta =
                    "INSERT INTO Productos "
                    "(Nombre, PrecioUnitario, Stock, Descuento, Activo) "
                    "VALUES "
                    "(@Nombre, @PrecioUnitario, @Stock, @Descuento, @Activo)";

                SqlCommand^ comando =
                    gcnew SqlCommand(
                        consulta,
                        conexion);

                comando->Parameters->AddWithValue(
                    "@Nombre",
                    producto->GetNombre());

                comando->Parameters->AddWithValue(
                    "@PrecioUnitario",
                    producto->GetPrecioUnitario());

                comando->Parameters->AddWithValue(
                    "@Stock",
                    producto->GetStock());

                comando->Parameters->AddWithValue(
                    "@Descuento",
                    producto->GetDescuento());

                comando->Parameters->AddWithValue(
                    "@Activo",
                    producto->GetActivo());

                comando->ExecuteNonQuery();

                conexion->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show(
                    ex->Message,
                    "Error");
            }
        }

        void Modificar(Producto^ producto)
        {
            try
            {
                SqlConnection^ conexion =
                    gcnew SqlConnection(
                        DBHelper::ConnectionString);

                conexion->Open();

                String^ consulta =
                    "UPDATE Productos "
                    "SET Nombre = @Nombre, "
                    "PrecioUnitario = @PrecioUnitario, "
                    "Stock = @Stock, "
                    "Descuento = @Descuento "
                    "WHERE IdProducto = @IdProducto";

                SqlCommand^ comando =
                    gcnew SqlCommand(
                        consulta,
                        conexion);

                comando->Parameters->AddWithValue(
                    "@IdProducto",
                    producto->GetIdProducto());

                comando->Parameters->AddWithValue(
                    "@Nombre",
                    producto->GetNombre());

                comando->Parameters->AddWithValue(
                    "@PrecioUnitario",
                    producto->GetPrecioUnitario());

                comando->Parameters->AddWithValue(
                    "@Stock",
                    producto->GetStock());

                comando->Parameters->AddWithValue(
                    "@Descuento",
                    producto->GetDescuento());

                comando->ExecuteNonQuery();

                conexion->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show(ex->Message);
            }
        }

        void Eliminar(int idProducto)
        {
            try
            {
                SqlConnection^ conexion =
                    gcnew SqlConnection(
                        DBHelper::ConnectionString);

                conexion->Open();

                String^ consulta =
                    "UPDATE Productos "
                    "SET Activo = 0 "
                    "WHERE IdProducto = @IdProducto";

                SqlCommand^ comando =
                    gcnew SqlCommand(
                        consulta,
                        conexion);

                comando->Parameters->AddWithValue(
                    "@IdProducto",
                    idProducto);

                comando->ExecuteNonQuery();

                conexion->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show(
                    ex->Message);
            }
        }

        void DescontarStock(
            int idProducto,
            int cantidad)
        {
            SqlConnection^ conexion =
                gcnew SqlConnection(
                    DBHelper::ConnectionString);

            conexion->Open();

            String^ consulta =
                "UPDATE Productos "
                "SET Stock = Stock - @Cantidad "
                "WHERE IdProducto = @IdProducto";

            SqlCommand^ comando =
                gcnew SqlCommand(
                    consulta,
                    conexion);

            comando->Parameters->AddWithValue(
                "@Cantidad",
                cantidad);

            comando->Parameters->AddWithValue(
                "@IdProducto",
                idProducto);

            comando->ExecuteNonQuery();

            conexion->Close();
        }
    };
}