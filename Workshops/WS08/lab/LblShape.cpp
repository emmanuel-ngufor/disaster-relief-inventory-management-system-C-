#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string.h>
#include "LblShape.h"

namespace sdds
{ 
	const char* LblShape::label() const
	{ 
		return m_label;
	}

	LblShape::LblShape() 
	{
		if (this->m_label != nullptr)
		{
			m_label = nullptr; 
		}
	}

	LblShape::LblShape(const char* cString) 
	{
		if (cString != nullptr) 
		{
			this->m_label = new char[strlen(cString) + 1];
			strcpy(this->m_label, cString);
		}
		else
		{
			m_label = nullptr;
		}
	}

	LblShape::~LblShape()
	{
		if (m_label != nullptr)
		{
			delete[] m_label;
			m_label = nullptr;
		}
	}

	void LblShape::getSpecs(std::istream& istr)
	{
		// Declare a cString to read the characters.
		char cString[100]{}; 

		// Use the get function to read up untill the comma (',').
		istr.get(cString, 100, ','); 
		// Ignore when you get to the comma (',').
		istr.ignore(); 

		// Alloacte memory large enough for the cString to be copied to m_label
		delete[] this->m_label;   
		m_label = new char[strlen(cString) + 1]; 
		strcpy(m_label, cString);  
	}

} // namespace sdds