#pragma once
#pragma once

using namespace System;

namespace SistemaUsuarios
{
	public ref class Proveedor
	{
	private:
		int idProveedor;
		String^ nombre;
		String^ telefono;

	public:

		Proveedor(
			int idProveedor,
			String^ nombre,
			String^ telefono)
		{
			this->idProveedor = idProveedor;
			this->nombre = nombre;
			this->telefono = telefono;
		}

		int GetIdProveedor()
		{
			return idProveedor;
		}

		String^ GetNombre()
		{
			return nombre;
		}

		String^ GetTelefono()
		{
			return telefono;
		}

		void SetNombre(String^ nombre)
		{
			this->nombre = nombre;
		}

		void SetTelefono(String^ telefono)
		{
			this->telefono = telefono;
		}
	};
}