#pragma once
#include "library.h"

ref class _education_two_form
{
private:
	String^ specialty;
	String^ skill;
	String^ form_of_education;

public:

	_education_two_form();

	_education_two_form(String^ specialty_, String^ skill_, String^ form_of_education_);

	_education_two_form(_education_two_form^ other);

	String^ get_specialty();
	String^ get_skill();
	String^ get_form_of_education();

};

