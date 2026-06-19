#pragma once

using namespace System;

namespace SistemaUsuarios
{
	public ref class Usuario
	{
	private:
		String^ nombre;
		String^ password;
		String^ rol;

	public:
		Usuario(
			String^ nombre,
			String^ password,
			String^ rol)
		{
			this->nombre = nombre;
			this->password = password;
			this->rol = rol;
		}

		String^ GetNombre() 
		{
			return nombre;
		}

		String^ GetPassword() 
		{
			return password;
		}

		String^ GetRol() 
		{
			return rol;
		}
	};
}
