#pragma once
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>
#include "_Admin.h"
#include "_employee.h"
#include "family_status.h"
//#include "stdafx.h"
#include <string>
using namespace System;

using json = nlohmann::json;

ref class Serialization {
private:
	json* _data;
	json save_passport_data(Passport_data^ Passport);

	//void save_family_status(Family_status^ family);

	json save_education(_education^ education_);

	json save_military_registration( military_registration^ military);

	json save_health(Health^ health);

	json save_work(_work^ work);

	json save_vacation(List<_vacation^>^ vacation);

	//json save_employee_awards(_employee_awards^ awards);

	json save_employee_certificates(List <_certificate^>^ certificates);

	json save_family_status(Family_status^ family);

	json save_salary(List<_salary^>^ sal);


	Passport_data^ read_passport_data(json Passport);

	_education^ read_education(json education_);

	military_registration^ read_military_registration(json military);

	Health^ read_health(json health);

	List<_diseases^>^ read_diseases(json diseases);

	_work^ read_work(json work);

	List<_vacation^>^ read_vacation(json vacation);

	//json save_employee_awards(_employee_awards^ awards);

	List <_certificate^>^ read_employee_certificates(json certificates);

	Family_status^ read_family_status(json family);

	List<_salary^>^ read_salary(json sal);
	
public:
	List<_employee^>^ getEmployees();
	
	void saveDataUser(_Admin^ admin);

	void saveDataemployee(_employee^ finish);

	void saveDocumentationPackage(long long unsigned int TTN_, int price_);

	bool deleteDocumentationPackage(long long unsigned int TTN_);

	bool checkPhoneNumber(std::string search_phone_number);

	bool findUser(String^ username, String^ password);

	bool checkEmail(std::string search_email);

	std::vector<std::unordered_map<std::string, std::string>> getPackageData(std::string search_phone_number);

	std::unordered_map<std::string, std::string> getUserData(std::string search_email);

	void changeEmail(std::string email_, std::string new_email, std::string check_password);

	void changePassword(std::string email_, std::string password_, std::string new_password);

	bool deletePackage(long long unsigned int TTN);

	std::string getFullName(std::string email_);

	Serialization();
	Serialization(Serialization^ other);
	
};
