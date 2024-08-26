#pragma once
#include "library.h"

ref class _employee_transfer
{
private:
	String^ date_transfer;
	String^ name_of_the_structural_unit;
	String^ Profession_position;
	String^ Rank_salary;
	String^ The_basis_of_the_order;
	String^ signature;

public:

	_employee_transfer();

	_employee_transfer(String^ date_transfer_,
	String^ name_of_the_structural_unit_,
	String^ Profession_position_,
	String^ Rank_salary_,
	String^ The_basis_of_the_order_,
	String^ signature_);

	_employee_transfer( _employee_transfer^ other);

	String^ _employee_transfer::get_date_transfer();

	String^ _employee_transfer::get_name_of_the_structural_unit();

	String^ _employee_transfer::get_Profession_position();

	String^ _employee_transfer::get_Rank_salary(); 
	
	String^ _employee_transfer::get_The_basis_of_the_order();

	String^ _employee_transfer::get_signature();

};

