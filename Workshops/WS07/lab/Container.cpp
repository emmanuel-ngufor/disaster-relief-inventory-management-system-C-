#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Container.h"  


namespace sdds
{
	// Protected modifier and queries: (only accessible by derived classes)
	void Container::setEmpty() { m_validState = false; }
	// Queries
	int Container::getCapacity() const { return m_capacity; } 
	int Container::getVolume() const { return m_contentVolume; } 

	// Constructor
	Container::Container(const char* content, int capacity, int contentVolume)
	{
		if (content == nullptr || contentVolume > capacity)
		{
			setEmpty();
		}
		else
		{
			// Copy the client's content if it is atmost 50 characters
			if (strlen(content) <= MAX_CHARS)
			{
				strcpy(this->m_content, content);
			}
			else  // if the client's content is > 50 characters, copy only the MAX_CHARS 50 needed
			{
				strncpy(this->m_content, content, MAX_CHARS);
				this->m_content[50] = '\0';
			}
			this->m_capacity = capacity;
			this->m_contentVolume = contentVolume;
			m_validState = true;
		}
	}

	// Operations
	int Container::operator+=(int value)
	{
		if (m_contentVolume + value <= m_capacity)
		{
			m_contentVolume += value;
		}
		else
		{
			value = m_capacity - m_contentVolume;
			m_contentVolume = m_capacity; 
		}

		return value;
	}

	int Container::operator-=(int value)
	{
		if (m_contentVolume - value >= 0)
		{
			m_contentVolume -= value; 
		}
		else
		{
			value = m_contentVolume;  
			m_contentVolume = 0;
		}

		return value;
	}

	// bool type conversion.
	Container::operator bool() const { return m_validState; } 

	void Container::clear(int capacity, const char* content_desc) 
	{
		if (capacity >= 1 && ((content_desc != nullptr) && (strlen(content_desc) >= 1)))
		{
			m_capacity = capacity;
			strcpy(m_content, content_desc);
			m_contentVolume = 0;
			m_validState = true;  
		}
	}

	// Methods
	std::ostream& Container::print(std::ostream& ostr) const 
	{
		if (m_validState)
		{
			ostr << m_content << ": (" << m_contentVolume << "cc/" << m_capacity << ")";
		}
		else
		{
			ostr << "****: (**cc/***)";
		}
		return ostr;
	}

	std::istream& Container::read(std::istream& istr)
	{
		int num{};
		if (!m_validState)
		{
			std::cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << std::endl;
			istr.ignore(10000, '\n');
		}
		else
		{
			bool done = false; 
			std::cout << "Add to "; 
			print(std::cout);  

			while (!done) 
			{ 
				std::cout << std::endl << "> ";
				istr >> num; 
				if (istr.fail()) 
				{
					std::cout << "Invalid Integer, retry:";
					istr.clear();
				}
				else if (num < 1 || num > 999) 
				{
					std::cout << "Value out of range [1<=val<=999]:";
					istr.clear();
				}
				else done = true;  
			}

			// Calling the += operator
			num = (*this += num);
			std::cout << "Added " << num << " CCs" << std::endl; 
		}

		return istr;
	}

	// Helper Extraction(Left-shift) and Insertion(Right-shift) Operators respectively
	std::ostream& operator<<(std::ostream& ostr, const Container& container) { return container.print(ostr); }

	std::istream& operator>>(std::istream& istr, Container& container) { return container.read(istr); }

}  // namespace sdds