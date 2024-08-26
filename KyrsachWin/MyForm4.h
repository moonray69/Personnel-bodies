#pragma once
#include "military_registration.h"

namespace KyrsachWin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm4
	/// </summary>
	public ref class MyForm4 : public System::Windows::Forms::Form
	{
	public:
		MyForm4(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}
		MyForm4(military_registration^ mil)
		{
			InitializeComponent();
			military = mil;
			pos->Text = mil->get_position();
			milEx->Text = mil->get_military_experience()+"";

			if (mil->get_rank() == "Ordinary")
			{
				comboBox1->SelectedIndex = 0;
			}
			else if (mil->get_rank() == "Corporal")
			{
				comboBox1->SelectedIndex = 1;
			}
			else if (mil->get_rank() == "Junior sergeant")
			{
				comboBox1->SelectedIndex = 2;
			}
			else if (mil->get_rank() == "Sergeant")
			{
				comboBox1->SelectedIndex = 3;
			}
			else if (mil->get_rank() == "������� �������")
			{
				comboBox1->SelectedIndex = 4;
			}
			else if (mil->get_rank() == "Petty officer")
			{
				comboBox1->SelectedIndex = 5;
			}
			else if (mil->get_rank() == "Junior Lieutenant")
			{
				comboBox1->SelectedIndex = 6;
			}
			else if (mil->get_rank() == "Lieutenant")
			{
				comboBox1->SelectedIndex = 7;
			}
			else if (mil->get_rank() == "Senior lieutenant")
			{
				comboBox1->SelectedIndex = 8;
			}
			else if (mil->get_rank() == "Captain")
			{
				comboBox1->SelectedIndex = 9;
			}
			else if (mil->get_rank() == "Major")
			{
				comboBox1->SelectedIndex = 10;
			}
			else if (mil->get_rank() == "Lieutenant colonel")
			{
				comboBox1->SelectedIndex = 11;
			}
			else if (mil->get_rank() == "Colonel")
			{
				comboBox1->SelectedIndex = 12;
			}
		}

		military_registration^ get_military()
		{
			return military;
		}

	protected:
		military_registration^ military = gcnew military_registration();
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm4()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::TextBox^ pos;

	private: System::Windows::Forms::TextBox^ milEx;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button2;


	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->pos = (gcnew System::Windows::Forms::TextBox());
			this->milEx = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(46, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(177, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"³�������� ����";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(59, 98);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(142, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"³������� ������:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm4::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(83, 192);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"������:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(47, 278);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(146, 16);
			this->label4->TabIndex = 3;
			this->label4->Text = L"³�������� �����:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(59, 356);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(103, 16);
			this->label5->TabIndex = 4;
			this->label5->Text = L"����������:";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(66, 385);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(83, 17);
			this->radioButton1->TabIndex = 7;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"���������.";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(66, 408);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(95, 17);
			this->radioButton2->TabIndex = 8;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"�����������.";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// pos
			// 
			this->pos->Location = System::Drawing::Point(62, 211);
			this->pos->Name = L"pos";
			this->pos->Size = System::Drawing::Size(100, 20);
			this->pos->TabIndex = 9;
			// 
			// milEx
			// 
			this->milEx->Location = System::Drawing::Point(62, 297);
			this->milEx->Name = L"milEx";
			this->milEx->Size = System::Drawing::Size(100, 20);
			this->milEx->TabIndex = 11;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(13) {
				L"�������", L"��������", L"�������� �������", L"�������",
					L"������� �������", L"��������", L"�������� ���������", L"���������", L"������� ���������", L"������", L"�����", L"ϳ����������",
					L"���������"
			});
			this->comboBox1->Location = System::Drawing::Point(62, 126);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 12;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(36, 466);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(147, 59);
			this->button2->TabIndex = 100;
			this->button2->Text = L"��������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm4::button2_Click);
			// 
			// MyForm4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(235, 552);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->milEx);
			this->Controls->Add(this->pos);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm4";
			this->Text = L"MyForm4";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ rank = comboBox1->Text;
	String^ position = pos->Text;
	String^ military_experience = milEx->Text;
	bool suitability;
	
	suitability = radioButton1->Checked;
	String^ eng_rank = "";
	if (rank == "�������")
	{
		eng_rank = "Ordinary";
	}
	else if (rank == "��������")
	{
		eng_rank = "Corporal";
	}
	else if (rank == "�������� �������")
	{
		eng_rank = "Junior sergeant";
	}
	else if (rank == "�������")
	{
		eng_rank = "Sergeant";
	}
	else if (rank == "������� �������")
	{
		eng_rank = "Senior sergeant";
	}
	else if (rank == "��������")
	{
		eng_rank = "Petty officer";
	}
	else if (rank == "�������� ���������")
	{
		eng_rank = "Junior Lieutenant";
	}
	else if (rank == "���������")
	{
		eng_rank = "Lieutenant";
	}
	else if (rank == "������� ���������")
	{
		eng_rank = "Senior lieutenant";
	}
	else if (rank == "������")
	{
		eng_rank = "Captain";
	}
	else if (rank == "�����")
	{
		eng_rank = "Major";
	}
	else if (rank == "ϳ����������")
	{
		eng_rank = "Lieutenant colonel";
	}
	else if (rank == "���������")
	{
		eng_rank = "Colonel";
	}
	military = gcnew military_registration(eng_rank, position,  Int32::Parse(military_experience), suitability);
	Close();

}
};
}
