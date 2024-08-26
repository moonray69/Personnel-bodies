#include "_education_info.h"

_education_info::_education_info()
{
    name = "";
    education_level = "";
    diplom = "";
    graduation_year = "";
    science = "";
}

_education_info::_education_info(String^ name_, String^ education_level_, String^ diplom_, String^ graduation_year_, String^ science_)
{
    name = name_;
    education_level = education_level_;
    diplom = diplom_;
    graduation_year = graduation_year_;
    science = science_;
}

_education_info::_education_info(const _education_info^ other)
{
    this->name = other->name;
    this->education_level = other->education_level;
    this->diplom = other->diplom;
    this->graduation_year = other->graduation_year;
    this->science = other->science;
}

String^ _education_info::get_name()
{
    return name;
}

String^ _education_info::get_education_level()
{
    return education_level;
}

String^ _education_info::get_diploma()
{
    return diplom;
}

String^ _education_info::get_graduation_year()
{
    return graduation_year;
}

String^ _education_info::get_science()
{
    return science;
}
