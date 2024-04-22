#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "iProduct.h"
namespace sdds
{
	iProduct::~iProduct() {}

	std::ostream& operator<<(std::ostream& ostr, const iProduct& iP)
	{
		return iP.display(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, iProduct& iP)
	{
		return iP.read(istr);
		return istr;
	}

}  // namespace sdds