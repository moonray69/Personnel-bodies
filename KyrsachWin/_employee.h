#pragma once
#include "library.h"
#include "military_registration.h"
#include "Passport_data.h"
#include "_work.h"
#include "_employee_transfer.h"
#include"Health.h"
#include "_education.h"
#include "_employee_awards.h"
#include "_salary.h"
#include "_vacation.h"
#include "_certificate.h"
#include "family_status.h"

using namespace System;

ref class _employee
{
private:
	Passport_data^ passport_inf;
	List<_vacation^>^ vac;
	_work^ work;
	_education^ education;
	military_registration^ military;
	Health^ health;
	List <_salary^>^ salary;
	List <_certificate^>^ certificates;
	Family_status^ family;

public:

	_employee();

	_employee(_employee^ other);
	_employee(Passport_data^ passport_inf,
		List<_vacation^>^ vac,
		Family_status^ family,
		_work^ work,
		_education^ education,
		military_registration^ military,
		Health^ health,
		List<_salary^>^ salary,
		List <_certificate^>^ certificates);


	float calculate() ;

	Passport_data^ get_passport_inf();

	List<_vacation^>^  get_vacations();

	_work^ get_work();

	_education^ get_education();

	military_registration^ get_military();

	Health^ get_health();

	List<_salary^>^ get_salary();

	List <_certificate^>^ get_certificates();
	
	Family_status^ get_family();
};

