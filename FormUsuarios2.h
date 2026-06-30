#pragma once
#include "DBHelper.h"

namespace SistemaUsuarios {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Resumen de FormUsuarios2
	/// </summary>
	public ref class FormUsuarios2 : public System::Windows::Forms::Form
	{
	public:
		FormUsuarios2(void)
		{
			InitializeComponent();

			CargarUsuarios();

			ModoAgregar();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormUsuarios2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dgvUsuarios;
	private: System::Windows::Forms::Button^ btnNuevoUsuario;
	private: System::Windows::Forms::Label^ lblNombre;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::Label^ lblEmail;
	private: System::Windows::Forms::TextBox^ txtEmail;
	private: System::Windows::Forms::Label^ lblContraseña;
	private: System::Windows::Forms::TextBox^ txtContraseña;
	private: System::Windows::Forms::Label^ lblRol;

	private: System::Windows::Forms::Button^ btnModificar;
	private: System::Windows::Forms::Button^ btnAgregar;
	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::Button^ btnVolver;
	private: System::Windows::Forms::ComboBox^ cmbRol;
	private: System::Windows::Forms::Label^ lblAdministracionUsuarios;

	private:

		int idUsuarioSeleccionado = 0;

	protected:

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
		void CargarUsuarios()
		{
			try
			{
				SqlConnection^ conexion =
					gcnew SqlConnection(
						DBHelper::ConnectionString);

				conexion->Open();

				String^ sql =
					"SELECT IdUsuario, Nombre, Email, Rol "
					"FROM Usuarios "
					"ORDER BY Nombre";

				SqlDataAdapter^ adapter =
					gcnew SqlDataAdapter(
						sql,
						conexion);

				DataTable^ tabla =
					gcnew DataTable();

				adapter->Fill(tabla);

				dgvUsuarios->DataSource = tabla;

				dgvUsuarios->Columns["IdUsuario"]->Visible = false;

				conexion->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(
					ex->Message,
					"Error");
			}
		}

		void ModoAgregar()
		{
			btnNuevoUsuario->Enabled = false;

			btnAgregar->Enabled = true;

			btnModificar->Enabled = false;

			btnEliminar->Enabled = false;
		}

		void ModoEditar()
		{
			btnNuevoUsuario->Enabled = true;

			btnAgregar->Enabled = false;

			btnModificar->Enabled = true;

			btnEliminar->Enabled = true;
		}

		void LimpiarCampos()
		{
			idUsuarioSeleccionado = 0;

			txtNombre->Clear();

			txtEmail->Clear();

			txtContraseña->Clear();

			cmbRol->SelectedIndex = -1;

			dgvUsuarios->ClearSelection();

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

			if (txtEmail->Text->Trim() == "")
			{
				MessageBox::Show(
					"Ingrese un email.");

				txtEmail->Focus();

				return false;
			}

			if (txtContraseña->Text->Trim() == "")
			{
				MessageBox::Show(
					"Ingrese una contraseña.");

				txtContraseña->Focus();

				return false;
			}

			if (cmbRol->SelectedIndex == -1)
			{
				MessageBox::Show(
					"Seleccione un rol.");

				cmbRol->Focus();

				return false;
			}

			return true;
		}

		void InitializeComponent(void)
		{
			this->dgvUsuarios = (gcnew System::Windows::Forms::DataGridView());
			this->btnNuevoUsuario = (gcnew System::Windows::Forms::Button());
			this->lblNombre = (gcnew System::Windows::Forms::Label());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->lblEmail = (gcnew System::Windows::Forms::Label());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->lblContraseña = (gcnew System::Windows::Forms::Label());
			this->txtContraseña = (gcnew System::Windows::Forms::TextBox());
			this->lblRol = (gcnew System::Windows::Forms::Label());
			this->btnModificar = (gcnew System::Windows::Forms::Button());
			this->btnAgregar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->cmbRol = (gcnew System::Windows::Forms::ComboBox());
			this->lblAdministracionUsuarios = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUsuarios))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvUsuarios
			// 
			this->dgvUsuarios->AllowUserToAddRows = false;
			this->dgvUsuarios->AllowUserToDeleteRows = false;
			this->dgvUsuarios->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvUsuarios->Location = System::Drawing::Point(12, 45);
			this->dgvUsuarios->MultiSelect = false;
			this->dgvUsuarios->Name = L"dgvUsuarios";
			this->dgvUsuarios->ReadOnly = true;
			this->dgvUsuarios->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvUsuarios->Size = System::Drawing::Size(477, 245);
			this->dgvUsuarios->TabIndex = 0;
			this->dgvUsuarios->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormUsuarios2::dgvUsuarios_CellClick);
			// 
			// btnNuevoUsuario
			// 
			this->btnNuevoUsuario->Location = System::Drawing::Point(414, 16);
			this->btnNuevoUsuario->Name = L"btnNuevoUsuario";
			this->btnNuevoUsuario->Size = System::Drawing::Size(75, 23);
			this->btnNuevoUsuario->TabIndex = 1;
			this->btnNuevoUsuario->Text = L"Nuevo";
			this->btnNuevoUsuario->UseVisualStyleBackColor = true;
			this->btnNuevoUsuario->Click += gcnew System::EventHandler(this, &FormUsuarios2::btnNuevoUsuario_Click);
			// 
			// lblNombre
			// 
			this->lblNombre->AutoSize = true;
			this->lblNombre->Location = System::Drawing::Point(545, 45);
			this->lblNombre->Name = L"lblNombre";
			this->lblNombre->Size = System::Drawing::Size(44, 13);
			this->lblNombre->TabIndex = 2;
			this->lblNombre->Text = L"Nombre";
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(548, 61);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(155, 20);
			this->txtNombre->TabIndex = 3;
			this->txtNombre->TextChanged += gcnew System::EventHandler(this, &FormUsuarios2::txtNombre_TextChanged);
			// 
			// lblEmail
			// 
			this->lblEmail->AutoSize = true;
			this->lblEmail->Location = System::Drawing::Point(545, 93);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(32, 13);
			this->lblEmail->TabIndex = 4;
			this->lblEmail->Text = L"Email";
			// 
			// txtEmail
			// 
			this->txtEmail->Location = System::Drawing::Point(548, 109);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(155, 20);
			this->txtEmail->TabIndex = 5;
			// 
			// lblContraseña
			// 
			this->lblContraseña->AutoSize = true;
			this->lblContraseña->Location = System::Drawing::Point(545, 141);
			this->lblContraseña->Name = L"lblContraseña";
			this->lblContraseña->Size = System::Drawing::Size(61, 13);
			this->lblContraseña->TabIndex = 6;
			this->lblContraseña->Text = L"Contraseña";
			// 
			// txtContraseña
			// 
			this->txtContraseña->Location = System::Drawing::Point(548, 157);
			this->txtContraseña->Name = L"txtContraseña";
			this->txtContraseña->Size = System::Drawing::Size(154, 20);
			this->txtContraseña->TabIndex = 7;
			// 
			// lblRol
			// 
			this->lblRol->AutoSize = true;
			this->lblRol->Location = System::Drawing::Point(545, 183);
			this->lblRol->Name = L"lblRol";
			this->lblRol->Size = System::Drawing::Size(23, 13);
			this->lblRol->TabIndex = 8;
			this->lblRol->Text = L"Rol";
			// 
			// btnModificar
			// 
			this->btnModificar->Location = System::Drawing::Point(546, 238);
			this->btnModificar->Name = L"btnModificar";
			this->btnModificar->Size = System::Drawing::Size(75, 23);
			this->btnModificar->TabIndex = 10;
			this->btnModificar->Text = L"Modificar";
			this->btnModificar->UseVisualStyleBackColor = true;
			this->btnModificar->Click += gcnew System::EventHandler(this, &FormUsuarios2::btnModificar_Click);
			// 
			// btnAgregar
			// 
			this->btnAgregar->Location = System::Drawing::Point(584, 267);
			this->btnAgregar->Name = L"btnAgregar";
			this->btnAgregar->Size = System::Drawing::Size(75, 23);
			this->btnAgregar->TabIndex = 13;
			this->btnAgregar->Text = L"Agregar";
			this->btnAgregar->UseVisualStyleBackColor = true;
			this->btnAgregar->Click += gcnew System::EventHandler(this, &FormUsuarios2::btnAgregar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(627, 238);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(75, 23);
			this->btnEliminar->TabIndex = 14;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &FormUsuarios2::btnEliminar_Click);
			// 
			// btnVolver
			// 
			this->btnVolver->Location = System::Drawing::Point(12, 298);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(75, 23);
			this->btnVolver->TabIndex = 15;
			this->btnVolver->Text = L"Volver";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &FormUsuarios2::btnVolver_Click);
			// 
			// cmbRol
			// 
			this->cmbRol->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbRol->FormattingEnabled = true;
			this->cmbRol->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Admin", L"Deposito", L"Cajero" });
			this->cmbRol->Location = System::Drawing::Point(548, 199);
			this->cmbRol->Name = L"cmbRol";
			this->cmbRol->Size = System::Drawing::Size(154, 21);
			this->cmbRol->TabIndex = 16;
			// 
			// lblAdministracionUsuarios
			// 
			this->lblAdministracionUsuarios->AutoSize = true;
			this->lblAdministracionUsuarios->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->lblAdministracionUsuarios->Location = System::Drawing::Point(12, 19);
			this->lblAdministracionUsuarios->Name = L"lblAdministracionUsuarios";
			this->lblAdministracionUsuarios->Size = System::Drawing::Size(195, 20);
			this->lblAdministracionUsuarios->TabIndex = 17;
			this->lblAdministracionUsuarios->Text = L"Administracion empleados";
			this->lblAdministracionUsuarios->Click += gcnew System::EventHandler(this, &FormUsuarios2::lblAdministracionUsuarios_Click);
			// 
			// FormUsuarios2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(722, 323);
			this->Controls->Add(this->lblAdministracionUsuarios);
			this->Controls->Add(this->cmbRol);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnAgregar);
			this->Controls->Add(this->btnModificar);
			this->Controls->Add(this->lblRol);
			this->Controls->Add(this->txtContraseña);
			this->Controls->Add(this->lblContraseña);
			this->Controls->Add(this->txtEmail);
			this->Controls->Add(this->lblEmail);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->lblNombre);
			this->Controls->Add(this->btnNuevoUsuario);
			this->Controls->Add(this->dgvUsuarios);
			this->Name = L"FormUsuarios2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormUsuarios2";
			this->Load += gcnew System::EventHandler(this, &FormUsuarios2::FormUsuarios2_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUsuarios))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void txtNombre_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void dgvUsuarios_CellClick(
	System::Object^ sender,
	System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	if (e->RowIndex >= 0)
	{
		DataGridViewRow^ fila =
			dgvUsuarios->Rows[e->RowIndex];

		idUsuarioSeleccionado =
			Convert::ToInt32(
				fila->Cells["IdUsuario"]->Value);

		txtNombre->Text =
			fila->Cells["Nombre"]->Value->ToString();

		txtEmail->Text =
			fila->Cells["Email"]->Value->ToString();

		txtContraseña->Clear();

		cmbRol->Text =
			fila->Cells["Rol"]->Value->ToString();

		ModoEditar();
	}
}
private: System::Void btnNuevoUsuario_Click(System::Object^ sender, System::EventArgs^ e) {
	LimpiarCampos();

	ModoAgregar();
}
private: System::Void btnAgregar_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!ValidarCampos())
		return;

	try
	{
		SqlConnection^ conexion =
			gcnew SqlConnection(DBHelper::ConnectionString);

		conexion->Open();

		String^ sql =
			"INSERT INTO Usuarios "
			"(Nombre, Email, Password, Rol, Activo) "
			"VALUES (@Nombre, @Email, @Password, @Rol, 1)";

		SqlCommand^ comando =
			gcnew SqlCommand(sql, conexion);

		comando->Parameters->AddWithValue("@Nombre", txtNombre->Text);
		comando->Parameters->AddWithValue("@Email", txtEmail->Text);
		comando->Parameters->AddWithValue("@Password", txtContraseña->Text);
		comando->Parameters->AddWithValue("@Rol", cmbRol->Text);

		comando->ExecuteNonQuery();

		conexion->Close();

		MessageBox::Show(
			"Usuario agregado correctamente.");

		CargarUsuarios();

		LimpiarCampos();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
	}
}
	private: System::Void btnModificar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (idUsuarioSeleccionado == 0)
		{
			MessageBox::Show(
				"Seleccione un usuario.");

			return;
		}

		if (!ValidarCampos())
			return;

		try
		{
			SqlConnection^ conexion =
				gcnew SqlConnection(DBHelper::ConnectionString);

			conexion->Open();

			String^ sql =
				"UPDATE Usuarios "
				"SET Nombre = @Nombre, "
				"Email = @Email, "
				"Password = @Password, "
				"Rol = @Rol "
				"WHERE IdUsuario = @IdUsuario";

			SqlCommand^ comando =
				gcnew SqlCommand(sql, conexion);

			comando->Parameters->AddWithValue("@Nombre", txtNombre->Text);
			comando->Parameters->AddWithValue("@Email", txtEmail->Text);
			comando->Parameters->AddWithValue("@Password", txtContraseña->Text);
			comando->Parameters->AddWithValue("@Rol", cmbRol->Text);
			comando->Parameters->AddWithValue("@IdUsuario", idUsuarioSeleccionado);

			comando->ExecuteNonQuery();

			conexion->Close();

			MessageBox::Show(
				"Usuario modificado correctamente.");

			CargarUsuarios();

			LimpiarCampos();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (idUsuarioSeleccionado == 0)
		{
			MessageBox::Show(
				"Seleccione un usuario.");

			return;
		}

		System::Windows::Forms::DialogResult respuesta =
			MessageBox::Show(
				"¿Desea eliminar este usuario?",
				"Confirmar",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Question);

		if (respuesta == System::Windows::Forms::DialogResult::Yes)
		{
			try
			{
				SqlConnection^ conexion =
					gcnew SqlConnection(DBHelper::ConnectionString);

				conexion->Open();

				String^ sql =
					"DELETE FROM Usuarios "
					"WHERE IdUsuario = @IdUsuario";

				SqlCommand^ comando =
					gcnew SqlCommand(sql, conexion);

				comando->Parameters->AddWithValue(
					"@IdUsuario",
					idUsuarioSeleccionado);

				comando->ExecuteNonQuery();

				conexion->Close();

				MessageBox::Show(
					"Usuario eliminado correctamente.");

				CargarUsuarios();

				LimpiarCampos();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}
	}
private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) 
{
	this->Close();
}
private: System::Void FormUsuarios2_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblAdministracionUsuarios_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
