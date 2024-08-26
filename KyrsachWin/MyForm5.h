#pragma once
#include "_salary.h"
#include "_employee.h"

namespace KyrsachWin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using System::Collections::Generic::List;
	/// <summary>
	/// Сводка для MyForm5
	/// </summary>
	public ref class MyForm5 : public System::Windows::Forms::Form
	{
	public:
		MyForm5(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		List <_salary^>^ get_salaries()
		{
			return salaries;
		}


		MyForm5(_employee^ empe)
		{
			InitializeComponent();
			isEdit = true;
			this->empe = empe;

			for (int i = 0; i < empe->get_salary()->Count; i++)
			{
				dataGridView1->Rows->Add();
				//dataGridView1->Rows[i]->Cells[0]->Value = empe->get_salary();

				if (dynamic_cast<FOP^>(empe->get_salary()[i]) != nullptr) {
					dataGridView1->Rows[i]->Cells[0]->Value = "ФОП(Фізична Особа Підприємець)";
				}
				else if (dynamic_cast<government^>(empe->get_salary()[i]) != nullptr) {
					dataGridView1->Rows[i]->Cells[0]->Value = "Держслужбовець";
				}
				else if (dynamic_cast<pension^>(empe->get_salary()[i]) != nullptr) {
					dataGridView1->Rows[i]->Cells[0]->Value = "Пенсія";
				}
				else if (dynamic_cast<free_lancer^>(empe->get_salary()[i]) != nullptr) {
					dataGridView1->Rows[i]->Cells[0]->Value = "Найманий працівник";
				}

				dataGridView1->Rows[i]->Cells[1]->Value = empe->get_salary()[i]->get_money();
				dataGridView1->Rows[i]->Cells[2]->Value = empe->get_salary()[i]->get_bonus();
				dataGridView1->Rows[i]->Cells[3]->Value = empe->get_salary()[i]->get_salary();
			}
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm5()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:



	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;





	protected:

		_employee^ empe;
		bool isEdit = false;

		List<_salary^>^ salaries = gcnew List<_salary^>();



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1,
					this->Column2, this->Column4, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 32);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(524, 143);
			this->dataGridView1->TabIndex = 0;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Вид ";
			this->Column1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Пенсія", L"ФОП (Фізична Особа Підприємець)", L"Найманий працівник",
					L"Держслужбовець"
			});
			this->Column1->Name = L"Column1";
			this->Column1->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->Column1->Width = 175;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Зарплатня";
			this->Column2->Name = L"Column2";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Премія";
			this->Column4->Name = L"Column4";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Результат";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(12, 185);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 33);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Зберегти";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm5::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(431, 185);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(105, 33);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Порахувати";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm5::button2_Click);
			// 
			// MyForm5
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(540, 231);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm5";
			this->Text = L"salary";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ info = "";
		for (int i = 0; i < dataGridView1->RowCount; i++)
		{
			if (dataGridView1->Rows[i]->Cells[0]->Value == nullptr) 
			{
				break;
			}
			if (dataGridView1->Rows[i]->Cells[1]->Value == nullptr)
			{
				break;
			}
			float bonus=0;
			if (dataGridView1->Rows[i]->Cells[2]->Value != nullptr)
			{
				bonus = FLOAT::Parse(dataGridView1->Rows[i]->Cells[2]->Value->ToString());
			}
			float value = FLOAT::Parse(dataGridView1->Rows[i]->Cells[1]->Value->ToString());
			
			String^ people = dataGridView1->Rows[i]->Cells[0]->Value->ToString();
			_salary^ sal=nullptr;
			if (people == "Пенсія")
			{
				sal = gcnew pension(value, bonus);
				//info+=""
				
			}
			else if (people == "ФОП (Фізична Особа Підприємець)")
			{
				sal = gcnew FOP(value, bonus);
			}
			else if (people == "Найманий працівник")
			{
				sal = gcnew free_lancer(value, bonus);
			}
			else if (people == "Держслужбовець")
			{
				sal = gcnew government(value, bonus);
			}
			if (sal != nullptr) {
				dataGridView1->Rows[i]->Cells[3]->Value = sal->get_salary();
			//	dataGridView1[i][3]->Value = sal->get_salary();
				
			}
		}
		MessageBox::Show("The results are shown with duty");

	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < dataGridView1->RowCount; i++)
	{
		if (dataGridView1->Rows[i]->Cells[0]->Value == nullptr)
		{
			break;
		}
		if (dataGridView1->Rows[i]->Cells[1]->Value == nullptr)
		{
			break;
		}

		float value = FLOAT::Parse(dataGridView1->Rows[i]->Cells[1]->Value->ToString());
		float bonus = FLOAT::Parse(dataGridView1->Rows[i]->Cells[2]->Value->ToString());
		String^ people = dataGridView1->Rows[i]->Cells[0]->Value->ToString();
		_salary^ sal = nullptr;
		if (people == "Пенсія")
		{
			sal = gcnew pension(value, bonus);
			//info+=""

		}
		else if (people == "ФОП(Фізична Особа Підприємець)")
		{
			sal = gcnew FOP(value, bonus);
		}
		else if (people == "Найманий працівник")
		{
			sal = gcnew free_lancer(value, bonus);
		}
		else if (people == "Держслужбовець")
		{
			sal = gcnew government(value, bonus);
		}
		if (sal != nullptr) {
			salaries->Add(sal);
		}

	}
	//Dispose();
	Close();
}
};
}
