#pragma once
#include "_awards.h"
#include "library.h"
#include <algorithm>
#include <vector>
#include <iostream>
//using namespace std;

using System::Collections::Generic::List;

ref class _employee_awards {
private:
    List <_awards^>^ awardsList;

public:
  //  void input();

    void addAwards(_awards^ award);

    //void displayAwards() ;

    //add new
    float calculateAwards();
    _employee_awards();
    _employee_awards(_employee_awards^ other);

    ~_employee_awards();

    List <_awards^>^ get_awards();
};