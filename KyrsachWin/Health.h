#pragma once
#include "library.h"
#include "_diseases.h"

using System::Collections::Generic::List;

ref class Health
{
private:
	String^ state_of_health;
	
	List <_diseases^>^ diseases;
	
	String^ blood_type;

public:

	Health();

	Health( String^ state_of_health_, String^ blood_type_, List<_diseases^>^ diseases_);

	Health( Health^ other);


	/*void add_disability( String^ disability_group);

	void add_hereditary( String^ hereditary_diseases);

	void add_chronic( String^ chronic_diseases);*/

	//bool isDisable();

	 String^ get_state_of_health() ;

	// String^ get_disability_group() ;

	 //String^ get_hereditary_diseases() ;

	// String^ get_chronic_diseases() ;

	 List<_diseases^>^ get_diseases();

	String^ get_blood_type() ;
};



