#include "_salary.h"

float _salary::get_money()
{
    return money;
}

float _salary::get_bonus()
{
    return bonus;
}

_salary::_salary()
{
    money = 0.0;
    bonus = 0.0;
}

_salary::_salary(float money_,  float bonus_)
{
    money = money_;
    bonus = bonus_;
}

_salary::_salary(_salary^ other)
{
    this->money = other->money;
    this->bonus = other->bonus; 
}

_salary::~_salary() {}


float FOP::get_salary() 
{
    return ((money + bonus) * 95) / 100.0;
}

float government::get_salary() 
{
    return ((money + bonus) * 78) / 100.0;
}

float pension::get_salary() 
{
    return ((money + bonus) * 90) / 100.0;
}

float free_lancer::get_salary()
{
    return ((money + bonus) * 80) / 100.0;
}