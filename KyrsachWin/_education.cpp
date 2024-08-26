#include "_education.h"

_education::_education() {
	inf = gcnew List<_education_info^>();
}

_education::_education(List<_education_info^>^ inf_) {
	inf = inf_;
}
_education::_education(_education^ other)
{
	this->inf = other->inf;
}

List<_education_info^>^ _education::get_list()
{
	return inf;
}


 
