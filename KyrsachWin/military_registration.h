#pragma once
#include "library.h"

ref class military_registration {
private:
	String^ rank;
	String^ position;
	int military_experience;
	bool suitability;

public:

	military_registration();

	military_registration(String^ rank_,  String^ position_, int military_experience_, bool suitability_);

	military_registration(military_registration^ other);

	 String^ get_rank() ;

	 String^ get_position() ;

	int get_military_experience() ;

	bool get_suitability() ;
};




