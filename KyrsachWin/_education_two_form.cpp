#include "_education_two_form.h"

_education_two_form::_education_two_form()
{
     specialty = "";
     skill = "";
     form_of_education = "";
}

_education_two_form::_education_two_form(String^ specialty_, String^ skill_, String^ form_of_education_)
{
    specialty = specialty_;
    skill = skill_;
    form_of_education = form_of_education_;
}

_education_two_form::_education_two_form(_education_two_form^ other)
{
    this->specialty = other->specialty;
    this->skill = other->skill;
    this->form_of_education = other->form_of_education;
}

String^ _education_two_form::get_specialty()
{
    return specialty;
}

String^ _education_two_form::get_skill()
{
    return skill;
}

String^ _education_two_form::get_form_of_education()
{
    return form_of_education;
}
