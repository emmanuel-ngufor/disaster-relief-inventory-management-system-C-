#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Line.h"

namespace sdds
{
	Line::Line() : LblShape()
	{
		m_length = 0; 
	}

	Line::Line(const char* cString, const int lenght) : LblShape::LblShape(cString)
	{
		m_length = lenght; 
	}
	
	void Line::getSpecs(std::istream& istr) 
	{
		// Call the getSpecs() function of the base class(LblShape)
		LblShape::getSpecs(istr);
		// Read the value of m_length fron the istream argument
		istr >> m_length;
		// Ignore the rest of the characters up to including the newline('\n')
		istr.ignore();
	}

	void Line::draw(std::ostream& ostr) const
	{
		if (m_length > 0 && LblShape::label() != nullptr) 
		{
			ostr << LblShape::label() << std::endl;

			for (auto i = 0; i < m_length; i++) 
			{
				ostr << "=";
			}
		}
	}

}  // namespace sdds