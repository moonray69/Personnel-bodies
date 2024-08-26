#pragma once
#include "_certificate.h"
#include "Serialization.h"
namespace KyrsachWin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm3
	/// </summary>
	public ref class MyForm3 : public System::Windows::Forms::Form
	{
	public:
		MyForm3(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		List<_certificate^>^ get_certificates() {
			return educations;
		}

		MyForm3(_employee^ emps)
		{
			InitializeComponent();
			isEdit = true;
			this->emps = emps;

			for (int i = 0; i < emps->get_certificates()->Count; i++)
			{
				dataGridView2->Rows->Add();

				_certificate^ cert = emps->get_certificates()[i];
				
				dataGridView2->Rows[i]->Cells[0]->Value = cert->get_the_name_of_the_certificate();
				dataGridView2->Rows[i]->Cells[1]->Value = cert->get_Date_of_receiving_the_certificate();
				dataGridView2->Rows[i]->Cells[2]->Value = cert->get_points();
				dataGridView2->Rows[i]->Cells[3]->Value = cert->get_location();

			}
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		List<_certificate^>^ educations = gcnew List<_certificate^>();
		~MyForm3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::DataGridView^ dataGridView2;





	private: System::Windows::Forms::Button^ saveInf;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name_Sert;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ take_sert;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ points;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ loca;









	protected:
		_employee^ emps;
		bool isEdit = false;
		_certificate^ certificat = gcnew _certificate();
	protected:
	private: System::ComponentModel::IContainer^ components;

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
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->saveInf = (gcnew System::Windows::Forms::Button());
			this->name_Sert = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->take_sert = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->points = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->loca = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(285, 19);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(117, 20);
			this->label10->TabIndex = 68;
			this->label10->Text = L"ПОРТФОЛІО";
			this->label10->Click += gcnew System::EventHandler(this, &MyForm3::label10_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->name_Sert,
					this->take_sert, this->points, this->loca
			});
			this->dataGridView2->Location = System::Drawing::Point(0, 42);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(761, 87);
			this->dataGridView2->TabIndex = 91;
			// 
			// saveInf
			// 
			this->saveInf->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->saveInf->Location = System::Drawing::Point(12, 145);
			this->saveInf->Name = L"saveInf";
			this->saveInf->Size = System::Drawing::Size(142, 55);
			this->saveInf->TabIndex = 92;
			this->saveInf->Text = L"Зберегти";
			this->saveInf->UseVisualStyleBackColor = true;
			this->saveInf->Click += gcnew System::EventHandler(this, &MyForm3::saveInf_Click);
			// 
			// name_Sert
			// 
			this->name_Sert->HeaderText = L"Назва сертифікату";
			this->name_Sert->Name = L"name_Sert";
			this->name_Sert->Width = 200;
			// 
			// take_sert
			// 
			this->take_sert->HeaderText = L"Дата отримання сертифікату";
			this->take_sert->Name = L"take_sert";
			this->take_sert->Width = 200;
			// 
			// points
			// 
			this->points->HeaderText = L"Кількість балів";
			this->points->Name = L"points";
			this->points->Width = 170;
			// 
			// loca
			// 
			this->loca->HeaderText = L"Місце проведення";
			this->loca->Name = L"loca";
			this->loca->Width = 200;
			// 
			// MyForm3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(763, 212);
			this->Controls->Add(this->saveInf);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->label10);
			this->Name = L"MyForm3";
			this->Text = L"MyForm3";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void saveInf_Click(System::Object^ sender, System::EventArgs^ e) {
	
	String^ the_name_of_the_certificate = "";
	String^ Date_of_receiving_the_certificate = "";
	String^ points = "";

	for (int i = 0; i < dataGridView2->RowCount; i++)
	{
		if (dataGridView2->Rows[i]->Cells[0]->Value == nullptr || dataGridView2->Rows[i]->Cells[1]->Value == nullptr || dataGridView2->Rows[i]->Cells[2]->Value == nullptr || dataGridView2->Rows[i]->Cells[3]->Value == nullptr)
		{
			break;
		}
		String^ the_name_of_the_certificate = dataGridView2->Rows[i]->Cells[0]->Value->ToString();
		String^ Date_of_receiving_the_certificate = dataGridView2->Rows[i]->Cells[1]->Value->ToString();
		String^ points = dataGridView2->Rows[i]->Cells[2]->Value->ToString();
		String^ location = dataGridView2->Rows[i]->Cells[3]->Value->ToString();
		
		_certificate^ certificat = gcnew _certificate(the_name_of_the_certificate, Date_of_receiving_the_certificate, points, location);
		
		educations->Add(certificat);
	}
	Close();
}
};
}
