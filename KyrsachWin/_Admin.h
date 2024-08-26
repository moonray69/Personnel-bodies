#pragma once

using namespace System;

ref class _Admin {
protected:
	String^ username;
	String^ password;
	String^ email;
	String^ phonenumber;
	String^ name;
	String^ surname;

public:

	_Admin();

	_Admin(String^ username_, String^ password_, String^ email_, String^ phonenumber_, String^ name_, String^ surname_);

	_Admin(_Admin^ other);

	 String^ get_user_name();

	 String^ get_name();

	 String^ get_surname();

	 String^ get_email();

	 String^ get_password();

	 String^ get_phone_number();

};

