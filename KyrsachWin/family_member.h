#pragma once
#include "library.h"
ref class family_member
{
private:
	String^ PIB;
	String^ date_of_birthday;
	String^ level_relatives;

public:

	family_member();
	family_member(String^ PIB_,
	String^ date_of_birthday_,
	String^ level_relatives_);
	family_member(family_member^ other);


	String^ get_PIB();
	String^ get_date_of_birthday();
	String^ get_level_relatives();
};

