#include "_certificate.h"

_certificate::_certificate()
{
    name = "";
    Date_of_receiving = "";
    points = "";
    location = "";
}

_certificate::_certificate(String^ name_, String^ Date_of_receiving_, String^ points_,
    String^ location_)
{
    name = name_;
    Date_of_receiving = Date_of_receiving_;
    points = points_;
    location = location_;
}

_certificate::_certificate(_certificate^ other)
{
    this->name = other->name;
    this->Date_of_receiving = other->Date_of_receiving;
    this->points = other->points;
    this->location = other->location;
}

String^ _certificate::get_the_name_of_the_certificate()
{
 
    return name;
  
}

String^ _certificate::get_Date_of_receiving_the_certificate()
{
    return Date_of_receiving;
}

String^ _certificate::get_points()
{
    return points;
}

String^ _certificate::get_location()
{
    return location;
}
