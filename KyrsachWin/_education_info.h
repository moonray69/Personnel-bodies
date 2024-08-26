#pragma once
#include"library.h"

ref class _education_info
{
private:
	String^ name;
	String^ education_level;
	String^ diplom;
	String^ graduation_year;
	String^ science;

public:

	_education_info();

	_education_info(String^ name_, String^ education_level_,
		String^ diplom_,
		String^ graduation_year_,
		String^ science_);

	_education_info(const _education_info^ other);

	String^ get_name();

	String^ get_education_level();

	String^ get_diploma();

	String^ get_graduation_year();

	String^ get_science();

};

