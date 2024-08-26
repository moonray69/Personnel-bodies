#pragma once

#include "MainForm.h"
#include "Serialization.h"
#include "registration.h"



namespace KyrsachWin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ loginTextBox;
	private: System::Windows::Forms::TextBox^ passwordTextBox;
	protected:











	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ loginButton;
	private: System::Windows::Forms::Button^ registrationButton;



	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->loginTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->loginButton = (gcnew System::Windows::Forms::Button());
			this->registrationButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// loginTextBox
			// 
			this->loginTextBox->Location = System::Drawing::Point(307, 114);
			this->loginTextBox->Name = L"loginTextBox";
			this->loginTextBox->Size = System::Drawing::Size(157, 20);
			this->loginTextBox->TabIndex = 0;
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->Location = System::Drawing::Point(307, 213);
			this->passwordTextBox->Name = L"passwordTextBox";
			this->passwordTextBox->Size = System::Drawing::Size(157, 20);
			this->passwordTextBox->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(368, 87);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Login";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(359, 188);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Password";
			// 
			// loginButton
			// 
			this->loginButton->Location = System::Drawing::Point(307, 262);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(158, 59);
			this->loginButton->TabIndex = 4;
			this->loginButton->Text = L"Увійти";
			this->loginButton->UseVisualStyleBackColor = true;
			this->loginButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// registrationButton
			// 
			this->registrationButton->Location = System::Drawing::Point(307, 345);
			this->registrationButton->Name = L"registrationButton";
			this->registrationButton->Size = System::Drawing::Size(157, 61);
			this->registrationButton->TabIndex = 5;
			this->registrationButton->Text = L"Зареєструватися";
			this->registrationButton->UseVisualStyleBackColor = true;
			this->registrationButton->Click += gcnew System::EventHandler(this, &MyForm::registrationButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(798, 520);
			this->Controls->Add(this->registrationButton);
			this->Controls->Add(this->loginButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->passwordTextBox);
			this->Controls->Add(this->loginTextBox);
			this->Name = L"MyForm";
			this->Text = L"zxc";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void folderBrowserDialog1_HelpRequest(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void webBrowser1_DocumentCompleted(System::Object^ sender, System::Windows::Forms::WebBrowserDocumentCompletedEventArgs^ e) {
	}


	private: Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		
		String^ login = MyForm::loginTextBox->Text;
		String^ password = MyForm::passwordTextBox->Text;
		Serialization^ serialization = gcnew Serialization();
		if (serialization->findUser(login, password))
		{
			MainForm^ form = gcnew MainForm(login);

			form->Show();
			//this->Close();
			this->Hide();
		}
		
		else
		{
			String^ messagebox = "incorrect password or login.";
			MessageBox::Show(messagebox);
		}
		

	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void registrationButton_Click(System::Object^ sender, System::EventArgs^ e) {
		registration^ f2 = gcnew registration();
		f2->Show();
	}
	};
}
