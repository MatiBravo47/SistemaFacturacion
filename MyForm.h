#pragma once
#include "DBHelper.h"
#include "FormAdmin.h"
#include "FormDeposito.h"
#include "FormCajero.h"
#include "Usuario.h"
#include "UsuarioDAO.h"

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
	public:
		MyForm(void)
		{
			InitializeComponent();
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
			this->label1->Location = System::Drawing::Point(112, 71);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Email";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(112, 125);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Contraseña";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// txtEmail
			// 
			this->txtEmail->Location = System::Drawing::Point(115, 87);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(186, 20);
			this->txtEmail->TabIndex = 2;
			this->txtEmail->TextChanged += gcnew System::EventHandler(this, &MyForm::txtEmail_TextChanged);
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(115, 141);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(186, 20);
			this->txtPassword->TabIndex = 3;
			// 
			// btnIngresar
			// 
			this->btnIngresar->Location = System::Drawing::Point(170, 178);
			this->btnIngresar->Name = L"btnIngresar";
			this->btnIngresar->Size = System::Drawing::Size(75, 23);
			this->btnIngresar->TabIndex = 4;
			this->btnIngresar->Text = L"Ingresar";
			this->btnIngresar->UseVisualStyleBackColor = true;
			this->btnIngresar->Click += gcnew System::EventHandler(this, &MyForm::btnIngresar_Click);
			// 
			// btnProbarConexion
			// 
			this->btnProbarConexion->Location = System::Drawing::Point(170, 241);
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
			this->ClientSize = System::Drawing::Size(408, 309);
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
	private: System::Void label2_Click(
		System::Object^ sender,
		System::EventArgs^ e) 
	{
	}

	private: System::Void btnIngresar_Click(
		System::Object^ sender,
		System::EventArgs^ e)
	{
		String^ email = txtEmail->Text;
		String^ password = txtPassword->Text;

		UsuarioDAO^ usuarioDAO = gcnew UsuarioDAO();

		Usuario^ usuario = usuarioDAO->Login(email, password);

		if (usuario != nullptr)
		{
			MessageBox::Show(
				"Bienvenido " + usuario->GetNombre());

			if (usuario->GetRol() == "Admin")
			{
				FormAdmin^ admin = gcnew FormAdmin();
				admin->Show();
				this->Hide();
			}
			else if (usuario->GetRol() == "Deposito")
			{
				FormDeposito^ deposito = gcnew FormDeposito();
				deposito->Show();
				this->Hide();
			}
			else if (usuario->GetRol() == "Cajero")
			{
				FormCajero^ cajero = gcnew FormCajero();
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
	}
	private: System::Void btnProbarConexion_Click(
	System::Object^ sender,
	System::EventArgs^ e)
	{
		try
		{
			String^ connectionString = DBHelper::ConnectionString;

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
