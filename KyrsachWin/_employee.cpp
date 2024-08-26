#include "_employee.h"

_employee::_employee() {
	passport_inf = gcnew Passport_data();
	vac = gcnew List<_vacation^>();
	work = gcnew _work();
	education = gcnew _education();
	//employee_awards = gcnew _employee_awards();
	military = gcnew military_registration();
	health = gcnew Health();
	salary = gcnew List<_salary^>();
	family = gcnew Family_status();
}
_employee::_employee(Passport_data^ passport_inf,
	List<_vacation^>^ vac,
	Family_status^ family,
	_work^ work,
	_education^ education,
	//_employee_awards^ employee_awards,
	military_registration^ military,
	Health^ health,
	List<_salary^>^ salary,
	List <_certificate^>^ certificates) {
	this->passport_inf = passport_inf;
	this->vac = vac;
	this->work = work;
	this->education = education;
	//this->employee_awards = employee_awards;
	this->military = military;
	this->health = health;
	this->salary = salary;
	this->certificates = certificates;
	this->family = family;
}
_employee::_employee( _employee^ other) {
	
	passport_inf = other->passport_inf ? gcnew Passport_data(other->passport_inf) : nullptr;
	vac = other->vac ? gcnew List<_vacation^>(other->vac) : nullptr;
	work = other->work ? gcnew _work(other->work) : nullptr;
	education = other->education ? gcnew _education(other->education) : nullptr;
	//employee_awards = other->employee_awards ? gcnew _employee_awards(other->employee_awards) : nullptr;

	military = other->military ? gcnew  military_registration(other->military) : nullptr;
	health = other->health ? gcnew Health(other->health) : nullptr;
	certificates = other->certificates;
	/*if (dynamic_cast<FOP^>(other->salary))
	{
		salary = dynamic_cast<FOP^>(other->salary);
	}
	else if (dynamic_cast<government^>(other->salary))
	{
		salary = dynamic_cast<government^>(other->salary);
	}
	else
	{
		salary = dynamic_cast<pension^>(other->salary);
	}*/
	this->salary = other->salary;
}


float _employee::calculate()  {
	float base_salary = 0;
	/*if (salary)
	{
		base_salary = salary->get_salary();
	}*/

	for (int i = 0; i < salary->Count; i++) {
		base_salary += salary[i]->get_salary();
	}

	/*float award_amount = 0;
	if (employee_awards)
	{
		award_amount = employee_awards->calculateAwards();
	}*/

	float healthy = 0;
	if (health)
	{
		//придумать метод что со втой стадии инвалидности будем доплачивать
		healthy = -pow(base_salary, 0.10f);
	}
	return base_salary + healthy;
}

Passport_data^ _employee::get_passport_inf()
{
	return passport_inf;
}

List<_vacation^>^ _employee::get_vacations()
{
	return vac;
}

_work^ _employee::get_work()
{
	return work;
}

_education^ _employee::get_education()
{
	return education;
}

//_employee_awards^ _employee::get_employee_awards()
//{
//	return employee_awards;
//}

military_registration^ _employee::get_military()
{
	return military;
}

Health^ _employee::get_health()
{
	return health;
}

List<_salary^>^ _employee::get_salary()
{
	return salary;
}

List <_certificate^>^ _employee::get_certificates()
{
	return certificates;
}


Family_status^ _employee::get_family()
{
	return family;
}


