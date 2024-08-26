#include "_employee_awards.h"

//void _employee_awards::input() {
//    string str;
//    std::cout << "Введіть ваші нагороди (якщо їх нема натисніть -, приймається грамота або медаль): ";
//    cin.ignore(256, '\n');
//    getline(cin, str);
//    while (str != "-") {
//        if (str == "Медаль") {
//            awardsList.push_back(new medal());
//            awardsList.back()->input();
//        }
//        else if (str == "Грамота") {
//            awardsList.push_back(new gratitude());
//            awardsList.back()->input();
//        }
//        std::cout << "Введіть ваші нагороди (якщо їх нема натисніть -, приймається грамота або медаль): ";
//        getline(cin, str);
//    }
//}

void _employee_awards::addAwards(_awards^ award) {
    awardsList->Add(award);
}
_employee_awards::_employee_awards(){}

//void _employee_awards::displayAwards()  {
//    /*std::cout << "Нагороди або грамоти співробітників: " << std::endl;
//    for (int i = 0; i < awardsList->Count; i++) {
//        awardsList[i]->_info();
//        std::cout << std::endl;
//    }*/
//}

//add new
float _employee_awards::calculateAwards()
{
    double total = 0.0;
    for (int i = 0; i < awardsList->Count; i++)
    {
        total += awardsList[i]->getAwardValuE();
    }
    return total;
}

_employee_awards::_employee_awards(_employee_awards^ other)
{
    this->awardsList = other->awardsList;
}

_employee_awards::~_employee_awards() {
    for (int i = 0; i < awardsList->Count; i++) {
        delete awardsList[i];
    }
    awardsList->Clear();
}

List <_awards^>^ _employee_awards::get_awards()
{
    return awardsList;
}
