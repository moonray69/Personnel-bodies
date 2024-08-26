#include "_diseases.h"

_diseases::_diseases()
{
    disability_group = "";
    name = "";
    type = "";
}

_diseases::_diseases(String^ disability_group_, String^ name_, String^ type_)
{
    disability_group = disability_group_;
    name = name_;
    type = type_;
}

_diseases::_diseases(const _diseases^ other)
{
    this->disability_group = other->disability_group;
    this->name = other->name;
    this->type = other->type;
}

String^ _diseases::get_disability_group()
{
    return disability_group;
}

String^ _diseases::get_name()
{
    return name;
}

String^ _diseases::get_type()
{
    return type;
}
