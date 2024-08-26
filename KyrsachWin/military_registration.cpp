#include "military_registration.h"

military_registration::military_registration() {
	rank = "";
	position = "";
	military_experience = 0;
	suitability = true;
}

military_registration::military_registration( String^ rank_,  String^ position_, int military_experience_, bool suitability_) {
	rank = rank_;
	position = position_;
	military_experience = military_experience_;
	suitability = suitability_;
}

military_registration::military_registration(military_registration^ other) {
	this->rank = other->rank;
	this->position = other->position;
	this->military_experience = other->military_experience;
	this->suitability = other->suitability;
}

 String^ military_registration::get_rank() 
{
	return rank;
}

 String^ military_registration::get_position() 
{
	return position;
}

int  military_registration::get_military_experience() 
{
	return military_experience;
}

bool  military_registration::get_suitability() 
{
	return suitability;
}