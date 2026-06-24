#pragma once
#include "DBHelper.h"

namespace SistemaUsuarios {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Data::SqlClient;
    using namespace System::Drawing;

    public ref class FormUsuarios : public System::Windows::Forms::Form
    {
    private:
        DataGridView^ dgvUsuarios;
        TextBox^ txtNombre;
        TextBox^ txtEmail;
        TextBox^ txtPassword;
        ComboBox^ cmbRol;
        Button^ btnAgregar;
        Button^ btnModificar;
        Button^ btnDesactivar;
        Button^ btnActivar;
        Button^ btnLimpiar;
        Label^ lblNombre;
        Label^ lblEmail;
        Label^ lblPassword;
        Label^ lblRol;
        Label^ lblTitulo;
        int             idSeleccionado;

    public:
        FormUsuarios(void)
        {
            idSeleccionado = -1;
            InitializeComponent();
            CargarUsuarios();
        }

    protected:
        ~FormUsuarios()
        {
            if (components) delete components;
        }

    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->Text = L"Administración de Usuarios";
            this->Size = System::Drawing::Size(780, 480);
            this->StartPosition = FormStartPosition::CenterScreen;

            // -- Título --
            lblTitulo = gcnew Label();
            lblTitulo->Text = L"Usuarios del Sistema";
            lblTitulo->Font = gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Bold);
            lblTitulo->Location = System::Drawing::Point(10, 10);
            lblTitulo->Size = System::Drawing::Size(250, 25);

            // -- DataGridView --
            dgvUsuarios = gcnew DataGridView();
            dgvUsuarios->Location = System::Drawing::Point(10, 45);
            dgvUsuarios->Size = System::Drawing::Size(460, 380);
            dgvUsuarios->ReadOnly = true;
            dgvUsuarios->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            dgvUsuarios->MultiSelect = false;
            dgvUsuarios->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            dgvUsuarios->AllowUserToAddRows = false;
            dgvUsuarios->CellClick += gcnew DataGridViewCellEventHandler(
                this, &FormUsuarios::dgvUsuarios_CellClick);

            // -- Labels --
            lblNombre = gcnew Label();
            lblNombre->Text = L"Nombre:";
            lblNombre->Location = System::Drawing::Point(490, 45);

            lblEmail = gcnew Label();
            lblEmail->Text = L"Email:";
            lblEmail->Location = System::Drawing::Point(490, 95);

            lblPassword = gcnew Label();
            lblPassword->Text = L"Contraseña:";
            lblPassword->Location = System::Drawing::Point(490, 145);

            lblRol = gcnew Label();
            lblRol->Text = L"Rol:";
            lblRol->Location = System::Drawing::Point(490, 195);

            // -- TextBoxes --
            txtNombre = gcnew TextBox();
            txtNombre->Location = System::Drawing::Point(490, 65);
            txtNombre->Size = System::Drawing::Size(240, 20);

            txtEmail = gcnew TextBox();
            txtEmail->Location = System::Drawing::Point(490, 115);
            txtEmail->Size = System::Drawing::Size(240, 20);

            txtPassword = gcnew TextBox();
            txtPassword->Location = System::Drawing::Point(490, 165);
            txtPassword->Size = System::Drawing::Size(240, 20);
            txtPassword->PasswordChar = '*';

            // -- ComboBox Rol --
            cmbRol = gcnew ComboBox();
            cmbRol->Location = System::Drawing::Point(490, 215);
            cmbRol->Size = System::Drawing::Size(240, 20);
            cmbRol->DropDownStyle = ComboBoxStyle::DropDownList;
            cmbRol->Items->Add("Admin");
            cmbRol->Items->Add("Cajero");
            cmbRol->Items->Add("Deposito");

            // -- Botones --
            btnAgregar = gcnew Button();
            btnAgregar->Text = L"Agregar";
            btnAgregar->Location = System::Drawing::Point(490, 270);
            btnAgregar->Size = System::Drawing::Size(110, 30);
            btnAgregar->BackColor = Color::FromArgb(40, 167, 69);
            btnAgregar->ForeColor = Color::White;
            btnAgregar->Click += gcnew EventHandler(
                this, &FormUsuarios::btnAgregar_Click);

            btnModificar = gcnew Button();
            btnModificar->Text = L"Modificar";
            btnModificar->Location = System::Drawing::Point(620, 270);
            btnModificar->Size = System::Drawing::Size(110, 30);
            btnModificar->BackColor = Color::FromArgb(0, 123, 255);
            btnModificar->ForeColor = Color::White;
            btnModificar->Click += gcnew EventHandler(
                this, &FormUsuarios::btnModificar_Click);

            btnDesactivar = gcnew Button();
            btnDesactivar->Text = L"Desactivar";
            btnDesactivar->Location = System::Drawing::Point(490, 315);
            btnDesactivar->Size = System::Drawing::Size(110, 30);
            btnDesactivar->BackColor = Color::FromArgb(220, 53, 69);
            btnDesactivar->ForeColor = Color::White;
            btnDesactivar->Click += gcnew EventHandler(
                this, &FormUsuarios::btnDesactivar_Click);

            btnLimpiar = gcnew Button();
            btnLimpiar->Text = L"Limpiar";
            btnLimpiar->Location = System::Drawing::Point(620, 315);
            btnLimpiar->Size = System::Drawing::Size(110, 30);
            btnLimpiar->Click += gcnew EventHandler(
                this, &FormUsuarios::btnLimpiar_Click);

            btnActivar = gcnew Button();
            btnActivar->Text = L"Activar";
            btnActivar->Location = System::Drawing::Point(620, 360);
            btnActivar->Size = System::Drawing::Size(110, 30);
            btnActivar->BackColor = Color::FromArgb(25, 135, 84);
            btnActivar->ForeColor = Color::White;
            btnActivar->Click += gcnew EventHandler(
                this,
                &FormUsuarios::btnActivar_Click);

            // -- Agregar controles --
            this->Controls->Add(lblTitulo);
            this->Controls->Add(dgvUsuarios);
            this->Controls->Add(lblNombre);
            this->Controls->Add(lblEmail);
            this->Controls->Add(lblPassword);
            this->Controls->Add(lblRol);
            this->Controls->Add(txtNombre);
            this->Controls->Add(txtEmail);
            this->Controls->Add(txtPassword);
            this->Controls->Add(cmbRol);
            this->Controls->Add(btnAgregar);
            this->Controls->Add(btnModificar);
            this->Controls->Add(btnDesactivar);
            this->Controls->Add(btnLimpiar);
            this->Controls->Add(btnActivar);
        }

        // ── Cargar grilla ──────────────────────────────────────────
        void CargarUsuarios()
        {
            try
            {
                SqlConnection^ con = gcnew SqlConnection(DBHelper::ConnectionString);
                con->Open();

                String^ sql =
                    "SELECT IdUsuario, Nombre, Email, Rol, "
                    "CASE WHEN Activo = 1 THEN 'Activo' ELSE 'Inactivo' END AS Estado "
                    "FROM Usuarios "
                    "ORDER BY Nombre";

                SqlDataAdapter^ adapter = gcnew SqlDataAdapter(sql, con);
                DataTable^ tabla = gcnew DataTable();
                adapter->Fill(tabla);

                dgvUsuarios->DataSource = tabla;

                // Ocultar columna ID de la vista pero la necesitamos para operaciones
                dgvUsuarios->Columns["IdUsuario"]->Visible = false;

                con->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show(ex->Message, "Error al cargar usuarios");
            }
        }

        // ── Click en fila → cargar campos ──────────────────────────
        void dgvUsuarios_CellClick(Object^ sender, DataGridViewCellEventArgs^ e)
        {
            if (e->RowIndex < 0) return;

            DataGridViewRow^ fila = dgvUsuarios->Rows[e->RowIndex];

            idSeleccionado = Convert::ToInt32(fila->Cells["IdUsuario"]->Value);
            txtNombre->Text = fila->Cells["Nombre"]->Value->ToString();
            txtEmail->Text = fila->Cells["Email"]->Value->ToString();
            txtPassword->Text = "";   // por seguridad no se muestra
            cmbRol->Text = fila->Cells["Rol"]->Value->ToString();
        }

        // ── Agregar ────────────────────────────────────────────────
        void btnAgregar_Click(Object^ sender, EventArgs^ e)
        {
            if (!ValidarCampos(true)) return;

            try
            {
                SqlConnection^ con = gcnew SqlConnection(DBHelper::ConnectionString);
                con->Open();

                String^ sql =
                    "INSERT INTO Usuarios (Nombre, Email, Password, Rol) "
                    "VALUES (@Nombre, @Email, @Password, @Rol)";

                SqlCommand^ cmd = gcnew SqlCommand(sql, con);
                cmd->Parameters->AddWithValue("@Nombre", txtNombre->Text->Trim());
                cmd->Parameters->AddWithValue("@Email", txtEmail->Text->Trim());
                cmd->Parameters->AddWithValue("@Password", txtPassword->Text);
                cmd->Parameters->AddWithValue("@Rol", cmbRol->Text);

                cmd->ExecuteNonQuery();
                con->Close();

                MessageBox::Show("Usuario agregado correctamente.", "Éxito");
                Limpiar();
                CargarUsuarios();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show(ex->Message, "Error al agregar");
            }
        }

        // ── Modificar ──────────────────────────────────────────────
        void btnModificar_Click(Object^ sender, EventArgs^ e)
        {
            if (idSeleccionado == -1)
            {
                MessageBox::Show("Seleccioná un usuario de la lista.", "Aviso");
                return;
            }

            if (!ValidarCampos(false)) return;

            try
            {
                SqlConnection^ con = gcnew SqlConnection(DBHelper::ConnectionString);
                con->Open();

                String^ sql =
                    "UPDATE Usuarios "
                    "SET Nombre = @Nombre, Email = @Email, Rol = @Rol "
                    "WHERE IdUsuario = @Id";

                SqlCommand^ cmd = gcnew SqlCommand(sql, con);
                cmd->Parameters->AddWithValue("@Nombre", txtNombre->Text->Trim());
                cmd->Parameters->AddWithValue("@Email", txtEmail->Text->Trim());
                cmd->Parameters->AddWithValue("@Rol", cmbRol->Text);
                cmd->Parameters->AddWithValue("@Id", idSeleccionado);

                cmd->ExecuteNonQuery();
                con->Close();

                MessageBox::Show("Usuario modificado correctamente.", "Éxito");
                Limpiar();
                CargarUsuarios();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show(ex->Message, "Error al modificar");
            }
        }

        // ── Desactivar (baja lógica) ───────────────────────────────
        void btnDesactivar_Click(Object^ sender, EventArgs^ e)
        {
            if (idSeleccionado == -1)
            {
                MessageBox::Show("Seleccioná un usuario de la lista.", "Aviso");
                return;
            }
            System::Windows::Forms::DialogResult confirm = MessageBox::Show(
                "¿Desactivar este usuario?",
                "Confirmar",
                MessageBoxButtons::YesNo,
                MessageBoxIcon::Warning);

            if (confirm != System::Windows::Forms::DialogResult::Yes) return;

            try
            {
                SqlConnection^ con = gcnew SqlConnection(DBHelper::ConnectionString);
                con->Open();

                String^ sql =
                    "UPDATE Usuarios SET Activo = 0 WHERE IdUsuario = @Id";

                SqlCommand^ cmd = gcnew SqlCommand(sql, con);
                cmd->Parameters->AddWithValue("@Id", idSeleccionado);

                cmd->ExecuteNonQuery();
                con->Close();

                MessageBox::Show("Usuario desactivado.", "Éxito");
                Limpiar();
                CargarUsuarios();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show(ex->Message, "Error al desactivar");
            }
        }

        void btnActivar_Click(
            Object^ sender,
            EventArgs^ e)
        {
            if (idSeleccionado == -1)
            {
                MessageBox::Show(
                    "Seleccioná un usuario.",
                    "Aviso");
                return;
            }

            try
            {
                SqlConnection^ con =
                    gcnew SqlConnection(
                        DBHelper::ConnectionString);

                con->Open();

                String^ sql =
                    "UPDATE Usuarios "
                    "SET Activo = 1 "
                    "WHERE IdUsuario = @Id";

                SqlCommand^ cmd =
                    gcnew SqlCommand(
                        sql,
                        con);

                cmd->Parameters->AddWithValue(
                    "@Id",
                    idSeleccionado);

                cmd->ExecuteNonQuery();

                con->Close();

                MessageBox::Show(
                    "Usuario activado correctamente.",
                    "Éxito");

                Limpiar();

                CargarUsuarios();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show(
                    ex->Message,
                    "Error");
            }
        }

        // ── Limpiar campos ─────────────────────────────────────────
        void btnLimpiar_Click(Object^ sender, EventArgs^ e)
        {
            Limpiar();
        }

        void Limpiar()
        {
            idSeleccionado = -1;
            txtNombre->Text = "";
            txtEmail->Text = "";
            txtPassword->Text = "";
            cmbRol->SelectedIndex = -1;
        }

        // ── Validaciones ───────────────────────────────────────────
        bool ValidarCampos(bool esAlta)
        {
            if (txtNombre->Text->Trim() == "")
            {
                MessageBox::Show("El nombre es obligatorio.", "Validación");
                return false;
            }
            if (txtEmail->Text->Trim() == "")
            {
                MessageBox::Show("El email es obligatorio.", "Validación");
                return false;
            }
            if (esAlta && txtPassword->Text == "")
            {
                MessageBox::Show("La contraseña es obligatoria.", "Validación");
                return false;
            }
            if (cmbRol->SelectedIndex == -1)
            {
                MessageBox::Show("Seleccioná un rol.", "Validación");
                return false;
            }
            return true;
        }
    };
}