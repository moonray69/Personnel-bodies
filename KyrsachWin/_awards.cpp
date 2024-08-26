#include "_awards.h"

_awards::_awards() {
	name_awards = "";
	gifter = "";
	date = "";
	signature = "";
}

_awards::_awards( String^ name_awards_,  String^ gifter_,  String^ date_,  String^ signature_) {
	name_awards = name_awards_;
	gifter = gifter_;
	date = date_;
	signature = signature_;
}

_awards::_awards(_awards^ other) {
	this->name_awards = other->name_awards;
	this->gifter = other->gifter;
	this->date = other->date;
	this->signature = other->signature;
}


//void  _awards::input() {
//	std::cout << "Введіть назву нагороди або грамоти: ";
//	getline(cin, name_awards);
//	std::cout << std::endl;
//	std::cout << "Ким була вручена нагорода або грамота: ";
//	getline(cin, gifter);
//	std::cout << std::endl;
//	std::cout << "Дата видачі нагороди: ";
//	getline(cin, date);
//	std::cout << std::endl;
//	std::cout << "Ваш підпис: ";
//	getline(cin, signature);
//}

 String^ _awards::get_name_awards() 
{
	return name_awards;
}

 String^ _awards::get_gifter() 
{
	return gifter;
}

 String^ _awards::get_date() 
{
	return date;
}

 String^ _awards::get_signature() 
{
	return signature;
}

medal::medal() : _awards() {
	merit = "";
	participant_in_hostilities = false;
}

medal::medal( String^ merit_, bool participant_in_hostilities_,  String^ name_awards_,  String^ gifter_,
	 String^ date_,  String^ signature_) :_awards(name_awards_, gifter_, date_, signature_) {
	merit = merit_;
	participant_in_hostilities = participant_in_hostilities_;
}

medal::medal(medal^ other) : _awards(other) {
	this->merit = other->merit;
	this->participant_in_hostilities = other->participant_in_hostilities;
}



 String^ medal::get_merit() 
{
	return merit;
}

bool medal::get_participant_in_hostilities() 
{
	return participant_in_hostilities;
}

double  medal::getAwardValuE()
{
	return 10.0;
	//пример сколько можно получить за грамоту , хотя дать краба лучше
}

gratitude::gratitude() : _awards() {
	course = "";
}

gratitude::gratitude( String^ course_,  String^ merit_, bool participant_in_hostilities_,  String^ name_awards_,  String^ gifter_,
	 String^ date_,  String^ signature_) :_awards(name_awards_, gifter_, date_, signature_) {
	course = course_;
}
gratitude::gratitude(gratitude^ other) : _awards(other) {
	this->course = other->course;
}

//void  gratitude::_info() {
//
//	std::cout << "21.Назва нагороди: " << name_awards << std::endl;
//	std::cout << "22.Пройдений курс: " << course << std::endl;
//	std::cout << "23.Вручав нагороду: " << gifter << std::endl;
//	std::cout << "24.Дата видачі нагороди: " << date << std::endl;
//	std::cout << "25.Підпис: " << signature << std::endl;
//}

//void  gratitude::input() {
//	_awards::input();
//	std::cout << "Який курс ви пройшли?: ";
//	getline(cin, course);
//	std::cout << std::endl;
//}

double  gratitude::getAwardValuE()
{
	return 50.0;
	//пример сколько можно получить за грамоту , хотя дать краба лучше
}

 String^ gratitude::get_course() 
{
	return course;
}
