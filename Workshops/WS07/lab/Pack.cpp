#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Pack.h"  


namespace sdds
{
	// Constructor
	Pack::Pack(const char* content_Desc, int size, int unitSize, int numberOfUnits)
		: Container(content_Desc, size * unitSize, numberOfUnits * unitSize)
	{
		this->m_UnitSize = unitSize;
		this->m_Size = size;
		this->m_NumOfUnits = numberOfUnits;

		if (unitSize <= 0)
		{
			Container::setEmpty();     
		}
	}
	
	// Operations
	int Pack::operator+=(int units) 
	{
		int result = Container::operator+=(units * m_UnitSize) / m_UnitSize;  
		m_NumOfUnits += result;   
		return result; 
	}

	int Pack::operator-=(int units)
	{
		int result = Container::operator-=(units * m_UnitSize) / m_UnitSize;
		m_NumOfUnits -= result;
		return result; 
	}

	// Queries
	int Pack::unit() { return m_UnitSize; } 
	int Pack::noOfUnits() { return m_NumOfUnits; }
	int Pack::size() { return m_NumOfUnits; } 

	// Methods
	void Pack::clear(int packSize, int unitSize, const char* content_Desc)
	{
		if (unitSize > 0)
		{
			int packUnit = packSize * unitSize;
			m_Size = packSize;

			Container::clear(packUnit, content_Desc); 
			this->m_UnitSize = unitSize; 
			this->m_NumOfUnits = 0;
		}
	}

	std::ostream& Pack::print(std::ostream& ostr) const 
	{
		Container::print(ostr);  
		if (*this) 
		{
			ostr << ", " << m_NumOfUnits << " in a pack of " << m_Size; 
		}

		return ostr;
	}

	std::istream& Pack::read(std::istream& istr)
	{
		int units{}; 
		if (!*this)
		{
			std::cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.ignore(10000, '\n');
		}
		else if (m_NumOfUnits == m_Size)  
		{ 
			istr.ignore(); 
			std::cout << "Pack is full!, press <ENTER> to continue..." << std::endl; 
		}
		else
		{
			bool done = false;
			std::cout << "Add to ";
			print(std::cout); 

			// Declaring additional variables
			int maxCapacity = m_Size - m_NumOfUnits;  
			int flag = 0;  
			while (!done && flag == 0) 
			{
				std::cout << std::endl << "> ";
				istr >> units; 
				if (istr.fail())
				{
					std::cout << "Invalid Integer, retry:";
					istr.clear();
				}
				else if (units < 1 || units > maxCapacity)  
				{
					std::cout << "Value out of range [1<=val<=" << maxCapacity << "]: "; 
					istr >> units; 
					flag = 1;
					istr.clear();
				}
				else done = true;
			}

			// Calling the += operator
			units = (*this += units);
			std::cout << "Added " << units << std::endl; 
		}

		return istr; 
	}

	//  Helper Extraction(Left-shift) and Insertion(Right-shift) Operators respectively
	std::ostream& operator<<(std::ostream& ostr, const Pack& pack) { return pack.print(ostr); }  

	std::istream& operator>>(std::istream& istr, Pack& pack) { return pack.read(istr); }   

} // namespace sdds