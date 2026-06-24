#pragma once
#pragma once

#include "DBHelper.h"

using namespace System;
using namespace System::Data::SqlClient;

namespace SistemaUsuarios
{
	public ref class FacturaDAO
	{
	public:

		int CrearFactura(
			double total,
			int idUsuario)
		{
			SqlConnection^ conexion =
				gcnew SqlConnection(
					DBHelper::ConnectionString);

			conexion->Open();

			String^ consulta =
				"INSERT INTO Facturas "
				"(Fecha, Total, IdUsuario) "
				"VALUES "
				"(GETDATE(), @Total, @IdUsuario); "
				"SELECT SCOPE_IDENTITY();";

			SqlCommand^ comando =
				gcnew SqlCommand(
					consulta,
					conexion);

			comando->Parameters->AddWithValue(
				"@Total",
				total);

			comando->Parameters->AddWithValue(
				"@IdUsuario",
				idUsuario);

			int idFactura =
				Convert::ToInt32(
					comando->ExecuteScalar());

			conexion->Close();

			return idFactura;
		}
	};
}