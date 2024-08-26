#pragma once
#include "library.h"
#include "_education_info.h"

using namespace System::Collections::Generic;

ref class _education
{
private:

	List<_education_info^>^ inf;
	

public:

	_education();

	_education(List<_education_info^>^ inf);

	_education(_education^ other);

	List<_education_info^>^ get_list();


};