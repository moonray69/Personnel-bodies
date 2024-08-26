#include "family_status.h"

Family_status::Family_status()
{
    family_stats = "";

    family_members = gcnew List<family_member^> ();
}

Family_status::Family_status(String^ family_stats_, List<family_member^>^ family_members_)
{
    family_stats = family_stats_;
    family_members = family_members_;

}


Family_status::Family_status(Family_status^ other)
{
    this->family_stats = other->family_stats;
    this->family_members = other->family_members;
   
}



String^ Family_status::get_family_stats()
{
    return family_stats;
}

List <family_member^>^ Family_status::get_family_members()
{
    return family_members;
}
