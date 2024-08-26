#pragma once
#include "library.h"

ref class _salary
{
protected:
    float money;
    float bonus;

public:
    virtual float get_salary()  = 0;
    virtual float get_money();
    virtual float get_bonus();
    _salary();
    _salary(float money_, float bonus_);
    _salary(_salary^ other);
    virtual ~_salary();
};

ref class FOP : public _salary
{
public:
    virtual float get_salary()  override;
    FOP(float money_, float bonus_):_salary(money_, bonus_){}
};

ref class government : public _salary
{
public:
    virtual float get_salary()  override;
    government(float money_, float bonus_) :_salary(money_, bonus_) {}
};

ref class pension : public _salary
{
public:
    virtual float get_salary()  override;
    pension(float money_, float bonus_) :_salary(money_, bonus_) {}
};

ref class free_lancer : public _salary
{
public:
    virtual float get_salary()  override;
    free_lancer(float money_, float bonus_) :_salary(money_, bonus_) {}
};
