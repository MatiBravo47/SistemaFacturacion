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
	/// Resumen de FormDeposito
	/// </summary>
	public ref class FormDeposito : public System::Windows::Forms::Form
	{
	public:
		FormDeposito(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormDeposito()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::DataGridView^ dgvProductos;
	private: System::Windows::Forms::Label^ lblNombre;
	private: System::Windows::Forms::Label^ lblPrecio;
	private: System::Windows::Forms::Label^ lblStock;
	private: System::Windows::Forms::Label^ lblDescuento;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::TextBox^ txtPrecio;
	private: System::Windows::Forms::TextBox^ txtStock;
	private: System::Windows::Forms::TextBox^ txtDescuento;
	private: System::Windows::Forms::Button^ btnAgregar;
	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::Button^ btnModificar;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colNombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colPrecio;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colStock;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colDescuento;

	private:
		int idProductoSeleccionado = 0;
	private: System::Windows::Forms::Button^ btnNuevo;
	private: System::Windows::Forms::Label^ lblProductos;










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
		/// 
		void CargarProductos()
		{
			dgvProductos->Rows->Clear();

			ProductoDAO^ dao =
				gcnew ProductoDAO();

			List<Producto^>^ productos =
				dao->ObtenerTodos();

			for each (Producto ^ producto in productos)
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

		void LimpiarCampos()
		{
			idProductoSeleccionado = 0;

			txtNombre->Clear();
			txtPrecio->Clear();
			txtStock->Clear();
			txtDescuento->Clear();

			dgvProductos->ClearSelection();

			txtNombre->Focus();
		}
		void ModoAgregar()
		{
			btnAgregar->Enabled = true;

			btnModificar->Enabled = false;

			btnEliminar->Enabled = false;
		}

		void ModoEditar()
		{
			btnAgregar->Enabled = false;

			btnModificar->Enabled = true;

			btnEliminar->Enabled = true;
		}

		bool ValidarProducto()
		{
			if (txtNombre->Text->Trim() == "")
			{
				MessageBox::Show("Ingrese un nombre.");
				txtNombre->Focus();
				return false;
			}

			double precio;

			if (!Double::TryParse(txtPrecio->Text, precio))
			{
				MessageBox::Show("Ingrese un precio válido.");
				txtPrecio->Focus();
				return false;
			}

			if (precio <= 0)
			{
				MessageBox::Show("El precio debe ser mayor a 0.");
				txtPrecio->Focus();
				return false;
			}

			int stock;

			if (!Int32::TryParse(txtStock->Text, stock))
			{
				MessageBox::Show("Ingrese un stock válido.");
				txtStock->Focus();
				return false;
			}

			if (stock < 0)
			{
				MessageBox::Show("El stock no puede ser negativo.");
				txtStock->Focus();
				return false;
			}

			double descuento;

			if (!Double::TryParse(txtDescuento->Text, descuento))
			{
				MessageBox::Show("Ingrese un descuento válido.");
				txtDescuento->Focus();
				return false;
			}

			if (descuento < 0 || descuento > 100)
			{
				MessageBox::Show("El descuento debe estar entre 0 y 100.");
				txtDescuento->Focus();
				return false;
			}

			return true;
		}
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dgvProductos = (gcnew System::Windows::Forms::DataGridView());
			this->colId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colPrecio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colStock = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDescuento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lblNombre = (gcnew System::Windows::Forms::Label());
			this->lblPrecio = (gcnew System::Windows::Forms::Label());
			this->lblStock = (gcnew System::Windows::Forms::Label());
			this->lblDescuento = (gcnew System::Windows::Forms::Label());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtPrecio = (gcnew System::Windows::Forms::TextBox());
			this->txtStock = (gcnew System::Windows::Forms::TextBox());
			this->txtDescuento = (gcnew System::Windows::Forms::TextBox());
			this->btnAgregar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->btnModificar = (gcnew System::Windows::Forms::Button());
			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->lblProductos = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProductos))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 226);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Cerrar sesion";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FormDeposito::button1_Click);
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
			this->dgvProductos->Location = System::Drawing::Point(15, 33);
			this->dgvProductos->MultiSelect = false;
			this->dgvProductos->Name = L"dgvProductos";
			this->dgvProductos->ReadOnly = true;
			this->dgvProductos->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvProductos->Size = System::Drawing::Size(543, 150);
			this->dgvProductos->TabIndex = 3;
			this->dgvProductos->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormDeposito::dgvProductos_CellClick);
			this->dgvProductos->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormDeposito::dgvProductos_CellContentClick);
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
			// lblNombre
			// 
			this->lblNombre->AutoSize = true;
			this->lblNombre->Location = System::Drawing::Point(602, 9);
			this->lblNombre->Name = L"lblNombre";
			this->lblNombre->Size = System::Drawing::Size(44, 13);
			this->lblNombre->TabIndex = 4;
			this->lblNombre->Text = L"Nombre";
			// 
			// lblPrecio
			// 
			this->lblPrecio->AutoSize = true;
			this->lblPrecio->Location = System::Drawing::Point(609, 64);
			this->lblPrecio->Name = L"lblPrecio";
			this->lblPrecio->Size = System::Drawing::Size(37, 13);
			this->lblPrecio->TabIndex = 5;
			this->lblPrecio->Text = L"Precio";
			this->lblPrecio->Click += gcnew System::EventHandler(this, &FormDeposito::lblPrecio_Click);
			// 
			// lblStock
			// 
			this->lblStock->AutoSize = true;
			this->lblStock->Location = System::Drawing::Point(602, 116);
			this->lblStock->Name = L"lblStock";
			this->lblStock->Size = System::Drawing::Size(35, 13);
			this->lblStock->TabIndex = 6;
			this->lblStock->Text = L"Stock";
			this->lblStock->Click += gcnew System::EventHandler(this, &FormDeposito::txtStock_Click);
			// 
			// lblDescuento
			// 
			this->lblDescuento->AutoSize = true;
			this->lblDescuento->Location = System::Drawing::Point(602, 162);
			this->lblDescuento->Name = L"lblDescuento";
			this->lblDescuento->Size = System::Drawing::Size(59, 13);
			this->lblDescuento->TabIndex = 7;
			this->lblDescuento->Text = L"Descuento";
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(605, 25);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(175, 20);
			this->txtNombre->TabIndex = 8;
			// 
			// txtPrecio
			// 
			this->txtPrecio->Location = System::Drawing::Point(605, 80);
			this->txtPrecio->Name = L"txtPrecio";
			this->txtPrecio->Size = System::Drawing::Size(175, 20);
			this->txtPrecio->TabIndex = 9;
			// 
			// txtStock
			// 
			this->txtStock->Location = System::Drawing::Point(605, 132);
			this->txtStock->Name = L"txtStock";
			this->txtStock->Size = System::Drawing::Size(175, 20);
			this->txtStock->TabIndex = 10;
			// 
			// txtDescuento
			// 
			this->txtDescuento->Location = System::Drawing::Point(605, 178);
			this->txtDescuento->Name = L"txtDescuento";
			this->txtDescuento->Size = System::Drawing::Size(175, 20);
			this->txtDescuento->TabIndex = 11;
			// 
			// btnAgregar
			// 
			this->btnAgregar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->btnAgregar->Location = System::Drawing::Point(648, 240);
			this->btnAgregar->Name = L"btnAgregar";
			this->btnAgregar->Size = System::Drawing::Size(75, 23);
			this->btnAgregar->TabIndex = 12;
			this->btnAgregar->Text = L"Agregar";
			this->btnAgregar->UseVisualStyleBackColor = false;
			this->btnAgregar->Click += gcnew System::EventHandler(this, &FormDeposito::btnAgregar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->btnEliminar->Location = System::Drawing::Point(705, 204);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(75, 23);
			this->btnEliminar->TabIndex = 13;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = false;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &FormDeposito::btnEliminar_Click);
			// 
			// btnModificar
			// 
			this->btnModificar->BackColor = System::Drawing::Color::CornflowerBlue;
			this->btnModificar->Location = System::Drawing::Point(605, 204);
			this->btnModificar->Name = L"btnModificar";
			this->btnModificar->Size = System::Drawing::Size(75, 23);
			this->btnModificar->TabIndex = 14;
			this->btnModificar->Text = L"Modificar";
			this->btnModificar->UseVisualStyleBackColor = false;
			this->btnModificar->Click += gcnew System::EventHandler(this, &FormDeposito::btnModificar_Click);
			// 
			// btnNuevo
			// 
			this->btnNuevo->Location = System::Drawing::Point(483, 9);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Size = System::Drawing::Size(75, 23);
			this->btnNuevo->TabIndex = 15;
			this->btnNuevo->Text = L"Nuevo";
			this->btnNuevo->UseVisualStyleBackColor = true;
			this->btnNuevo->Click += gcnew System::EventHandler(this, &FormDeposito::button2_Click_1);
			// 
			// lblProductos
			// 
			this->lblProductos->AutoSize = true;
			this->lblProductos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->lblProductos->Location = System::Drawing::Point(15, 9);
			this->lblProductos->Name = L"lblProductos";
			this->lblProductos->Size = System::Drawing::Size(81, 20);
			this->lblProductos->TabIndex = 16;
			this->lblProductos->Text = L"Productos";
			// 
			// FormDeposito
			// 
			this->AccessibleRole = System::Windows::Forms::AccessibleRole::SplitButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(827, 261);
			this->Controls->Add(this->lblProductos);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->btnModificar);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnAgregar);
			this->Controls->Add(this->txtDescuento);
			this->Controls->Add(this->txtStock);
			this->Controls->Add(this->txtPrecio);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->lblDescuento);
			this->Controls->Add(this->lblStock);
			this->Controls->Add(this->lblPrecio);
			this->Controls->Add(this->lblNombre);
			this->Controls->Add(this->dgvProductos);
			this->Controls->Add(this->button1);
			this->Name = L"FormDeposito";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Panel de deposito";
			this->Load += gcnew System::EventHandler(this, &FormDeposito::FormDeposito_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProductos))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void dgvProductos_CellContentClick(
	System::Object^ sender,
	System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	
}
private: System::Void txtStock_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void FormDeposito_Load(System::Object^ sender, System::EventArgs^ e) {
	CargarProductos();

	ModoAgregar();
}
private: System::Void btnAgregar_Click(
	System::Object^ sender,
	System::EventArgs^ e)
{
	if (!ValidarProducto())
	{
		return;
	}
	Producto^ producto =
		gcnew Producto(
			0,
			txtNombre->Text,
			Convert::ToDouble(
				txtPrecio->Text),
			Convert::ToInt32(
				txtStock->Text),
			Convert::ToDouble(
				txtDescuento->Text),
			true
		);

	ProductoDAO^ dao =
		gcnew ProductoDAO();

	dao->Agregar(producto);

	MessageBox::Show(
		"Producto agregado correctamente");

	CargarProductos();

	LimpiarCampos();

	ModoAgregar();
}
private: System::Void btnModificar_Click(
	System::Object^ sender,
	System::EventArgs^ e)
{
	if (idProductoSeleccionado == 0)
	{
		MessageBox::Show(
			"Seleccione un producto");

		return;
	}
	if (!ValidarProducto())
	{
		return;
	}

	Producto^ producto =
		gcnew Producto(
			idProductoSeleccionado,
			txtNombre->Text,
			Convert::ToDouble(
				txtPrecio->Text),
			Convert::ToInt32(
				txtStock->Text),
			Convert::ToDouble(
				txtDescuento->Text),
			true);

	ProductoDAO^ dao =
		gcnew ProductoDAO();

	dao->Modificar(producto);

	MessageBox::Show(
		"Producto modificado");

	CargarProductos();

	LimpiarCampos();

	ModoAgregar();
}
private: System::Void btnEliminar_Click(
	System::Object^ sender,
	System::EventArgs^ e)
{
	if (idProductoSeleccionado == 0)
	{
		MessageBox::Show(
			"Seleccione un producto");

		return;
	}

	System::Windows::Forms::DialogResult respuesta =
		MessageBox::Show(
			"¿Desea eliminar este producto?",
			"Confirmar",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question);

	if (respuesta == System::Windows::Forms::DialogResult::Yes)
	{
		ProductoDAO^ dao =
			gcnew ProductoDAO();

		dao->Eliminar(
			idProductoSeleccionado);

		MessageBox::Show(
			"Producto eliminado");

		CargarProductos();

		LimpiarCampos();

		ModoAgregar();
	}
}
private: System::Void dgvProductos_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex >= 0)
	{
		DataGridViewRow^ fila =
			dgvProductos->Rows[e->RowIndex];

		idProductoSeleccionado =
			Convert::ToInt32(
				fila->Cells[0]->Value);

		txtNombre->Text =
			fila->Cells[1]->Value->ToString();

		txtPrecio->Text =
			fila->Cells[2]->Value->ToString();

		txtStock->Text =
			fila->Cells[3]->Value->ToString();

		txtDescuento->Text =
			fila->Cells[4]->Value->ToString();
		ModoEditar();
	}
}
private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	LimpiarCampos();

	ModoAgregar();
}
private: System::Void lblPrecio_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
