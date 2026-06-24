#pragma once

#include "DBHelper.h"

using namespace System;
using namespace System::Data::SqlClient;

namespace SistemaUsuarios
{
	public ref class DetalleFacturaDAO
	{
	public:

		void AgregarDetalle(
			int idFactura,
			int idProducto,
			int cantidad,
			double precio)
		{
			SqlConnection^ conexion =
				gcnew SqlConnection(
					DBHelper::ConnectionString);

			conexion->Open();

			String^ consulta =
				"INSERT INTO DetalleFactura "
				"(IdFactura, IdProducto, Cantidad, Precio) "
				"VALUES "
				"(@IdFactura, @IdProducto, @Cantidad, @Precio)";

			SqlCommand^ comando =
				gcnew SqlCommand(
					consulta,
					conexion);

			comando->Parameters->AddWithValue(
				"@IdFactura",
				idFactura);

			comando->Parameters->AddWithValue(
				"@IdProducto",
				idProducto);

			comando->Parameters->AddWithValue(
				"@Cantidad",
				cantidad);

			comando->Parameters->AddWithValue(
				"@Precio",
				precio);

			comando->ExecuteNonQuery();

			conexion->Close();
		}
	};
}
