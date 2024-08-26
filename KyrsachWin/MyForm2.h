#pragma once
#include"Health.h"
#include "_diseases.h"
#include "_employee_transfer.h"
#include "_vacation.h"
#include "Serialization.h"
#include "MyForm5.h"

namespace KyrsachWin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		

		MyForm2(_employee^ empe) {
			InitializeComponent();

			isEdite = true;
			this->empe = empe;
			vac = empe->get_vacations();
			health = empe->get_health();
			//health
			textBox1->Text = health->get_state_of_health();
			/*if (mil->get_rank() == "Ordinary")
			{
				comboBox1->SelectedIndex = 0;
			}*/
			if (health->get_blood_type() == "I blood group (Rhesus plus)") {
				comboBox1->SelectedIndex = 0;
			}
			else if (health->get_blood_type() ==  "I blood group (Rhesus minus)") {
				comboBox1->SelectedIndex = 1;
			}
			else if (health->get_blood_type() == "II blood group (Rhesus plus)") {
				comboBox1->SelectedIndex = 2;
			}
			else if (health->get_blood_type() == "II blood group(Rhesus minus)") {
				comboBox1->SelectedIndex = 3;
			}
			else if (health->get_blood_type() == "III blood group (Rhesus plus)") {
				comboBox1->SelectedIndex = 4;
			}
			else if (health->get_blood_type() == "III blood group(Rhesus minus)") {
				comboBox1->SelectedIndex = 5;
			}
			else if (health->get_blood_type() == "IV blood group(Rhesus plus)") {
				comboBox1->SelectedIndex = 6;
			}
			else if (health->get_blood_type() == "IV blood group(Rhesus minus") {
				comboBox1->SelectedIndex = 7;
			}
			for (int i = 0; i < vac->Count; i++)
			{
				dataGridView1->Rows->Add();
				
				if (dynamic_cast<unpayed_vacation^>(vac[i]) != nullptr) {
					dataGridView1->Rows[i]->Cells[0]->Value = "За свій рахунок";
				}
				else if (dynamic_cast<payed_vacation^>(vac[i]) != nullptr) {
					dataGridView1->Rows[i]->Cells[0]->Value = "За рахунок фірми";
				}
				else if (dynamic_cast<sick_leave^>(vac[i]) != nullptr) {
					dataGridView1->Rows[i]->Cells[0]->Value = "Лікарняний";
				}
					
				dataGridView1->Rows[i]->Cells[1]->Value = vac[i]->get_disease();
				dataGridView1->Rows[i]->Cells[2]->Value = vac[i]->get_payment();
				dataGridView1->Rows[i]->Cells[3]->Value = vac[i]->get_period();
				dataGridView1->Rows[i]->Cells[4]->Value = vac[i]->get_day_duration();
				dataGridView1->Rows[i]->Cells[5]->Value = vac[i]->get_date();
				dataGridView1->Rows[i]->Cells[6]->Value = vac[i]->get_order();
			}

		}
		List<_vacation^>^ get_vacation () {
			return vac;
		}

		

		Health^ get_Health()
		{
			return health;
		}
		List<_salary^>^ get_salary()
		{
			return salary;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		/// 
	    _employee^ empe;
		bool isEdite = false;
		Health^ health = gcnew Health();
		List<_vacation^>^ vac = gcnew List<_vacation^> ();
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ Type_of_vacation;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ for_what_period;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ number_of_days;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Datee;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ orderr;
	private: System::Windows::Forms::Button^ button1;

	protected:





		   
		   List<_employee_transfer^>^ employee_transfer = gcnew List<_employee_transfer^>();
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}

		List<_salary^>^ salary = gcnew List<_salary^>();






	private: System::Windows::Forms::Label^ VACATION;
	private: System::Windows::Forms::DataGridView^ dataGridView1;





	private: System::Windows::Forms::Button^ button2;






	private: System::Windows::Forms::Label^ label2;
	//: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;


























	protected:

	protected:

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
			this->VACATION = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Type_of_vacation = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->for_what_period = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->number_of_days = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Datee = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->orderr = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// VACATION
			// 
			this->VACATION->AutoSize = true;
			this->VACATION->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->VACATION->Location = System::Drawing::Point(14, 9);
			this->VACATION->Name = L"VACATION";
			this->VACATION->Size = System::Drawing::Size(96, 16);
			this->VACATION->TabIndex = 91;
			this->VACATION->Text = L"ВІДПУСТКИ:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Type_of_vacation,
					this->Column5, this->Column4, this->for_what_period, this->number_of_days, this->Datee, this->orderr
			});
			this->dataGridView1->Location = System::Drawing::Point(14, 28);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(903, 87);
			this->dataGridView1->TabIndex = 92;
			// 
			// Type_of_vacation
			// 
			this->Type_of_vacation->HeaderText = L"Вид відпустки";
			this->Type_of_vacation->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"За свій рахунок", L"За рахунок фірми",
					L"Лікарняний"
			});
			this->Type_of_vacation->MinimumWidth = 6;
			this->Type_of_vacation->Name = L"Type_of_vacation";
			this->Type_of_vacation->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Type_of_vacation->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->Type_of_vacation->Width = 150;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Хвороба";
			this->Column5->Name = L"Column5";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Надходження";
			this->Column4->Name = L"Column4";
			// 
			// for_what_period
			// 
			this->for_what_period->HeaderText = L"За який період";
			this->for_what_period->MinimumWidth = 6;
			this->for_what_period->Name = L"for_what_period";
			this->for_what_period->Width = 200;
			// 
			// number_of_days
			// 
			this->number_of_days->HeaderText = L"Кількість днів";
			this->number_of_days->MinimumWidth = 6;
			this->number_of_days->Name = L"number_of_days";
			this->number_of_days->Width = 150;
			// 
			// Datee
			// 
			this->Datee->HeaderText = L"Дата";
			this->Datee->MinimumWidth = 6;
			this->Datee->Name = L"Datee";
			this->Datee->Width = 150;
			// 
			// orderr
			// 
			this->orderr->HeaderText = L"Підстава, наказ";
			this->orderr->MinimumWidth = 6;
			this->orderr->Name = L"orderr";
			this->orderr->Width = 145;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(9, 337);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(147, 59);
			this->button2->TabIndex = 99;
			this->button2->Text = L"Зберегти";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm2::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(11, 172);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(98, 16);
			this->label2->TabIndex = 103;
			this->label2->Text = L"Група крові:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"I група крові (Резус плюс)", L"I група крові (Резус мінус)",
					L"II група крові (Резус плюс)", L"II група крові(Резус мінус)", L"III група крові (Резус плюс)", L"III група крові (Резус мінус)",
					L"IV група крові (Резус плюс)", L"IV група крові (Резус мінус)"
			});
			this->comboBox1->Location = System::Drawing::Point(12, 201);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(194, 21);
			this->comboBox1->TabIndex = 105;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(9, 261);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(198, 16);
			this->label3->TabIndex = 106;
			this->label3->Text = L"Загальний стан здоров\'я:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(9, 295);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(310, 20);
			this->textBox1->TabIndex = 107;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(739, 337);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(147, 59);
			this->button1->TabIndex = 108;
			this->button1->Text = L"Внести данні про заробітну платню";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(914, 436);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->VACATION);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ invalid_group;
		String^ Blood;
		String^ blood_type= comboBox1->Text;
		if (blood_type == "I група крові (Резус плюс)") {
			Blood = "I blood group (Rhesus plus)";
		}
		else if (blood_type == "I група крові (Резус мінус)") {
			Blood = "I blood group (Rhesus minus)";
		}
		else if (blood_type == "II група крові (Резус плюс)") {
			Blood = "II blood group (Rhesus plus)";
		}
		else if (blood_type == "II група крові(Резус мінус)") {
			Blood = "II blood group(Rhesus minus)";
		}
		else if (blood_type == "III група крові (Резус плюс)") {
			Blood = "III blood group (Rhesus plus)";
		}
		else if (blood_type == "III blood group (Rhesus minus)III група крові (Резус мінус)") {
			Blood = "III blood group(Rhesus minus)";
		}
		else if (blood_type == "IV група крові (Резус плюс)") {
			Blood = "IV blood group(Rhesus plus)";
		}
		else if (blood_type == "IV група крові (Резус мінус)") {
			Blood = "IV blood group(Rhesus minus";
		}
		else {
			Blood = "undefined";
		}
		String^ disease;
		String^ general_state = textBox1->Text;
		List<_diseases^>^ diseases=gcnew List<_diseases^>();
		//for (int i = 0; i < dataGridView4->RowCount; i++) {
		//	if (dataGridView4->Rows[i]->Cells[0]->Value == nullptr || dataGridView4->Rows[i]->Cells[1]->Value==nullptr|| dataGridView4->Rows[i]->Cells[2]->Value==nullptr) {
		//		break;
		//	}
		//	String^ name_of_diseases = dataGridView4->Rows[i]->Cells[0]->Value->ToString();

		//	String^ type_of_desease = dataGridView4->Rows[i]->Cells[1]->Value->ToString();
		//	String^ disibility_group = dataGridView4->Rows[i]->Cells[2]->Value->ToString();
		//	

		//	String^ str; // "Name of diseases: " + name_of_diseases + "  Diploma: " + diploma + " Year:" + year + " Power:" + power;
		//	if (disibility_group == "Ні") {
		//		invalid_group = "No";
		//	}
		//	else if (disibility_group == "I група інвалідності") {
		//		invalid_group = "I group of disabilities";
		//	}
		//	else if (disibility_group == "II група інвалідності") {
		//		invalid_group = "II group of disabilities";
		//	}
		//	else if (disibility_group == "III група інвалідності") {
		//		invalid_group = "III group of disabilities";
		//	}
		//	else {
		//		invalid_group = str;
		//	}

		//	if (type_of_desease == "Спадкова хвороба") 
		//	{
		//		disease = "Hereditary disease ";
		//	}
		//	else if (type_of_desease == "Хронічна хвороба")
		//	{
		//		disease = "Chronic disease";
		//	}
		//	diseases->Add(gcnew _diseases(invalid_group, name_of_diseases, disease));
		//}

		 health = gcnew Health(general_state,Blood,diseases);
		

		 String^ reason_for_transfer;
		 String^ dis;
		 float payment;
		 String^ period;
		 int days;
		 String^ date;
		 String^ order;
		 for (int i = 0; i < dataGridView1->RowCount; i++)
		 {
			 if (dataGridView1->Rows[i]->Cells[0]->Value == nullptr)
			 {
				 break;
			 }
			 reason_for_transfer = dataGridView1->Rows[i]->Cells[0]->Value->ToString();
			 order = dataGridView1->Rows[i]->Cells[6]->Value->ToString();
			 period = dataGridView1->Rows[i]->Cells[3]->Value->ToString();
			 days = Int32::Parse(dataGridView1->Rows[i]->Cells[4]->Value->ToString());
			 date = dataGridView1->Rows[i]->Cells[5]->Value->ToString();
			 if (reason_for_transfer == "За свій рахунок")
			 {
				 vac->Add(gcnew unpayed_vacation(days, date, period, order));
			 }
			 else if (reason_for_transfer == "За рахунок фірми") {
				 payment = FLOAT::Parse(dataGridView1->Rows[i]->Cells[2]->Value->ToString());
				 vac->Add(gcnew payed_vacation(payment, days, date, period, order));
			 }
			 else if (reason_for_transfer == "Лікарняний") {
				 dis = dataGridView1->Rows[i]->Cells[1]->Value->ToString();
				 payment = FLOAT::Parse(dataGridView1->Rows[i]->Cells[2]->Value->ToString());
				 vac->Add(gcnew sick_leave(dis, payment, days, date, period, order));
			 }
		 }

		 Close();
	}

	//private: void UpdateSalaryGrid() {

	//	// Перебираємо список зарплат і додаємо рядки в таблицю
	//	for (int i = 0; i < salary->Count; i++) {
	//		dataGridView1->Rows->Add();

	//		if (dynamic_cast<FOP^>(salary[i]) != nullptr) {
	//			dataGridView1->Rows[i]->Cells[0]->Value = "ФОП(Фізична Особа Підприємець)";
	//		}
	//		else if (dynamic_cast<government^>(salary[i]) != nullptr) {
	//			dataGridView1->Rows[i]->Cells[0]->Value = "Держслужбовець";
	//		}
	//		else if (dynamic_cast<pension^>(salary[i]) != nullptr) {
	//			dataGridView1->Rows[i]->Cells[0]->Value = "Пенсія";
	//		}
	//		else if (dynamic_cast<free_lancer^>(salary[i]) != nullptr) {
	//			dataGridView1->Rows[i]->Cells[0]->Value = "Найманий працівник";
	//		}

	//		dataGridView1->Rows[i]->Cells[1]->Value = salary[i]->get_money();
	//		dataGridView1->Rows[i]->Cells[2]->Value = salary[i]->get_bonus();
	//		dataGridView1->Rows[i]->Cells[3]->Value = salary[i]->get_salary();
	//	}
	//}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if(isEdite)
	{
		MyForm5^ f5 = gcnew MyForm5(empe);
		f5->ShowDialog();
		salary = f5->get_salaries();
	}
	else
	{
		MyForm5^ f5 = gcnew MyForm5();
		f5->ShowDialog();
		salary = f5->get_salaries();
	}
	//UpdateSalaryGrid();
}

};
}
