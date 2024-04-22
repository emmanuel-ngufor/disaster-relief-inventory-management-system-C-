#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include "Rectangle.h"


namespace sdds
{ 
	Rectangle::Rectangle() : LblShape::LblShape()
	{
		m_width = 0;
		m_height = 0; 
	}

	Rectangle::Rectangle(const char* cString, const int width, const int height) : LblShape::LblShape(cString)
	{
		int value = strlen(label()) + 2; 

		if (height < 3 || width < value) 
		{
			m_width = 0; 
			m_height = 0;
		}
		else
		{
			m_width = width;
			m_height = height;
		}
	}

	void Rectangle::getSpecs(std::istream& istr) 
	{
		// Call the getSpecs() function from the base class(LblShape)
		LblShape::getSpecs(istr);
		// Read the m_width attribute via the istream arg and ignore untill a comma (',')
		istr >> m_width;
		istr.ignore(2000, ','); 
		// Read the m_height attribute via the istream arg and ignore untill a newline ('\n')
		istr >> m_height; 
		istr.ignore(2000, '\n');
	}

	void Rectangle::draw(std::ostream& ostr) const
	{
		if (m_width > 0 && m_height > 0)    
		{
			// first line
			ostr << "+";
			for (int i = 0; i < m_width - 2; i++)
			{ 
				ostr << "-";
			}
			ostr << "+" << std::endl; 

			// second line
			ostr << "|"; ostr << std::setw((std::streamsize)m_width - 2) << std::setfill(' ') << std::left << label();    
			ostr << "|" << std::endl; 

			for (int i = 0; i < m_height - 3; i++) 
			{
				ostr << "|" << std::setw((std::streamsize)m_width - 2) << " " << "|" << std::endl; 
			}

			ostr << "+";
			for (int i = 0; i < m_width - 2; i++)
			{
				ostr << "-";
			}
			ostr << "+"; 
		}

	}

}  // namespace sdds