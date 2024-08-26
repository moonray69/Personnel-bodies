#include "Passport_data.h"


Passport_data::Passport_data() {
	family_status = "";
	surname = "";
	name = "";
	patronymic = "";
	sex = "";
	date_of_birthday = "";
	nationality = "";
	ipn = "";
	adres = "";
}

Passport_data::Passport_data( String^ family_status_,  String^ surname_,  String^ name_,  String^ patronymic_,
	String^ sex_,  String^ date_of_birthday_,  String^ nationality_, String^ ipn_, String^ adres_) {
	family_status = family_status_;
	surname = surname_;
	name = name_;
	patronymic = patronymic_;
	sex = sex_;
	date_of_birthday = date_of_birthday_;
	nationality = nationality_;
	ipn = ipn_;
	adres = adres_;
}

Passport_data::Passport_data(Passport_data^ other) {
	this->family_status = other->family_status;
	this->surname = other->surname;
	this->name = other->name;
	this->patronymic = other->patronymic;
	this->sex = other->sex;
	this->date_of_birthday = other->date_of_birthday;
	this->nationality = other->nationality;
	this->ipn = other->ipn;
	this->adres = other->adres;
}

 String^ Passport_data::get_surname() 
{
	return surname;
}

 String^ Passport_data::get_name() 
{
	return name;
}

 String^ Passport_data::get_patronymic() 
{
	return patronymic;
}

 String^ Passport_data::get_sex() 
{
	return sex;
}

 String^ Passport_data::get_nationality() 
{
	return nationality;
}

 String^ Passport_data::get_family_status() 
{
	return family_status;
}

 String^ Passport_data::get_ipn()
{
	return ipn;
}

 String^ Passport_data::get_adres()
 {
	 return adres;
 }

 String^ Passport_data::get_date_of_birthday() 
{
	return date_of_birthday;
}

