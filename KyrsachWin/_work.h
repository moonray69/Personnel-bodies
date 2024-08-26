#pragma once
#include "library.h"
#include "Passport_data.h"


ref class _work
{
private:
	String^ last_place_of_work;

	String^ position;

	String^ work_experienc_date;

	String^ Date_and_reasons_for_dismissal;
	
	String^ news_about_the_withdrawal_of_pensions;

	String^ information_about_past_work;

	String^ place_of_actual_residence;

	String^ place_of_residence_according_to_state_registration;

	String^ Work_experience;


public:

	_work();

	_work(String^ last_place_of_work_,String^ position_,String^ work_experienc_date_,String^ Date_and_reasons_for_dismissal_,
		String^ news_about_the_withdrawal_of_pensions_,String^ information_about_past_work_,
		String^ place_of_actual_residence_,String^ place_of_residence_according_to_state_registration_,String^ Work_experience_ );

	_work(_work^ other);


	 String^ get_last_place_of_work() ;

	 String^ get_position();

	 String^ get_work_experienc_date();

	 String^ get_Date_and_reasons_for_dismissal();

	 String^ get_news_about_the_withdrawal_of_pensions();

	 String^ get_information_about_past_work();

	 String^ get_place_of_actual_residence();

	 String^ get_place_of_residence_according_to_state_registration();

	 String^ get_Work_experience();
};


