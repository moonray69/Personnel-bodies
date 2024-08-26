#include "family_member.h"

family_member::family_member()
{
    PIB = "";
    date_of_birthday = "";
    level_relatives = "";
}

family_member::family_member(String^ PIB_, String^ date_of_birthday_, String^ level_relatives_)
{
   PIB = PIB_;
   date_of_birthday = date_of_birthday_;
   level_relatives = level_relatives_;
}

family_member::family_member(family_member^ other)
{
    this->PIB = other->PIB;
    this->date_of_birthday = other->date_of_birthday;
    this->level_relatives = other->level_relatives;
}

String^ family_member::get_PIB()
{
    return PIB;
}

String^ family_member::get_date_of_birthday()
{
    return date_of_birthday;
}

String^ family_member::get_level_relatives()
{
    return level_relatives;
}
