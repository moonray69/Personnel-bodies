#pragma once
#include "Serialization.h"
#include "_work.h"
#include "family_status.h"
#include "MyForm3.h"
#include "MyForm2.h"
#include "MyForm4.h"
#include "_education_info.h"
#include "_education_two_form.h"
//#include <msclr/marshal_cppstd.h>
namespace KyrsachWin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			
			//
			//TODO: добавьте код конструктора
			//
		}

		MyForm1(_employee^ emp) {
			InitializeComponent();
			isEdit = true;
			this->emp = emp;

			//passport
			nameTextBox->Text = emp->get_passport_inf()->get_name();
			surnameTextBox->Text = emp->get_passport_inf()->get_surname();
			patronumicTextBox->Text = emp->get_passport_inf()->get_patronymic();
			residentialTextBox->Text = emp->get_passport_inf()->get_adres();
			sexTextBox->Text = emp->get_passport_inf()->get_sex();
			nationalityTextBox->Text = emp->get_passport_inf()->get_nationality();
			familystatusTextBox->Text = emp->get_passport_inf()->get_family_status();
			dateofbirthdayTextBox->Text = emp->get_passport_inf()->get_date_of_birthday();
			ipnTextBox->Text = emp->get_passport_inf()->get_ipn();

			//work
			lastplaceworkTextBox18->Text = emp->get_work()->get_last_place_of_work();
			positionTextBox17->Text = emp->get_work()->get_position();
			Work_experienceTextBox16->Text = emp->get_work()->get_Work_experience();
			Date_and_reasons_for_dismissalTextBox15->Text = emp->get_work()->get_Date_and_reasons_for_dismissal();
			textBox1->Text = emp->get_work()->get_news_about_the_withdrawal_of_pensions();
			news_about_the_withdrawa_of_pensionsTextBox14->Text = emp->get_work()->get_news_about_the_withdrawal_of_pensions();
			place_of_actual_residenceTextBox11->Text = emp->get_work()->get_place_of_actual_residence();
			place_of_residence_according_to_state_registrationTextBox10->Text = emp->get_work()->get_place_of_residence_according_to_state_registration();
			workExperienceTextBox2->Text = emp->get_work()->get_work_experienc_date();


			//family
			if (emp->get_family()->get_family_stats() == "Married")
			{
				familyStatusComboBox->SelectedItem = familyStatusComboBox->Items[0];
				
			}
			else if (emp->get_family()->get_family_stats() == "Divorced")
			{
				familyStatusComboBox->SelectedItem = familyStatusComboBox->Items[1];
			}
			else if (emp->get_family()->get_family_stats() =="Not married" )
			{
				familyStatusComboBox->SelectedItem = familyStatusComboBox->Items[2];
			}

			for (int i = 0; i < emp->get_family()->get_family_members()->Count; i++)
			{
				familyDataGridView->Rows->Add();
			
				
					if (emp->get_family()->get_family_members()[i]->get_level_relatives() == "husband") {
						familyDataGridView->Rows[i]->Cells[0]->Value = "Чоловік";
					}
					else if (emp->get_family()->get_family_members()[i]->get_level_relatives() == "wife")
					{
						familyDataGridView->Rows[i]->Cells[0]->Value = "Дружина";
					}
					else if (emp->get_family()->get_family_members()[i]->get_level_relatives() == "son")
					{
						familyDataGridView->Rows[i]->Cells[0]->Value = "Син";
					}
					else if (emp->get_family()->get_family_members()[i]->get_level_relatives() == "daughter")
					{
						familyDataGridView->Rows[i]->Cells[0]->Value = "Донька";
					}
					familyDataGridView->Rows[i]->Cells[1]->Value = emp->get_family()->get_family_members()[i]->get_PIB();
					familyDataGridView->Rows[i]->Cells[2]->Value = emp->get_family()->get_family_members()[i]->get_date_of_birthday();

			}

			if(emp->get_family()->get_family_stats()->Equals(""))
			familyStatusComboBox->SelectedItem = emp->get_family()->get_family_stats();

			//education
			for (int i = 0; i < emp->get_education()->get_list()->Count; i++)
			{
				dataGridView2->Rows->Add();
				dataGridView2->Rows[i]->Cells[0]->Value = emp->get_education()->get_list()[i]->get_name();
				//dataGridView2->Rows[i]->Cells[1]->Value = emp->get_education()->get_list()[i]->get_name();
				dataGridView2->Rows[i]->Cells[2]->Value = emp->get_education()->get_list()[i]->get_diploma();
				dataGridView2->Rows[i]->Cells[3]->Value = emp->get_education()->get_list()[i]->get_graduation_year();
				dataGridView2->Rows[i]->Cells[4]->Value = emp->get_education()->get_list()[i]->get_science();
				
				if (emp->get_education()->get_list()[i]->get_education_level() == "The average is incomplete") {
					dataGridView2->Rows[i]->Cells[1]->Value = "Середня неповна";
				}
				else if (emp->get_education()->get_list()[i]->get_education_level() == "Medium full") {
					dataGridView2->Rows[i]->Cells[1]->Value = "Середня повна";
				}
				else if (emp->get_education()->get_list()[i]->get_education_level() == "Magistracy" ) {
					dataGridView2->Rows[i]->Cells[1]->Value = "Магістратура" ;
				}
				else if (emp->get_education()->get_list()[i]->get_education_level() == "Higher education (bachelor's degree)") {
					dataGridView2->Rows[i]->Cells[1]->Value = "Вища освіта(бакалавр)";
				}
				else if (emp->get_education()->get_list()[i]->get_education_level() == "Complete general education") {
					dataGridView2->Rows[i]->Cells[1]->Value = "Повна загальна освіта";
				}
			}
			
		}
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	public:

	protected:
		_employee^ emp;
		bool isEdit = false;
		List<_certificate^>^ certificates = gcnew List<_certificate^>();
		military_registration^ military = gcnew military_registration();
		_education_two_form^ two = gcnew _education_two_form();
		Health^ health = gcnew Health();
		List<_vacation^>^ vac = gcnew List<_vacation^>();
	private: System::Windows::Forms::TextBox^ residentialTextBox;
	protected:
	private: System::Windows::Forms::Label^ label6;
		   List <_salary^>^ sal = gcnew List <_salary^>();
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
#pragma region Variables



	private: System::Windows::Forms::TextBox^ nationalityTextBox;
	protected:

	private: System::Windows::Forms::TextBox^ sexTextBox;
	protected:



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::TextBox^ patronumicTextBox;

	private: System::Windows::Forms::TextBox^ nameTextBox;

	private: System::Windows::Forms::TextBox^ surnameTextBox;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ ipnTextBox;
	private: System::Windows::Forms::TextBox^ dateofbirthdayTextBox;
	private: System::Windows::Forms::TextBox^ familystatusTextBox;




	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;

	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ place_of_residence_according_to_state_registrationTextBox10;

	private: System::Windows::Forms::TextBox^ place_of_actual_residenceTextBox11;


	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;


	private: System::Windows::Forms::TextBox^ news_about_the_withdrawa_of_pensionsTextBox14;

	private: System::Windows::Forms::TextBox^ Date_and_reasons_for_dismissalTextBox15;


	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::TextBox^ Work_experienceTextBox16;

	private: System::Windows::Forms::TextBox^ positionTextBox17;


	private: System::Windows::Forms::TextBox^ lastplaceworkTextBox18;

	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::DataGridView^ familyDataGridView;




	private: System::Windows::Forms::Label^ statusFamily;
	private: System::Windows::Forms::DataGridView^ dataGridView2;







	private: System::Windows::Forms::Label^ label19;

	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker2;
	private: System::Windows::Forms::Button^ button1;







	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ workExperienceTextBox2;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NameUN;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ EducationalLevel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ diploma;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ graduation_year;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ science;



	private: System::Windows::Forms::ComboBox^ familyStatusComboBox;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ family;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PIB;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DateOfBirthday;
private: System::Windows::Forms::Button^ button2;
#pragma endregion
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
			this->nationalityTextBox = (gcnew System::Windows::Forms::TextBox());
			this->sexTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->patronumicTextBox = (gcnew System::Windows::Forms::TextBox());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->surnameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ipnTextBox = (gcnew System::Windows::Forms::TextBox());
			this->dateofbirthdayTextBox = (gcnew System::Windows::Forms::TextBox());
			this->familystatusTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->place_of_residence_according_to_state_registrationTextBox10 = (gcnew System::Windows::Forms::TextBox());
			this->place_of_actual_residenceTextBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->news_about_the_withdrawa_of_pensionsTextBox14 = (gcnew System::Windows::Forms::TextBox());
			this->Date_and_reasons_for_dismissalTextBox15 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->Work_experienceTextBox16 = (gcnew System::Windows::Forms::TextBox());
			this->positionTextBox17 = (gcnew System::Windows::Forms::TextBox());
			this->lastplaceworkTextBox18 = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->familyDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->family = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->PIB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DateOfBirthday = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->statusFamily = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->NameUN = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EducationalLevel = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->diploma = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->graduation_year = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->science = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->workExperienceTextBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->familyStatusComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->residentialTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->familyDataGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// nationalityTextBox
			// 
			this->nationalityTextBox->Location = System::Drawing::Point(271, 199);
			this->nationalityTextBox->Name = L"nationalityTextBox";
			this->nationalityTextBox->Size = System::Drawing::Size(181, 20);
			this->nationalityTextBox->TabIndex = 23;
			// 
			// sexTextBox
			// 
			this->sexTextBox->Location = System::Drawing::Point(271, 144);
			this->sexTextBox->Name = L"sexTextBox";
			this->sexTextBox->Size = System::Drawing::Size(181, 20);
			this->sexTextBox->TabIndex = 22;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(268, 183);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(83, 13);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Громадянство:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(268, 128);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 13);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Стать:";
			// 
			// patronumicTextBox
			// 
			this->patronumicTextBox->Location = System::Drawing::Point(32, 199);
			this->patronumicTextBox->Name = L"patronumicTextBox";
			this->patronumicTextBox->Size = System::Drawing::Size(176, 20);
			this->patronumicTextBox->TabIndex = 17;
			// 
			// nameTextBox
			// 
			this->nameTextBox->Location = System::Drawing::Point(32, 144);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(176, 20);
			this->nameTextBox->TabIndex = 16;
			// 
			// surnameTextBox
			// 
			this->surnameTextBox->Location = System::Drawing::Point(32, 96);
			this->surnameTextBox->Name = L"surnameTextBox";
			this->surnameTextBox->Size = System::Drawing::Size(176, 20);
			this->surnameTextBox->TabIndex = 15;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(29, 183);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"По батькові:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 128);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Ім\'я:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(29, 80);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 13);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Прізвище:";
			// 
			// ipnTextBox
			// 
			this->ipnTextBox->Location = System::Drawing::Point(507, 199);
			this->ipnTextBox->Name = L"ipnTextBox";
			this->ipnTextBox->Size = System::Drawing::Size(193, 20);
			this->ipnTextBox->TabIndex = 29;
			// 
			// dateofbirthdayTextBox
			// 
			this->dateofbirthdayTextBox->Location = System::Drawing::Point(507, 144);
			this->dateofbirthdayTextBox->Name = L"dateofbirthdayTextBox";
			this->dateofbirthdayTextBox->Size = System::Drawing::Size(193, 20);
			this->dateofbirthdayTextBox->TabIndex = 28;
			// 
			// familystatusTextBox
			// 
			this->familystatusTextBox->Location = System::Drawing::Point(507, 96);
			this->familystatusTextBox->Name = L"familystatusTextBox";
			this->familystatusTextBox->Size = System::Drawing::Size(193, 20);
			this->familystatusTextBox->TabIndex = 27;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(504, 183);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(29, 13);
			this->label7->TabIndex = 26;
			this->label7->Text = L"ІПН:";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm1::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(504, 128);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(101, 13);
			this->label8->TabIndex = 25;
			this->label8->Text = L"Дата народження:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(504, 80);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(83, 13);
			this->label9->TabIndex = 24;
			this->label9->Text = L"Сімейний стан:";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label28->Location = System::Drawing::Point(29, 55);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(146, 16);
			this->label28->TabIndex = 66;
			this->label28->Text = L"Загальні відомості";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(245, 23);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(288, 20);
			this->label10->TabIndex = 67;
			this->label10->Text = L"ОСОБОВА КАРТКА ПРАЦІВНИКА";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(279, 282);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(194, 20);
			this->label11->TabIndex = 68;
			this->label11->Text = L"ОСВІТА ПРАЦІВНИКА";
			this->label11->Click += gcnew System::EventHandler(this, &MyForm1::label11_Click);
			// 
			// place_of_residence_according_to_state_registrationTextBox10
			// 
			this->place_of_residence_according_to_state_registrationTextBox10->Location = System::Drawing::Point(496, 599);
			this->place_of_residence_according_to_state_registrationTextBox10->Name = L"place_of_residence_according_to_state_registrationTextBox10";
			this->place_of_residence_according_to_state_registrationTextBox10->Size = System::Drawing::Size(243, 20);
			this->place_of_residence_according_to_state_registrationTextBox10->TabIndex = 86;
			// 
			// place_of_actual_residenceTextBox11
			// 
			this->place_of_actual_residenceTextBox11->Location = System::Drawing::Point(496, 544);
			this->place_of_actual_residenceTextBox11->Name = L"place_of_actual_residenceTextBox11";
			this->place_of_actual_residenceTextBox11->Size = System::Drawing::Size(243, 20);
			this->place_of_actual_residenceTextBox11->TabIndex = 85;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(493, 583);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(246, 13);
			this->label12->TabIndex = 83;
			this->label12->Text = L"Місце проживання за державною реєстрацією:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(493, 528);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(166, 13);
			this->label13->TabIndex = 82;
			this->label13->Text = L"Місце фактичного проживання:";
			// 
			// news_about_the_withdrawa_of_pensionsTextBox14
			// 
			this->news_about_the_withdrawa_of_pensionsTextBox14->Location = System::Drawing::Point(264, 655);
			this->news_about_the_withdrawa_of_pensionsTextBox14->Name = L"news_about_the_withdrawa_of_pensionsTextBox14";
			this->news_about_the_withdrawa_of_pensionsTextBox14->Size = System::Drawing::Size(202, 20);
			this->news_about_the_withdrawa_of_pensionsTextBox14->TabIndex = 79;
			this->news_about_the_withdrawa_of_pensionsTextBox14->TextChanged += gcnew System::EventHandler(this, &MyForm1::news_about_the_withdrawa_of_pensionsTextBox14_TextChanged);
			// 
			// Date_and_reasons_for_dismissalTextBox15
			// 
			this->Date_and_reasons_for_dismissalTextBox15->Location = System::Drawing::Point(264, 544);
			this->Date_and_reasons_for_dismissalTextBox15->Name = L"Date_and_reasons_for_dismissalTextBox15";
			this->Date_and_reasons_for_dismissalTextBox15->Size = System::Drawing::Size(202, 20);
			this->Date_and_reasons_for_dismissalTextBox15->TabIndex = 78;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(261, 639);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(155, 13);
			this->label16->TabIndex = 76;
			this->label16->Text = L"Відомості про минулу роботу:";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(261, 528);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(153, 13);
			this->label17->TabIndex = 75;
			this->label17->Text = L"Дата та причини звільнення:";
			// 
			// Work_experienceTextBox16
			// 
			this->Work_experienceTextBox16->Location = System::Drawing::Point(33, 655);
			this->Work_experienceTextBox16->Name = L"Work_experienceTextBox16";
			this->Work_experienceTextBox16->Size = System::Drawing::Size(176, 20);
			this->Work_experienceTextBox16->TabIndex = 74;
			// 
			// positionTextBox17
			// 
			this->positionTextBox17->Location = System::Drawing::Point(32, 598);
			this->positionTextBox17->Name = L"positionTextBox17";
			this->positionTextBox17->Size = System::Drawing::Size(176, 20);
			this->positionTextBox17->TabIndex = 73;
			// 
			// lastplaceworkTextBox18
			// 
			this->lastplaceworkTextBox18->Location = System::Drawing::Point(32, 544);
			this->lastplaceworkTextBox18->Name = L"lastplaceworkTextBox18";
			this->lastplaceworkTextBox18->Size = System::Drawing::Size(176, 20);
			this->lastplaceworkTextBox18->TabIndex = 72;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(30, 639);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(129, 13);
			this->label18->TabIndex = 71;
			this->label18->Text = L"Стаж роботи станом на:";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(29, 583);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(103, 13);
			this->label29->TabIndex = 70;
			this->label29->Text = L"Посада (професія):";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(29, 528);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(122, 13);
			this->label30->TabIndex = 69;
			this->label30->Text = L"Останнє місце роботи:";
			// 
			// familyDataGridView
			// 
			this->familyDataGridView->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->familyDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->familyDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->family,
					this->PIB, this->DateOfBirthday
			});
			this->familyDataGridView->Location = System::Drawing::Point(19, 738);
			this->familyDataGridView->Name = L"familyDataGridView";
			this->familyDataGridView->RowHeadersWidth = 35;
			this->familyDataGridView->Size = System::Drawing::Size(766, 96);
			this->familyDataGridView->TabIndex = 87;
			// 
			// family
			// 
			this->family->HeaderText = L"Ступінь родинного зв\'язку (склад сім\'ї)";
			this->family->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Чоловік", L"Дружина", L"Син", L"Донька" });
			this->family->MinimumWidth = 6;
			this->family->Name = L"family";
			this->family->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->family->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->family->Width = 250;
			// 
			// PIB
			// 
			this->PIB->HeaderText = L"ПІБ";
			this->PIB->MinimumWidth = 6;
			this->PIB->Name = L"PIB";
			this->PIB->Width = 250;
			// 
			// DateOfBirthday
			// 
			this->DateOfBirthday->HeaderText = L"Дата народження";
			this->DateOfBirthday->MinimumWidth = 6;
			this->DateOfBirthday->Name = L"DateOfBirthday";
			this->DateOfBirthday->Width = 150;
			// 
			// statusFamily
			// 
			this->statusFamily->AutoSize = true;
			this->statusFamily->Location = System::Drawing::Point(16, 701);
			this->statusFamily->Name = L"statusFamily";
			this->statusFamily->Size = System::Drawing::Size(103, 13);
			this->statusFamily->TabIndex = 88;
			this->statusFamily->Text = L"10. Родинний стан:";
			// 
			// dataGridView2
			// 
			this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->NameUN,
					this->EducationalLevel, this->diploma, this->graduation_year, this->science
			});
			this->dataGridView2->Location = System::Drawing::Point(19, 342);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->Size = System::Drawing::Size(767, 89);
			this->dataGridView2->TabIndex = 89;
			// 
			// NameUN
			// 
			this->NameUN->HeaderText = L"Назва освітнього закладу";
			this->NameUN->MinimumWidth = 6;
			this->NameUN->Name = L"NameUN";
			this->NameUN->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->NameUN->Width = 200;
			// 
			// EducationalLevel
			// 
			this->EducationalLevel->HeaderText = L"Освіта";
			this->EducationalLevel->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Середня неповна", L"Середня повна", L"Повна загальна освіта",
					L"Вища освіта(бакалавр)", L"Магістратура"
			});
			this->EducationalLevel->MinimumWidth = 6;
			this->EducationalLevel->Name = L"EducationalLevel";
			this->EducationalLevel->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->EducationalLevel->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->EducationalLevel->Width = 125;
			// 
			// diploma
			// 
			this->diploma->HeaderText = L"Диплом (свідоцтво), серія, номер";
			this->diploma->MinimumWidth = 6;
			this->diploma->Name = L"diploma";
			this->diploma->Width = 200;
			// 
			// graduation_year
			// 
			this->graduation_year->HeaderText = L"Рік закінчення";
			this->graduation_year->MinimumWidth = 6;
			this->graduation_year->Name = L"graduation_year";
			this->graduation_year->Width = 125;
			// 
			// science
			// 
			this->science->HeaderText = L"Науковий ступінь, учене звання";
			this->science->MinimumWidth = 6;
			this->science->Name = L"science";
			this->science->Width = 125;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label19->Location = System::Drawing::Point(260, 485);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(276, 20);
			this->label19->TabIndex = 91;
			this->label19->Text = L"ІСТОРІЯ РОБОТИ ПРАЦІВНИКА";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(19, 873);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(147, 59);
			this->button1->TabIndex = 92;
			this->button1->Text = L"Зберегти зміни";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(264, 598);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(202, 20);
			this->textBox1->TabIndex = 94;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(261, 583);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(169, 13);
			this->label14->TabIndex = 93;
			this->label14->Text = L"Відомості про отримання пенсії:";
			// 
			// workExperienceTextBox2
			// 
			this->workExperienceTextBox2->Location = System::Drawing::Point(496, 655);
			this->workExperienceTextBox2->Name = L"workExperienceTextBox2";
			this->workExperienceTextBox2->Size = System::Drawing::Size(243, 20);
			this->workExperienceTextBox2->TabIndex = 96;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(494, 639);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(87, 13);
			this->label15->TabIndex = 95;
			this->label15->Text = L"Робочий досвід:";
			this->label15->Click += gcnew System::EventHandler(this, &MyForm1::label15_Click);
			// 
			// familyStatusComboBox
			// 
			this->familyStatusComboBox->FormattingEnabled = true;
			this->familyStatusComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Одружений(а)", L"Розлучений(а)", L"Не одружений(а)" });
			this->familyStatusComboBox->Location = System::Drawing::Point(116, 698);
			this->familyStatusComboBox->Name = L"familyStatusComboBox";
			this->familyStatusComboBox->Size = System::Drawing::Size(121, 21);
			this->familyStatusComboBox->TabIndex = 97;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(639, 873);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(147, 59);
			this->button2->TabIndex = 98;
			this->button2->Text = L"Портфоліо працівника";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(434, 873);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(147, 59);
			this->button3->TabIndex = 99;
			this->button3->Text = L"Військовий облік";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(233, 873);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(147, 59);
			this->button4->TabIndex = 100;
			this->button4->Text = L"Додаткові відомості";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm1::button4_Click);
			// 
			// residentialTextBox
			// 
			this->residentialTextBox->Location = System::Drawing::Point(271, 96);
			this->residentialTextBox->Name = L"residentialTextBox";
			this->residentialTextBox->Size = System::Drawing::Size(181, 20);
			this->residentialTextBox->TabIndex = 21;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(268, 80);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(112, 13);
			this->label6->TabIndex = 18;
			this->label6->Text = L"Адреса проживання:";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(839, 631);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->familyStatusComboBox);
			this->Controls->Add(this->workExperienceTextBox2);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->statusFamily);
			this->Controls->Add(this->familyDataGridView);
			this->Controls->Add(this->place_of_residence_according_to_state_registrationTextBox10);
			this->Controls->Add(this->place_of_actual_residenceTextBox11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->news_about_the_withdrawa_of_pensionsTextBox14);
			this->Controls->Add(this->Date_and_reasons_for_dismissalTextBox15);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->Work_experienceTextBox16);
			this->Controls->Add(this->positionTextBox17);
			this->Controls->Add(this->lastplaceworkTextBox18);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->ipnTextBox);
			this->Controls->Add(this->dateofbirthdayTextBox);
			this->Controls->Add(this->familystatusTextBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->nationalityTextBox);
			this->Controls->Add(this->sexTextBox);
			this->Controls->Add(this->residentialTextBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->patronumicTextBox);
			this->Controls->Add(this->nameTextBox);
			this->Controls->Add(this->surnameTextBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm1";
			this->Text = L"infoEmloyee";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->familyDataGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Serialization^ print_inf = gcnew Serialization();
		Serialization^ history = gcnew Serialization();
		String^ surname = surnameTextBox->Text;
		String^ name = nameTextBox->Text;
		String^ patronumic = patronumicTextBox->Text;
		String^ sex = sexTextBox->Text;
		String^ date_of_birthday = dateofbirthdayTextBox->Text;
		String^ nationality = nationalityTextBox->Text;
		String^ family_status = familystatusTextBox->Text;
		String^ ipn = ipnTextBox->Text;

		Serialization^ history_work = gcnew Serialization();
		String^ last_place_of_work = lastplaceworkTextBox18->Text;
		String^ position = positionTextBox17->Text;
		String^ work_experienc_dat = Work_experienceTextBox16->Text;
		String^ Date_and_reasons_for_dismissal = Date_and_reasons_for_dismissalTextBox15->Text;
		String^ news_about_the_withdrawa_of_pensions = textBox1->Text;
		String^ information_about_past_work = news_about_the_withdrawa_of_pensionsTextBox14->Text;
		String^ place_of_actual_residence = place_of_actual_residenceTextBox11->Text;
		String^ place_of_residence_according_to_state_registration = place_of_residence_according_to_state_registrationTextBox10->Text;
		String^ Work_experience = workExperienceTextBox2->Text;
		String^ adres = residentialTextBox->Text;
		if (surname == "" || name == "" || patronumic == "" || sex == "" || date_of_birthday == "" || nationality == "" || family_status == ""
			|| last_place_of_work == "" || position == "" || work_experienc_dat == "" || Date_and_reasons_for_dismissal == "" || news_about_the_withdrawa_of_pensions == ""
			|| information_about_past_work == "" || place_of_actual_residence == "" || place_of_residence_according_to_state_registration == "" || Work_experience == "" || adres == "")
		{
			MessageBox::Show("Please enter a valid.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		
			MessageBox::Show("Data employee successfuly included.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
			Passport_data^ data = gcnew Passport_data(family_status, surname, name, patronumic,
				sex, date_of_birthday, nationality, ipn, adres);

			

			_work^ work_inf = gcnew _work(last_place_of_work, position, work_experienc_dat, Date_and_reasons_for_dismissal, news_about_the_withdrawa_of_pensions,
				information_about_past_work, place_of_actual_residence, place_of_residence_according_to_state_registration, Work_experience);

			

		

		List<_education^>^ educations = gcnew List<_education^>();
		String^ incomplete_education = "";
		String^ full_education = "";
		String^ secondary_education = "";
		String^ postgraduate_education = "";
		//магістратура
		String^ magistracy = "";


		List<_education_info^>^ info = gcnew List<_education_info^>();

		for (int i = 0; i < dataGridView2->RowCount; i++) {
			String^ name_of_education;
			if (dataGridView2->Rows[i]->Cells[0]->Value != nullptr) {
				name_of_education = dataGridView2->Rows[i]->Cells[0]->Value->ToString();

			}
			else {
				break;
			}
			String^ education = dataGridView2->Rows[i]->Cells[1]->Value->ToString();
			String^ diploma = dataGridView2->Rows[i]->Cells[2]->Value->ToString();
			String^ year = dataGridView2->Rows[i]->Cells[3]->Value->ToString();
			String^ power = dataGridView2->Rows[i]->Cells[4]->Value->ToString();
			String^ str = "";
			if (education == "Середня неповна") {
				str = "The average is incomplete";
			}
			else if (education == "Середня повна") {
				str = "Medium full";
			}
			else if (education == "Магістратура") {
				str = "Magistracy";
			}
			else if (education == "Вища освіта(бакалавр)") {
				str = "Higher education (bachelor's degree)";
			}
			else if (education == "Повна загальна освіта") {
				str = "Complete general education";
			}
			info->Add(gcnew _education_info(name_of_education, str, diploma, year, power));
		}
		_education^ education = gcnew _education(info);
	

		List<family_member^>^ familys = gcnew List<family_member^>();
		String^ level_relatives = "";
		String^ PIB = "";
		String^ dob = "";



		for (size_t i = 0; i < familyDataGridView->RowCount; i++)
		{
			if (familyDataGridView->Rows[i]->Cells[0]->Value == nullptr|| familyDataGridView->Rows[i]->Cells[1]->Value==nullptr|| familyDataGridView->Rows[i]->Cells[2]->Value==nullptr) {
				break;
			}
			level_relatives = familyDataGridView->Rows[i]->Cells[0]->Value->ToString();
			PIB = familyDataGridView->Rows[i]->Cells[1]->Value->ToString();
			dob = familyDataGridView->Rows[i]->Cells[2]->Value->ToString();
			String^ str = "";
		
			if (level_relatives == "Чоловік") {
				str = "husband";
			}
			else if (level_relatives == "Дружина")
			{
				str = "wife";
			}
			else if (level_relatives == "Син")
			{
				str = "son";
			}
			else if (level_relatives == "Донька")
			{
				str = "daughter";
			}
			family_member^ family_status = gcnew family_member(PIB, dob, str);

			familys->Add(family_status);
		}
		String^ family_stat = familyStatusComboBox->Text;
		String^ star = "";
	
		if (family_stat == "Одружений(а)")
		{
			star = "Married";
		}
		else if (family_stat == "Розлучений(а)")
		{
			star = "Divorced";
		}
		else if (family_stat == "Не одружений(а)")
		{
			star = "Not married";
		}

		Family_status^ stats = gcnew Family_status(star, familys);

		Serialization^ serializer = gcnew Serialization();
		//ed_serializer->save_education(education);

		_employee^ employee = gcnew _employee(data, vac, stats, work_inf, education, military, health, sal, certificates);
		serializer->saveDataemployee(employee);
		Close();
	};

	private: System::Void news_about_the_withdrawa_of_pensionsTextBox14_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if(isEdit)
		{
			MyForm3^ f1 = gcnew MyForm3(emp);
			f1->ShowDialog();
			certificates = f1->get_certificates();
		}
		else
		{
			MyForm3^ f1 = gcnew MyForm3();
			f1->ShowDialog();
			certificates = f1->get_certificates();
		}
	}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if(isEdit)
	{
		MyForm2^ f2 = gcnew MyForm2(emp);
		f2->ShowDialog();
		health = f2->get_Health();
		vac = f2->get_vacation();
		sal = f2->get_salary();
	}
	else
	{
		MyForm2^ f2 = gcnew MyForm2();
		f2->ShowDialog();
		health = f2->get_Health();
		vac = f2->get_vacation();
		sal = f2->get_salary();
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (isEdit) {
		MyForm4^ f4 = gcnew MyForm4(emp->get_military());
		f4->ShowDialog();
		military = f4->get_military();
	}
	else {
		MyForm4^ f4 = gcnew MyForm4();
		f4->ShowDialog();
		military = f4->get_military();
	}
}
private: System::Void label15_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}