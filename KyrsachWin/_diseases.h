#pragma once
#include "library.h"
ref class _diseases
{
private:
	String^ disability_group;
	String^ name;
	String^ type;
public:

	_diseases();
	_diseases(String^ disability_group_,
	String^ name_,
	String^ type_);
	_diseases(const _diseases^ other);

	String^ get_disability_group();
	String^ get_name();
	String^ get_type();
};

