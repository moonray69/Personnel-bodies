#pragma once
#include "library.h"
#include "family_member.h"
using System::Collections::Generic::List;
ref class Family_status
{
private:
	String^ family_stats;
	List <family_member^>^ family_members;

	
public:

	Family_status();

	Family_status(String^ family_stats_, List<family_member^>^ family_members_);

	Family_status(Family_status^ other);

	String^ get_family_stats();

	List <family_member^>^ get_family_members();
};

