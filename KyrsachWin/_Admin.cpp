#include "_Admin.h"
#include <unordered_map>

_Admin::_Admin() {
	username = "";
	password = "";
	email = "";
	phonenumber = "";
	name = "";
	surname = "";

}

_Admin::_Admin(String^ username_, String^ password_, String^ email_, String^ phonenumber_, String^ name_, String^ surname_) {
	username = username_;
	password = password_;
	email = email_;
	phonenumber = phonenumber_;
	name = name_;
	surname = surname_;
}

_Admin::_Admin( _Admin^ other) {
	this->username = other->username;
	this->password = other->password;
	this->email = other->email;
	this->phonenumber = other->phonenumber;
	this->name = other->name;
	this->surname = other->surname;
}


 String^ _Admin::get_user_name() {
	return username;
}

String^ _Admin::get_name() {
	return name;
}

String^ _Admin::get_surname() {
	return surname;
}

String^ _Admin::get_email() {
	return email;
}

String^ _Admin::get_password() {
	return password;
}

String^ _Admin::get_phone_number() {
	return phonenumber;
}


