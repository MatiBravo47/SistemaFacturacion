#pragma once
using namespace System;

namespace SistemaUsuarios 
{
	public ref class Producto 
	{
	private:
		int idProducto;
		String^ nombre;
		double precioUnitario;
		int stock;
		double descuento;
		bool activo;

	public:
		Producto(
			int idProducto,
			String^ nombre,
			double precioUnitario,
			int stock,
			double descuento,
			bool activo
			)
		{
			this->idProducto = idProducto;
			this->nombre = nombre;
			this->precioUnitario = precioUnitario;
			this->stock = stock;
			this->descuento = descuento;
			this->activo = activo;

		}

		int GetIdProducto()
		{
			return idProducto;
		};

		String^ GetNombre()
		{
			return nombre;
		};

		double GetPrecioUnitario()
		{
			return precioUnitario;
		};

		int GetStock()
		{
			return stock;
		};

		double GetDescuento()
		{
			return descuento;
		};

		bool GetActivo()
		{
			return activo;
		};


		void SetNombre(String^ nombre)
		{
			this->nombre = nombre;
		}

		void SetPrecioUnitario(double precioUnitario)
		{
			this->precioUnitario = precioUnitario;
		}

		void SetStock(int stock)
		{
			this->stock = stock;
		}

		void SetDescuento(double descuento)
		{
			this->descuento = descuento;
		}

		void SetActivo(bool activo)
		{
			this->activo = activo;
		}


	};
	
}