#pragma once
#include "ProductoDAO.h"

namespace SistemaUsuarios {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormCajero
	/// </summary>
	public ref class FormCajero : public System::Windows::Forms::Form
	{
	public:
		FormCajero(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
	private:

		void CargarProductos()
		{
			dgvProductos->Rows->Clear();

			ProductoDAO^ dao =
				gcnew ProductoDAO();

			List<Producto^>^ productos =
				dao->ObtenerTodos();

			for each(Producto ^ producto in productos)
			{
				dgvProductos->Rows->Add(
					producto->GetIdProducto(),
					producto->GetNombre(),
					producto->GetPrecioUnitario(),
					producto->GetStock(),
					producto->GetDescuento()
				);
			}
		}

		void CalcularTotal()
		{
			double total = 0;

			for each (DataGridViewRow ^ fila
				in dgvDetalleVenta->Rows)
			{
				if (fila->Cells[4]->Value != nullptr)
				{
					total += Convert::ToDouble(
						fila->Cells[4]->Value);
				}
			}

			lblTotal->Text =
				"Total: $" +
				total.ToString("F2");
		}

	private:
		int idProductoSeleccionado = 0;
		double precioSeleccionado = 0;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colIdProducto;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colProducto;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCantidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colDetallePrecio;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colDetalleSubtotal;










		   String^ nombreSeleccionado = "";


	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormCajero()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dgvProductos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colNombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colPrecio;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colStock;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colDescuento;
	private: System::Windows::Forms::Label^ lblCantidad;
	private: System::Windows::Forms::TextBox^ txtCantidad;
	private: System::Windows::Forms::Button^ btnAgregarVenta;
	private: System::Windows::Forms::DataGridView^ dgvDetalleVenta;
	private: System::Windows::Forms::Label^ lblTotal;
	private: System::Windows::Forms::Button^ btnConfirmarVenta;



	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dgvProductos = (gcnew System::Windows::Forms::DataGridView());
			this->colId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colPrecio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colStock = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDescuento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lblCantidad = (gcnew System::Windows::Forms::Label());
			this->txtCantidad = (gcnew System::Windows::Forms::TextBox());
			this->btnAgregarVenta = (gcnew System::Windows::Forms::Button());
			this->dgvDetalleVenta = (gcnew System::Windows::Forms::DataGridView());
			this->lblTotal = (gcnew System::Windows::Forms::Label());
			this->btnConfirmarVenta = (gcnew System::Windows::Forms::Button());
			this->colIdProducto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colProducto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDetallePrecio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDetalleSubtotal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProductos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDetalleVenta))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Bienvenido cajero";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(366, 583);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Cerrar sesion";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FormCajero::button1_Click);
			// 
			// dgvProductos
			// 
			this->dgvProductos->AllowUserToAddRows = false;
			this->dgvProductos->AllowUserToDeleteRows = false;
			this->dgvProductos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvProductos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->colId, this->colNombre,
					this->colPrecio, this->colStock, this->colDescuento
			});
			this->dgvProductos->Location = System::Drawing::Point(15, 40);
			this->dgvProductos->Name = L"dgvProductos";
			this->dgvProductos->ReadOnly = true;
			this->dgvProductos->Size = System::Drawing::Size(554, 150);
			this->dgvProductos->TabIndex = 2;
			this->dgvProductos->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormCajero::dgvProductos_CellClick);
			// 
			// colId
			// 
			this->colId->HeaderText = L"ID";
			this->colId->Name = L"colId";
			this->colId->ReadOnly = true;
			// 
			// colNombre
			// 
			this->colNombre->HeaderText = L"Nombre";
			this->colNombre->Name = L"colNombre";
			this->colNombre->ReadOnly = true;
			// 
			// colPrecio
			// 
			this->colPrecio->HeaderText = L"Precio";
			this->colPrecio->Name = L"colPrecio";
			this->colPrecio->ReadOnly = true;
			// 
			// colStock
			// 
			this->colStock->HeaderText = L"Stock";
			this->colStock->Name = L"colStock";
			this->colStock->ReadOnly = true;
			// 
			// colDescuento
			// 
			this->colDescuento->HeaderText = L"Descuento";
			this->colDescuento->Name = L"colDescuento";
			this->colDescuento->ReadOnly = true;
			// 
			// lblCantidad
			// 
			this->lblCantidad->AutoSize = true;
			this->lblCantidad->Location = System::Drawing::Point(15, 226);
			this->lblCantidad->Name = L"lblCantidad";
			this->lblCantidad->Size = System::Drawing::Size(49, 13);
			this->lblCantidad->TabIndex = 3;
			this->lblCantidad->Text = L"Cantidad";
			// 
			// txtCantidad
			// 
			this->txtCantidad->Location = System::Drawing::Point(98, 226);
			this->txtCantidad->Name = L"txtCantidad";
			this->txtCantidad->Size = System::Drawing::Size(100, 20);
			this->txtCantidad->TabIndex = 4;
			// 
			// btnAgregarVenta
			// 
			this->btnAgregarVenta->Location = System::Drawing::Point(311, 222);
			this->btnAgregarVenta->Name = L"btnAgregarVenta";
			this->btnAgregarVenta->Size = System::Drawing::Size(95, 23);
			this->btnAgregarVenta->TabIndex = 5;
			this->btnAgregarVenta->Text = L"Agregar venta";
			this->btnAgregarVenta->UseVisualStyleBackColor = true;
			this->btnAgregarVenta->Click += gcnew System::EventHandler(this, &FormCajero::btnAgregarVenta_Click);
			// 
			// dgvDetalleVenta
			// 
			this->dgvDetalleVenta->AllowUserToAddRows = false;
			this->dgvDetalleVenta->AllowUserToDeleteRows = false;
			this->dgvDetalleVenta->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvDetalleVenta->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->colIdProducto,
					this->colProducto, this->colCantidad, this->colDetallePrecio, this->colDetalleSubtotal
			});
			this->dgvDetalleVenta->Location = System::Drawing::Point(15, 296);
			this->dgvDetalleVenta->Name = L"dgvDetalleVenta";
			this->dgvDetalleVenta->ReadOnly = true;
			this->dgvDetalleVenta->Size = System::Drawing::Size(554, 150);
			this->dgvDetalleVenta->TabIndex = 6;
			this->dgvDetalleVenta->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormCajero::dgvDetalleVenta_CellContentClick);
			// 
			// lblTotal
			// 
			this->lblTotal->AutoSize = true;
			this->lblTotal->Location = System::Drawing::Point(18, 475);
			this->lblTotal->Name = L"lblTotal";
			this->lblTotal->Size = System::Drawing::Size(49, 13);
			this->lblTotal->TabIndex = 7;
			this->lblTotal->Text = L"Total: $0";
			// 
			// btnConfirmarVenta
			// 
			this->btnConfirmarVenta->Location = System::Drawing::Point(18, 514);
			this->btnConfirmarVenta->Name = L"btnConfirmarVenta";
			this->btnConfirmarVenta->Size = System::Drawing::Size(112, 23);
			this->btnConfirmarVenta->TabIndex = 8;
			this->btnConfirmarVenta->Text = L"Confirmar venta";
			this->btnConfirmarVenta->UseVisualStyleBackColor = true;
			// 
			// colIdProducto
			// 
			this->colIdProducto->HeaderText = L"IdProducto";
			this->colIdProducto->Name = L"colIdProducto";
			this->colIdProducto->ReadOnly = true;
			this->colIdProducto->Visible = false;
			// 
			// colProducto
			// 
			this->colProducto->HeaderText = L"Producto";
			this->colProducto->Name = L"colProducto";
			this->colProducto->ReadOnly = true;
			// 
			// colCantidad
			// 
			this->colCantidad->HeaderText = L"Cantidad";
			this->colCantidad->Name = L"colCantidad";
			this->colCantidad->ReadOnly = true;
			// 
			// colDetallePrecio
			// 
			this->colDetallePrecio->HeaderText = L"Precio";
			this->colDetallePrecio->Name = L"colDetallePrecio";
			this->colDetallePrecio->ReadOnly = true;
			// 
			// colDetalleSubtotal
			// 
			this->colDetalleSubtotal->HeaderText = L"Subtotal";
			this->colDetalleSubtotal->Name = L"colDetalleSubtotal";
			this->colDetalleSubtotal->ReadOnly = true;
			// 
			// FormCajero
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(793, 632);
			this->Controls->Add(this->btnConfirmarVenta);
			this->Controls->Add(this->lblTotal);
			this->Controls->Add(this->dgvDetalleVenta);
			this->Controls->Add(this->btnAgregarVenta);
			this->Controls->Add(this->txtCantidad);
			this->Controls->Add(this->lblCantidad);
			this->Controls->Add(this->dgvProductos);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"FormCajero";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Panel de Caja";
			this->Load += gcnew System::EventHandler(this, &FormCajero::FormCajero_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProductos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDetalleVenta))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FormCajero_Load(
		System::Object^ sender,
		System::EventArgs^ e)
	{
		CargarProductos();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void dgvProductos_CellClick(
	System::Object^ sender,
	System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	if (e->RowIndex >= 0)
	{
		DataGridViewRow^ fila =
			dgvProductos->Rows[e->RowIndex];

		idProductoSeleccionado =
			Convert::ToInt32(
				fila->Cells[0]->Value);

		nombreSeleccionado =
			fila->Cells[1]->Value->ToString();

		precioSeleccionado =
			Convert::ToDouble(
				fila->Cells[2]->Value);
	}
}
private: System::Void btnAgregarVenta_Click(
	System::Object^ sender,
	System::EventArgs^ e)
{
	if (idProductoSeleccionado == 0)
	{
		MessageBox::Show(
			"Seleccione un producto");

		return;
	}

	int cantidad =
		Convert::ToInt32(
			txtCantidad->Text);

	double subtotal =
		cantidad * precioSeleccionado;

	dgvDetalleVenta->Rows->Add(
		idProductoSeleccionado,
		nombreSeleccionado,
		cantidad,
		precioSeleccionado,
		subtotal);

	CalcularTotal();
}
private: System::Void dgvDetalleVenta_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
