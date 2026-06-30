#pragma once
#include "ProveedorDAO.h"

namespace SistemaUsuarios {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormProveedores
	/// </summary>
	public ref class FormProveedores : public System::Windows::Forms::Form
	{
	public:
		FormProveedores(void)
		{
			InitializeComponent();

			CargarProveedores();

			ModoAgregar();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormProveedores()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dgvProveedores;
	protected:
	private: System::Windows::Forms::Label^ lblNombre;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::Label^ lblTelefono;
	private: System::Windows::Forms::TextBox^ txtTelefono;
	private: System::Windows::Forms::Button^ btnNuevo;
	private: System::Windows::Forms::Button^ btnAgregar;
	private: System::Windows::Forms::Button^ btnModificar;
	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::Button^ btnVolver;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colIdProveedor;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colNombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colTelefono;
		   int idProveedorSeleccionado = 0;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		/// 
		void CargarProveedores()
		{
			dgvProveedores->Rows->Clear();

			ProveedorDAO^ dao =
				gcnew ProveedorDAO();

			List<Proveedor^>^ proveedores =
				dao->ObtenerTodos();

			for each (Proveedor ^ proveedor in proveedores)
			{
				dgvProveedores->Rows->Add(
					proveedor->GetIdProveedor(),
					proveedor->GetNombre(),
					proveedor->GetTelefono());
			}
		}

		void ModoAgregar()
		{
			btnNuevo->Enabled = false;

			btnAgregar->Enabled = true;

			btnModificar->Enabled = false;

			btnEliminar->Enabled = false;
		}

		void ModoEditar()
		{
			btnNuevo->Enabled = true;

			btnAgregar->Enabled = false;

			btnModificar->Enabled = true;

			btnEliminar->Enabled = true;
		}

		void LimpiarCampos()
		{
			idProveedorSeleccionado = 0;

			txtNombre->Clear();

			txtTelefono->Clear();

			dgvProveedores->ClearSelection();

			txtNombre->Focus();

			ModoAgregar();
		}

		bool ValidarCampos()
		{
			if (txtNombre->Text->Trim() == "")
			{
				MessageBox::Show(
					"Ingrese un nombre.");

				txtNombre->Focus();

				return false;
			}

			if (txtTelefono->Text->Trim() == "")
			{
				MessageBox::Show(
					"Ingrese un teléfono.");

				txtTelefono->Focus();

				return false;
			}

			return true;
		}
		void InitializeComponent(void)
		{
			this->dgvProveedores = (gcnew System::Windows::Forms::DataGridView());
			this->colIdProveedor = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTelefono = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lblNombre = (gcnew System::Windows::Forms::Label());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->lblTelefono = (gcnew System::Windows::Forms::Label());
			this->txtTelefono = (gcnew System::Windows::Forms::TextBox());
			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->btnAgregar = (gcnew System::Windows::Forms::Button());
			this->btnModificar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProveedores))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvProveedores
			// 
			this->dgvProveedores->AllowUserToAddRows = false;
			this->dgvProveedores->AllowUserToDeleteRows = false;
			this->dgvProveedores->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvProveedores->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvProveedores->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->colIdProveedor,
					this->colNombre, this->colTelefono
			});
			this->dgvProveedores->Location = System::Drawing::Point(12, 64);
			this->dgvProveedores->MultiSelect = false;
			this->dgvProveedores->Name = L"dgvProveedores";
			this->dgvProveedores->ReadOnly = true;
			this->dgvProveedores->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvProveedores->Size = System::Drawing::Size(298, 201);
			this->dgvProveedores->TabIndex = 0;
			this->dgvProveedores->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormProveedores::dgvProveedores_CellClick);
			// 
			// colIdProveedor
			// 
			this->colIdProveedor->HeaderText = L"ID";
			this->colIdProveedor->Name = L"colIdProveedor";
			this->colIdProveedor->ReadOnly = true;
			// 
			// colNombre
			// 
			this->colNombre->HeaderText = L"Nombre";
			this->colNombre->Name = L"colNombre";
			this->colNombre->ReadOnly = true;
			// 
			// colTelefono
			// 
			this->colTelefono->HeaderText = L"Teléfono";
			this->colTelefono->Name = L"colTelefono";
			this->colTelefono->ReadOnly = true;
			// 
			// lblNombre
			// 
			this->lblNombre->AutoSize = true;
			this->lblNombre->Location = System::Drawing::Point(346, 64);
			this->lblNombre->Name = L"lblNombre";
			this->lblNombre->Size = System::Drawing::Size(44, 13);
			this->lblNombre->TabIndex = 1;
			this->lblNombre->Text = L"Nombre";
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(349, 90);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(100, 20);
			this->txtNombre->TabIndex = 2;
			// 
			// lblTelefono
			// 
			this->lblTelefono->AutoSize = true;
			this->lblTelefono->Location = System::Drawing::Point(346, 125);
			this->lblTelefono->Name = L"lblTelefono";
			this->lblTelefono->Size = System::Drawing::Size(49, 13);
			this->lblTelefono->TabIndex = 3;
			this->lblTelefono->Text = L"Telefono";
			// 
			// txtTelefono
			// 
			this->txtTelefono->Location = System::Drawing::Point(349, 154);
			this->txtTelefono->Name = L"txtTelefono";
			this->txtTelefono->Size = System::Drawing::Size(100, 20);
			this->txtTelefono->TabIndex = 4;
			// 
			// btnNuevo
			// 
			this->btnNuevo->Location = System::Drawing::Point(201, 30);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Size = System::Drawing::Size(75, 23);
			this->btnNuevo->TabIndex = 5;
			this->btnNuevo->Text = L"Nuevo";
			this->btnNuevo->UseVisualStyleBackColor = true;
			this->btnNuevo->Click += gcnew System::EventHandler(this, &FormProveedores::btnNuevo_Click);
			// 
			// btnAgregar
			// 
			this->btnAgregar->Location = System::Drawing::Point(416, 309);
			this->btnAgregar->Name = L"btnAgregar";
			this->btnAgregar->Size = System::Drawing::Size(75, 23);
			this->btnAgregar->TabIndex = 6;
			this->btnAgregar->Text = L"Agregar";
			this->btnAgregar->UseVisualStyleBackColor = true;
			this->btnAgregar->Click += gcnew System::EventHandler(this, &FormProveedores::btnAgregar_Click);
			// 
			// btnModificar
			// 
			this->btnModificar->Location = System::Drawing::Point(360, 277);
			this->btnModificar->Name = L"btnModificar";
			this->btnModificar->Size = System::Drawing::Size(75, 23);
			this->btnModificar->TabIndex = 7;
			this->btnModificar->Text = L"Modificar";
			this->btnModificar->UseVisualStyleBackColor = true;
			this->btnModificar->Click += gcnew System::EventHandler(this, &FormProveedores::btnModificar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(451, 277);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(75, 23);
			this->btnEliminar->TabIndex = 8;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &FormProveedores::btnEliminar_Click);
			// 
			// btnVolver
			// 
			this->btnVolver->Location = System::Drawing::Point(23, 324);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(75, 23);
			this->btnVolver->TabIndex = 9;
			this->btnVolver->Text = L"Volver";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &FormProveedores::btnVolver_Click);
			// 
			// FormProveedores
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(611, 392);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnModificar);
			this->Controls->Add(this->btnAgregar);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->txtTelefono);
			this->Controls->Add(this->lblTelefono);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->lblNombre);
			this->Controls->Add(this->dgvProveedores);
			this->Name = L"FormProveedores";
			this->Text = L"FormProveedores";
			this->Load += gcnew System::EventHandler(this, &FormProveedores::FormProveedores_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProveedores))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FormProveedores_Load(System::Object^ sender, System::EventArgs^ e) {
		CargarProveedores();

		ModoAgregar();
	}
private: System::Void dgvProveedores_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex >= 0)
	{
		DataGridViewRow^ fila =
			dgvProveedores->Rows[e->RowIndex];

		idProveedorSeleccionado =
			Convert::ToInt32(
				fila->Cells[0]->Value);

		txtNombre->Text =
			fila->Cells[1]->Value->ToString();

		txtTelefono->Text =
			fila->Cells[2]->Value->ToString();

		ModoEditar();
	}
}
private: System::Void btnNuevo_Click(System::Object^ sender, System::EventArgs^ e) {
	LimpiarCampos();
}
private: System::Void btnAgregar_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!ValidarCampos())
		return;

	Proveedor^ proveedor =
		gcnew Proveedor(
			0,
			txtNombre->Text,
			txtTelefono->Text);

	ProveedorDAO^ dao =
		gcnew ProveedorDAO();

	dao->Agregar(proveedor);

	MessageBox::Show(
		"Proveedor agregado correctamente.");

	CargarProveedores();

	LimpiarCampos();
}
private: System::Void btnModificar_Click(System::Object^ sender, System::EventArgs^ e) {
	if (idProveedorSeleccionado == 0)
	{
		MessageBox::Show(
			"Seleccione un proveedor.");

		return;
	}

	if (!ValidarCampos())
		return;

	Proveedor^ proveedor =
		gcnew Proveedor(
			idProveedorSeleccionado,
			txtNombre->Text,
			txtTelefono->Text);

	ProveedorDAO^ dao =
		gcnew ProveedorDAO();

	dao->Modificar(proveedor);

	MessageBox::Show(
		"Proveedor modificado correctamente.");

	CargarProveedores();

	LimpiarCampos();
}
private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
	if (idProveedorSeleccionado == 0)
	{
		MessageBox::Show(
			"Seleccione un proveedor.");

		return;
	}

	System::Windows::Forms::DialogResult respuesta =
		MessageBox::Show(
			"¿Desea eliminar este proveedor?",
			"Confirmar",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question);

	if (respuesta == System::Windows::Forms::DialogResult::Yes)
	{
		ProveedorDAO^ dao =
			gcnew ProveedorDAO();

		dao->Eliminar(idProveedorSeleccionado);

		MessageBox::Show(
			"Proveedor eliminado correctamente.");

		CargarProveedores();

		LimpiarCampos();
	}
}
private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
