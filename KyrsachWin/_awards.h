#pragma once
#include "library.h"
//using namespace std;

ref class _awards
{
protected:
	/*vector<String^> gramota;
	vector<String^> medal;
	vector<String^> gratitude;*/
	String^ name_awards;
	String^ gifter;
	String^ date;
	String^ signature;
public:

	_awards();

	_awards(String^ name_awards_,  String^ gifter_,  String^ date_,  String^ signature_);

	_awards(_awards^ other);

	//virtual void _info();
	//virtual void  input() = 0;


	//virtual ~_awards();

	virtual  String^ get_name_awards() ;
	virtual  String^ get_gifter() ;

	virtual  String^ get_date() ;
	virtual  String^ get_signature() ;

	//virtual  String^ get_merit() {}
	//virtual  String^ get_merit() = 0;

	//virtual bool get_participant_in_hostilities(){}
	//virtual bool get_participant_in_hostilities() = 0;

	//virtual  String^ get_course() {}
	//virtual  String^ get_course()  = 0;
	virtual double getAwardValuE() = 0;


};


//Ô≥‰ ÍÎ‡Ò
ref class medal : public _awards {
private:
	String^ merit;
	//”¡ƒ
	bool participant_in_hostilities;

public:
	medal();

	medal( String^ merit_, bool participant_in_hostilities_,  String^ name_awards_,  String^ gifter_,
		 String^ date_,  String^ signature_);

	medal(medal^ other);

	//virtual void _info() override;

	//virtual void input() override;

	virtual  String^ get_merit();

	virtual bool get_participant_in_hostilities();

	virtual double getAwardValuE() override;
};

ref class gratitude :public _awards {
private:
	String^ course;
public:
	gratitude();

	gratitude( String^ course_,  String^ merit_, bool participant_in_hostilities_,  String^ name_awards_,  String^ gifter_,
		 String^ date_,  String^ signature_);

	gratitude(gratitude^ other);

	//virtual void _info() override;

	//virtual void input() override;

	virtual double getAwardValuE() override;

	virtual  String^ get_course() ;
};
