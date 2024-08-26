#include "Health.h"

Health::Health() {
	state_of_health = "";
	blood_type = "";
	diseases = gcnew List<_diseases^>();
}

Health::Health( String^ state_of_health_, String^ blood_type_, List<_diseases^>^ diseases_) {
	state_of_health = state_of_health_;
	blood_type = blood_type_;
	diseases = diseases_;
}

Health::Health(Health^ other){
	this->state_of_health = other->state_of_health;
	this->blood_type = other->blood_type;
	this->diseases = other->diseases;
}


//void Health::add_disability(String^ disability_group) {
//	this->disability_group->Add(disability_group);
//
//
//}
//
//void Health::add_hereditary( String^ hereditary_disease) {
//	hereditary_diseases->Add(hereditary_disease);
//}
//
//void Health::add_chronic( String^ chronic_diseases) {
//	this->chronic_diseases->Add(chronic_diseases);
//}


//void Health::print() {
//	cout << "29.Стан здоров'я: " << state_of_health << endl << endl;
//	cout << "30.Група крові: " << blood_type << endl << endl;
//	if (disability_group.size() != 0) {
//		cout << "31.Групи інвалідності: " << endl;
//
//		for (int i = 0; i < disability_group.size(); i++) {
//			cout << "\t" << disability_group[i] << endl;
//		}
//	}
//
//	if (hereditary_diseases.size() != 0) {
//		cout << "32.Спадкові хвороби: " << endl;
//
//		for (int i = 0; i < hereditary_diseases.size(); i++) {
//			cout << "\t" << hereditary_diseases[i] << endl;
//		}
//	}
//
//	if (chronic_diseases.size() != 0) {
//		cout << "33.Хронічні хвороби: " << endl;
//
//		for (int i = 0; i < chronic_diseases.size(); i++) {
//			cout << "\t" << chronic_diseases[i] << endl;
//		}
//	}
//	cout << endl;
//}


//void Health::_input() {
//	cout << "Введіть ваш стан здоров'я: ";
//	cin >> state_of_health;
//	cout << endl;
//	cout << "Введіть вашу групу крові: ";
//	cin >> blood_type;
//	String^ input;
//	cout << "Введіть групи інвалідності (введіть '-' якщо немаєте хвороб): " << endl;
//	while (true) {
//		getline(cin, input);
//		if (input == "-") {
//			break;
//		}
//		if (!input.empty()) add_disability(input);
//	}
//	cout << "Введіть спадкові хвороби (введіть '-' якщо немаєте хвороб): " << endl;
//	while (true) {
//		getline(cin, input);
//		if (input == "-") {
//			break;
//		}
//		if (!input.empty()) add_hereditary(input);
//	}
//	cout << "Введіть хронічні хвороби (введіть '-' якщо немаєте хвороб): " << endl;
//	while (true) {
//		getline(cin, input);
//		if (input == "-") {
//			break;
//		}
//		if (!input.empty()) add_chronic(input);
//	}
//}

//bool Health::isDisable()
//{
//	return !(disability_group->Count == 0);
//}

 String^ Health::get_state_of_health() 
{
	return state_of_health;
}

 /*String^ Health::get_disability_group() 
{
	String^ info;
	for (int i = 0; i < disability_group->Count; i++)
	{
		info += disability_group[i];
		if (i != disability_group->Count - 1)
		{
			info += ", ";
		}
	}
	return info;
}

 String^ Health::get_hereditary_diseases() 
{
	String^ info;
	for (int i = 0; i < hereditary_diseases->Count; i++)
	{
		info += hereditary_diseases[i];
		if (i != hereditary_diseases->Count - 1)
		{
			info += ", ";
		}
	}
	return info;
}

 String^ Health::get_chronic_diseases() 
{
	String^ info;
	for (int i = 0; i < chronic_diseases->Count; i++)
	{
		info += chronic_diseases[i];
		if (i != chronic_diseases->Count - 1)
		{
			info += ", ";
		}
	}
	return info;
}*/

 List<_diseases^>^ Health::get_diseases()
 {
	 return diseases;
 }

 String^ Health::get_blood_type()
{
	return blood_type;
}