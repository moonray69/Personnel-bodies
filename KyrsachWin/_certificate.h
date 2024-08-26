#pragma once
#include "library.h"
ref class _certificate
{
private:
	String^ name;
	String^ Date_of_receiving;
	String^ points;
	String^ location;
public:
	_certificate();
	_certificate(String^ name_, String^ Date_of_receiving_, String^ points_, String^ location_);
	_certificate(_certificate^ other);

	String^ get_the_name_of_the_certificate();
	String^ get_Date_of_receiving_the_certificate();
	String^ get_points();
	String^ get_location();
};

