#pragma once

#include "Proveedor.h"
#include "DBHelper.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data::SqlClient;
using namespace System::Windows::Forms;

namespace SistemaUsuarios
{
	public ref class ProveedorDAO
	{
	public:

		List<Proveedor^>^ ObtenerTodos()
		{
			List<Proveedor^>^ lista =
				gcnew List<Proveedor^>();

			try
			{
				SqlConnection^ conexion =
					gcnew SqlConnection(DBHelper::ConnectionString);

				conexion->Open();

				String^ sql =
					"SELECT * FROM Proveedores ORDER BY Nombre";

				SqlCommand^ comando =
					gcnew SqlCommand(sql, conexion);

				SqlDataReader^ lector =
					comando->ExecuteReader();

				while (lector->Read())
				{
					Proveedor^ proveedor =
						gcnew Proveedor(
							Convert::ToInt32(lector["IdProveedor"]),
							lector["Nombre"]->ToString(),
							lector["Telefono"]->ToString());

					lista->Add(proveedor);
				}

				lector->Close();
				conexion->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}

			return lista;
		}

		void Agregar(Proveedor^ proveedor)
		{
			try
			{
				SqlConnection^ conexion =
					gcnew SqlConnection(DBHelper::ConnectionString);

				conexion->Open();

				String^ sql =
					"INSERT INTO Proveedores(Nombre,Telefono) "
					"VALUES(@Nombre,@Telefono)";

				SqlCommand^ comando =
					gcnew SqlCommand(sql, conexion);

				comando->Parameters->AddWithValue(
					"@Nombre",
					proveedor->GetNombre());

				comando->Parameters->AddWithValue(
					"@Telefono",
					proveedor->GetTelefono());

				comando->ExecuteNonQuery();

				conexion->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}

		void Modificar(Proveedor^ proveedor)
		{
			try
			{
				SqlConnection^ conexion =
					gcnew SqlConnection(DBHelper::ConnectionString);

				conexion->Open();

				String^ sql =
					"UPDATE Proveedores "
					"SET Nombre=@Nombre, "
					"Telefono=@Telefono "
					"WHERE IdProveedor=@IdProveedor";

				SqlCommand^ comando =
					gcnew SqlCommand(sql, conexion);

				comando->Parameters->AddWithValue(
					"@Nombre",
					proveedor->GetNombre());

				comando->Parameters->AddWithValue(
					"@Telefono",
					proveedor->GetTelefono());

				comando->Parameters->AddWithValue(
					"@IdProveedor",
					proveedor->GetIdProveedor());

				comando->ExecuteNonQuery();

				conexion->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}

		void Eliminar(int idProveedor)
		{
			try
			{
				SqlConnection^ conexion =
					gcnew SqlConnection(DBHelper::ConnectionString);

				conexion->Open();

				String^ sql =
					"DELETE FROM Proveedores "
					"WHERE IdProveedor=@IdProveedor";

				SqlCommand^ comando =
					gcnew SqlCommand(sql, conexion);

				comando->Parameters->AddWithValue(
					"@IdProveedor",
					idProveedor);

				comando->ExecuteNonQuery();

				conexion->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}
	};
}
