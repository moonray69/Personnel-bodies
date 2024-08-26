#include "_work.h"

_work::_work() {
	 last_place_of_work = "";

	 position = "";

	 work_experienc_date = "";

	 Date_and_reasons_for_dismissal = "";
	
	 news_about_the_withdrawal_of_pensions = "";

	 information_about_past_work = "";

	 place_of_actual_residence = "";

	 place_of_residence_according_to_state_registration = "";

	 Work_experience = "";
}

_work::_work(String^ last_place_of_work_, String^ position_, String^ work_experienc_date_, String^ Date_and_reasons_for_dismissal_,
	String^ news_about_the_withdrawal_of_pensions_, String^ information_about_past_work_,
	String^ place_of_actual_residence_, String^ place_of_residence_according_to_state_registration_, String^ Work_experience_) 
{
	last_place_of_work = last_place_of_work_;

	position = position_;

	work_experienc_date = work_experienc_date_;

	Date_and_reasons_for_dismissal = Date_and_reasons_for_dismissal_;
	
	news_about_the_withdrawal_of_pensions = news_about_the_withdrawal_of_pensions_;

	information_about_past_work = information_about_past_work_;

	place_of_actual_residence = place_of_actual_residence_;

	place_of_residence_according_to_state_registration = place_of_residence_according_to_state_registration_;

	Work_experience = Work_experience_;

}

_work::_work(_work^ other) {
	this->last_place_of_work = other->last_place_of_work;

	this->position = other->position;

	this->work_experienc_date = other->work_experienc_date;

	this->Date_and_reasons_for_dismissal = other->Date_and_reasons_for_dismissal;

	this->news_about_the_withdrawal_of_pensions = other->news_about_the_withdrawal_of_pensions;

	this->information_about_past_work = other->information_about_past_work;

	this->place_of_actual_residence = other->place_of_actual_residence;

	this->place_of_residence_according_to_state_registration = other->place_of_residence_according_to_state_registration;

	this->Work_experience = other->Work_experience;

}

String^ _work::get_last_place_of_work()
{
	return last_place_of_work;
}

String^ _work::get_position()
{
	return position;
}

String^ _work::get_work_experienc_date()
{
	return work_experienc_date;
}

String^ _work::get_Date_and_reasons_for_dismissal()
{
	return Date_and_reasons_for_dismissal;
}

String^ _work::get_news_about_the_withdrawal_of_pensions()
{
	return news_about_the_withdrawal_of_pensions;
}

String^ _work::get_information_about_past_work()
{
	return information_about_past_work;
}

String^ _work::get_place_of_actual_residence()
{
	return place_of_actual_residence;
}

String^ _work::get_place_of_residence_according_to_state_registration()
{
	return place_of_residence_according_to_state_registration;
}

String^ _work::get_Work_experience()
{
	return Work_experience;
}





