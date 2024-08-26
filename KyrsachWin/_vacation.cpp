#include "_vacation.h"

sick_leave::sick_leave() :payed_vacation()
{
	disease = "";
}

sick_leave::sick_leave( String^ disease_, float payment, int day_duration, String^ date, String^ period, String^ order) : payed_vacation(payment, day_duration, date, period, order)
{
	disease = disease_;
}

sick_leave::sick_leave( sick_leave^ other) : payed_vacation(other)
{
	this->disease = other->disease;
}

 String^ sick_leave::get_disease() 
{
	return disease;
}

payed_vacation::payed_vacation() : _vacation()
{
	payment = 0.0;
}

payed_vacation::payed_vacation(float payment_, int day_duration, String^ date, String^ period, String^ order) : _vacation(day_duration, date, period, order)
{
	payment = payment_;
}

payed_vacation::payed_vacation( payed_vacation^ other) : _vacation(other)
{
	this->payment = other->payment;
}

float payed_vacation::get_payment() 
{
	return payment;
}

String^ payed_vacation::get_disease()
{
	return "";
}

_vacation::_vacation()
{
	day_duration = 0;
	date = "";
	period = "";
	order = "";
}

_vacation::_vacation(int day_duration_, String^ date_, String^ period_, String^ order_)
{
	day_duration = day_duration_;
	date = date_;
	period = period_;
	order = order_;
}

_vacation::_vacation( _vacation^ other)
{
	this->day_duration = other->day_duration;
	this->date = other->date;
	this->period = other->period;
	this->order = other->order;
}

int _vacation::get_day_duration() 
{
	return day_duration;
}

String^ _vacation::get_date()
{
	return date;
}

String^ _vacation::get_period()
{
	return period;
}

String^ _vacation::get_order()
{
	return order;
}

float unpayed_vacation::get_payment()
{
	return 0.0f;
}

String^ unpayed_vacation::get_disease()
{
	return "";
}


