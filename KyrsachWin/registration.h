#pragma once
#include "registration.h"
#include "Serialization.h"
namespace KyrsachWin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ registration
	/// </summary>
	public ref class registration : public System::Windows::Forms::Form
	{
	public:
		registration(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~registration()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ usernameText;
	protected:

	protected:

	private: System::Windows::Forms::TextBox^ nameTextBox;
	protected:

	private: System::Windows::Forms::TextBox^ surnameBox;
	private: System::Windows::Forms::TextBox^ emailText;
	private: System::Windows::Forms::TextBox^ passwordText;






	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ saveInfo;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ phonenumberText;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->usernameText = (gcnew System::Windows::Forms::TextBox());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->surnameBox = (gcnew System::Windows::Forms::TextBox());
			this->emailText = (gcnew System::Windows::Forms::TextBox());
			this->passwordText = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->saveInfo = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->phonenumberText = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// usernameText
			// 
			this->usernameText->Location = System::Drawing::Point(164, 50);
			this->usernameText->Name = L"usernameText";
			this->usernameText->Size = System::Drawing::Size(157, 20);
			this->usernameText->TabIndex = 4;
			// 
			// nameTextBox
			// 
			this->nameTextBox->Location = System::Drawing::Point(164, 108);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(157, 20);
			this->nameTextBox->TabIndex = 5;
			// 
			// surnameBox
			// 
			this->surnameBox->Location = System::Drawing::Point(164, 178);
			this->surnameBox->Name = L"surnameBox";
			this->surnameBox->Size = System::Drawing::Size(157, 20);
			this->surnameBox->TabIndex = 6;
			// 
			// emailText
			// 
			this->emailText->Location = System::Drawing::Point(164, 242);
			this->emailText->Name = L"emailText";
			this->emailText->Size = System::Drawing::Size(157, 20);
			this->emailText->TabIndex = 7;
			// 
			// passwordText
			// 
			this->passwordText->Location = System::Drawing::Point(164, 307);
			this->passwordText->Name = L"passwordText";
			this->passwordText->Size = System::Drawing::Size(157, 20);
			this->passwordText->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(211, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Username";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(220, 92);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(217, 162);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Surname";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(220, 226);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(32, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Email";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(217, 291);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Password";
			// 
			// saveInfo
			// 
			this->saveInfo->BackColor = System::Drawing::SystemColors::Info;
			this->saveInfo->Location = System::Drawing::Point(164, 424);
			this->saveInfo->Name = L"saveInfo";
			this->saveInfo->Size = System::Drawing::Size(157, 65);
			this->saveInfo->TabIndex = 14;
			this->saveInfo->Text = L"«берегти";
			this->saveInfo->UseVisualStyleBackColor = false;
			this->saveInfo->Click += gcnew System::EventHandler(this, &registration::saveInfo_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(211, 353);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(78, 13);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Phone Number";
			// 
			// phonenumberText
			// 
			this->phonenumberText->Location = System::Drawing::Point(164, 369);
			this->phonenumberText->Name = L"phonenumberText";
			this->phonenumberText->Size = System::Drawing::Size(157, 20);
			this->phonenumberText->TabIndex = 15;
			this->phonenumberText->Text = L"+380";
			// 
			// registration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(488, 555);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->phonenumberText);
			this->Controls->Add(this->saveInfo);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->passwordText);
			this->Controls->Add(this->emailText);
			this->Controls->Add(this->surnameBox);
			this->Controls->Add(this->nameTextBox);
			this->Controls->Add(this->usernameText);
			this->Name = L"registration";
			this->Text = L"registration";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void saveInfo_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ username = usernameText->Text;
		String^ name = nameTextBox->Text;
		String^ surname = surnameBox->Text;
		String^ email = emailText->Text;
		String^ password = passwordText->Text;
		String^ phonenumber = phonenumberText->Text;
		// зробити перев≥рку чи вс≥ пол€ заповнен≥ ≥ чи в правильному формат≥ email

		if (username == "" || name == "" || surname == "" || email == "" || password == "" || phonenumber == "")
		{
			MessageBox::Show("You missed a field.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		if (!email->Contains("@") || !email->EndsWith(".com"))
		{
			MessageBox::Show("Please enter a valid email address.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		_Admin^ _admin_ = gcnew _Admin(username, password, email, phonenumber, name, surname);
		Serialization^ info = gcnew Serialization();
		
		info->saveDataUser(_admin_);
		Close();
		MessageBox::Show("Data saved successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

};
}
