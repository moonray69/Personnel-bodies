#pragma once
#include "library.h"

ref class _vacation
{
protected:

	int day_duration;
	String^ date;
	String^ period;
	String^ order;

public:

	_vacation();

	_vacation(int day_duration_, String^ date_, String^ period_, String^ order_);

	_vacation( _vacation^ other);

	virtual int get_day_duration();

	virtual  String^ get_disease() = 0;

	virtual float get_payment() = 0;

	virtual String^ get_date();

	virtual String^ get_period();

	virtual String^ get_order();
};

ref class payed_vacation :public _vacation
{
	float payment;
public:

	payed_vacation();

	payed_vacation(float payment_, int day_duration, String^ date, String^ period, String^ order);

	payed_vacation( payed_vacation^ other);


	float get_payment() override;
	String^ get_disease() override;
};

ref class unpayed_vacation : public _vacation
{
public:
	unpayed_vacation() :_vacation() {}
	unpayed_vacation(int day_duration_, String^ date_, String^ period_, String^ order_) : _vacation(day_duration_, date_,  period_,  order_) {}
	unpayed_vacation(unpayed_vacation^ other) {}
	float get_payment() override;
	String^ get_disease() override;
};

ref class sick_leave : public payed_vacation
{
	String^ disease;
public:

	sick_leave();

	sick_leave(String^ disease_, float payment, int day_duration, String^ date, String^ period, String^ order);

	sick_leave(sick_leave^ other);

	 String^ get_disease() override;
	
};
