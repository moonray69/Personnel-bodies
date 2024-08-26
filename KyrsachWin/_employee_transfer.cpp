#include "_employee_transfer.h"

_employee_transfer::_employee_transfer() {
	date_transfer = "";
	name_of_the_structural_unit = "";
	Profession_position = "";
	Rank_salary = "";
	The_basis_of_the_order = "";
	signature = "";
}

_employee_transfer::_employee_transfer(String^ date_transfer_,
	String^ name_of_the_structural_unit_,
	String^ Profession_position_,
	String^ Rank_salary_,
	String^ The_basis_of_the_order_,
	String^ signature_) {
	date_transfer = date_transfer_;
	name_of_the_structural_unit = name_of_the_structural_unit_;
	Profession_position = Profession_position_;
	Rank_salary = Rank_salary_;
	The_basis_of_the_order = The_basis_of_the_order_;
	signature = signature_;
}

_employee_transfer::_employee_transfer(_employee_transfer^ other) {
	this->date_transfer = other->date_transfer;
	this->name_of_the_structural_unit = other->name_of_the_structural_unit;
	this->Profession_position = other->Profession_position;
	this->Rank_salary = other->Rank_salary;
	this->The_basis_of_the_order = other->The_basis_of_the_order;
	this->signature = other->signature;
}



 String^ _employee_transfer::get_date_transfer()
{
	return date_transfer;
}

 String^ _employee_transfer::get_name_of_the_structural_unit()
{
	return name_of_the_structural_unit;
}

 String^ _employee_transfer::get_Profession_position()
{
	return Profession_position;
}

 String^ _employee_transfer::get_Rank_salary()
 {
	 return Rank_salary;
 }

 String^ _employee_transfer::get_The_basis_of_the_order()
 {
	 return The_basis_of_the_order;
 }

 String^ _employee_transfer::get_signature()
 {
	 return signature;
 }


