#pragma once
#include "library.h"
//#include "MyForm.h"
#include "MyForm1.h"


namespace KyrsachWin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			Serialization serializer;
			List<_employee^>^ employees = serializer.getEmployees();
			/*for(int i )
			dataGridView1->*/
			// set items to dataGridView1 

			for (int i = 0; i < employees->Count; i++)
			{

			}
		}

		MainForm(String^ data)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			//textBox8->Text = data;
			Serialization serializer;
			employees = serializer.getEmployees();
			//List<_employee^>^ employees = gcnew List<_employee^>();
			//employees->Add(gcnew _employee(gcnew Passport_data("gggg", "gggg", "gggg", "ggggg", "ggg", "gggg",
			//	"gggg", "ggg", "ggg"), gcnew List<_vacation^>(), gcnew Family_status(), gcnew _work(), gcnew _education(), gcnew military_registration(), gcnew Health(), gcnew List<_salary^>(), gcnew List<_certificate^>()));
			//
			/*for(int i )
			dataGridView1->*/
			// set items to dataGridView1 

			for (int i = 0; i < employees->Count; i++)
			{
				dataGridView1->Rows->Add();
				dataGridView1->Rows[i]->Cells[0]->Value = employees[i]->get_passport_inf()->get_surname();
				dataGridView1->Rows[i]->Cells[1]->Value = employees[i]->get_passport_inf()->get_name();
				dataGridView1->Rows[i]->Cells[2]->Value = employees[i]->get_passport_inf()->get_patronymic();
				dataGridView1->Rows[i]->Cells[3]->Value = employees[i]->get_passport_inf()->get_adres();
				dataGridView1->Rows[i]->Cells[4]->Value = employees[i]->get_passport_inf()->get_sex();
				dataGridView1->Rows[i]->Cells[5]->Value = employees[i]->get_passport_inf()->get_date_of_birthday();
				
			}
		}
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	public:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ adress;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ sex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ date_of_birthday;

	protected:
		List<_employee^>^ employees;
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

















	private: System::Windows::Forms::DataGridView^ dataGridView1;









	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ regButton;



	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->adress = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->sex = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->date_of_birthday = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->regButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column1,
					this->Column2, this->Column3, this->adress, this->sex, this->date_of_birthday
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 125);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(746, 304);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_CellContentClick);
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_CellDoubleClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Прізвище";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 125;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Ім\'я";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 125;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"По батькові";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 125;
			// 
			// adress
			// 
			this->adress->HeaderText = L"Адреса";
			this->adress->MinimumWidth = 6;
			this->adress->Name = L"adress";
			this->adress->Width = 125;
			// 
			// sex
			// 
			this->sex->HeaderText = L"Стать";
			this->sex->MinimumWidth = 6;
			this->sex->Name = L"sex";
			this->sex->Width = 125;
			// 
			// date_of_birthday
			// 
			this->date_of_birthday->HeaderText = L"Рік народження";
			this->date_of_birthday->MinimumWidth = 6;
			this->date_of_birthday->Name = L"date_of_birthday";
			this->date_of_birthday->Width = 125;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(24, 472);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(165, 48);
			this->button3->TabIndex = 16;
			this->button3->Text = L"Додати новий запис";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(311, 472);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(166, 48);
			this->button4->TabIndex = 18;
			this->button4->Text = L"Список громадян із вищою освітою:";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(592, 472);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(166, 48);
			this->button5->TabIndex = 19;
			this->button5->Text = L"Відобразити всі записи:";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// regButton
			// 
			this->regButton->BackColor = System::Drawing::SystemColors::ControlLight;
			this->regButton->Location = System::Drawing::Point(592, 43);
			this->regButton->Name = L"regButton";
			this->regButton->Size = System::Drawing::Size(166, 48);
			this->regButton->TabIndex = 20;
			this->regButton->Text = L"Створити обліковий запис співробітника";
			this->regButton->UseVisualStyleBackColor = false;
			this->regButton->Click += gcnew System::EventHandler(this, &MainForm::regButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(784, 533);
			this->Controls->Add(this->regButton);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void regButton_Click(System::Object^ sender, System::EventArgs^ e) {

		KyrsachWin::MyForm1^ reg = gcnew MyForm1;

		reg->Show();
	}
	private: System::Void dataGridView1_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		MyForm1^ form = gcnew MyForm1( employees[e->RowIndex]);
		form->ShowDialog();

	}
};
}
