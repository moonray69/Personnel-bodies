#pragma once
#include "library.h"

ref class Passport_data
{
private:
	String^ surname;
	String^ name;
	String^ patronymic;
	String^ sex;
	String^ date_of_birthday;
	String^ nationality;
	String^ family_status;
	String^ ipn;
	String^ adres;

public:

	Passport_data();

	Passport_data( String^ family_status_,  String^ surname_,  String^ name_,  String^ patronymic_,
		 String^ sex_,  String^ date_of_birthday_,  String^ nationality_, String^ ipn_, String^ adres_);

	Passport_data(Passport_data^ other);

	 String^ get_surname() ;

	 String^ get_name() ;

	 String^ get_patronymic() ;

	 String^ get_date_of_birthday() ;

	 String^ get_sex() ;

	 String^ get_nationality() ;

	 String^ get_family_status() ;

	 String^ get_ipn() ;

	 String^ get_adres();

};



