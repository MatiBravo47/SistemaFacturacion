#pragma once
#include "FormInicio.h"
#include "FormAdmin.h"
#include "FormGerente.h"
#include "FormCajero.h"
#include "Usuario.h"

namespace SistemaUsuarios {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		List<Usuario^>^ usuarios;
	public:
		MyForm(void)
		{
			InitializeComponent();
			usuarios = gcnew List<Usuario^>();

			usuarios->Add(
				gcnew Usuario(
					"matias",
					"1111",
					"Admin"));

			usuarios->Add(
				gcnew Usuario(
					"gerente",
					"2222",
					"Gerente"));

			usuarios->Add(
				gcnew Usuario(
					"cajero",
					"3333",
					"Cajero"));
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtEmail;

	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Button^ btnIngresar;
	private: System::Windows::Forms::Button^ btnProbarConexion;
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnIngresar = (gcnew System::Windows::Forms::Button());
			this->btnProbarConexion = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(63, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Email";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(66, 127);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Contraseña";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// txtEmail
			// 
			this->txtEmail->Location = System::Drawing::Point(66, 90);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(100, 20);
			this->txtEmail->TabIndex = 2;
			this->txtEmail->TextChanged += gcnew System::EventHandler(this, &MyForm::txtEmail_TextChanged);
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(66, 154);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(100, 20);
			this->txtPassword->TabIndex = 3;
			// 
			// btnIngresar
			// 
			this->btnIngresar->Location = System::Drawing::Point(81, 180);
			this->btnIngresar->Name = L"btnIngresar";
			this->btnIngresar->Size = System::Drawing::Size(75, 23);
			this->btnIngresar->TabIndex = 4;
			this->btnIngresar->Text = L"Ingresar";
			this->btnIngresar->UseVisualStyleBackColor = true;
			this->btnIngresar->Click += gcnew System::EventHandler(this, &MyForm::btnIngresar_Click);
			// 
			// btnProbarConexion
			// 
			this->btnProbarConexion->Location = System::Drawing::Point(69, 220);
			this->btnProbarConexion->Name = L"btnProbarConexion";
			this->btnProbarConexion->Size = System::Drawing::Size(75, 23);
			this->btnProbarConexion->TabIndex = 5;
			this->btnProbarConexion->Text = L"Probar BD";
			this->btnProbarConexion->UseVisualStyleBackColor = true;
			this->btnProbarConexion->Click += gcnew System::EventHandler(this, &MyForm::btnProbarConexion_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->btnProbarConexion);
			this->Controls->Add(this->btnIngresar);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtEmail);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Inicio de Sesión";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnIngresar_Click(
	System::Object^ sender,
	System::EventArgs^ e)
{
	String^ email = txtEmail->Text;
	String^ password = txtPassword->Text;

	try
	{
		String^ connectionString =
			"Server=MATIASNOTEBOOK\\SQLEXPRESS;"
			"Database=SistemaFacturacion;"
			"Trusted_Connection=True;"
			"TrustServerCertificate=True;";

		SqlConnection^ conexion =
			gcnew SqlConnection(connectionString);

		conexion->Open();

		String^ consulta =
			"SELECT Rol, Nombre "
			"FROM Usuarios "
			"WHERE Email = @Email "
			"AND Password = @Password "
			"AND Activo = 1";

		SqlCommand^ comando =
			gcnew SqlCommand(consulta, conexion);

		comando->Parameters->AddWithValue(
			"@Email",
			email);

		comando->Parameters->AddWithValue(
			"@Password",
			password);

		SqlDataReader^ lector =
			comando->ExecuteReader();

		if (lector->Read())
		{
			String^ rol = lector["Rol"]->ToString();
			String^ nombre =
				lector["Nombre"]->ToString();

			MessageBox::Show(
				"Bienvenido " + nombre);

			if (rol == "Admin")
			{
				FormAdmin^ admin =
					gcnew FormAdmin();

				admin->Show();

				this->Hide();
			}
			else if (rol == "Gerente")
			{
				FormGerente^ gerente =
					gcnew FormGerente();

				gerente->Show();

				this->Hide();
			}
			else if (rol == "Cajero")
			{
				FormCajero^ cajero =
					gcnew FormCajero();

				cajero->Show();

				this->Hide();
			}
		}
		else
		{
			MessageBox::Show(
				"Usuario o contraseña incorrectos",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
		}

		lector->Close();
		conexion->Close();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(
			ex->Message,
			"Error de Base de Datos");
	}
}
private: System::Void btnProbarConexion_Click(
	System::Object^ sender,
	System::EventArgs^ e)
{
	try
	{
		String^ connectionString =
			"Server=MATIASNOTEBOOK\\SQLEXPRESS;"
			"Database=SistemaFacturacion;"
			"Trusted_Connection=True;"
			"TrustServerCertificate=True;";

		SqlConnection^ conexion =
			gcnew SqlConnection(connectionString);

		conexion->Open();

		MessageBox::Show(
			"Conexión exitosa con SQL Server"
		);

		conexion->Close();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(
			ex->Message,
			"Error"
		);
	}
}
private: System::Void txtEmail_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
