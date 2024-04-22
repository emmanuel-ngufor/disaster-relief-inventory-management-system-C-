#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string> 
#include "Menu.h"
#include "Utils.h"
using namespace std;

namespace sdds
{
	
	Menu& Menu::setEmpty()
	{
		m_menuContent = nullptr; 
		m_numOfOptions = 0;
		m_validMenu = false;
		return *this;
	}

	Menu::Menu(const char* content)
	{
		if (content == nullptr)      
		{
			setEmpty(); 
		}
		else
		{
			// Determine the number of options based on the number of tabs (\t) found in the C-String.
			// Initialized to 1 because 1 tab seperates atleast 2 options
			int numberOfOptions{ 1 };  
			for (int i = 0; content[i] != '\0'; i++)
			{
				if (content[i] == '\t')
				{
					numberOfOptions++;
				}
			}

			if (numberOfOptions <= MAX_OPTIONS) 
			{
				ut.alocpy(m_menuContent, content);
				m_numOfOptions = numberOfOptions;
				m_validMenu = true;
			}
			else  // Menu is rendered invalid 
			{
				setEmpty();
			}
		}
	}

	Menu::~Menu()
	{
		if (m_menuContent != nullptr)
		{
			delete[] m_menuContent;
			m_menuContent = nullptr;  
		}
	}

	unsigned int Menu::run() const
	{
		unsigned int selectedOption{}; 
		
		if (m_validMenu)
		{
			int optionNumber = 2;

			std::cout << 1 << "- ";

			for (int i = 0; m_menuContent[i] != '\0'; i++)
			{
				if (m_menuContent[i] == '\t')
				{
					std::cout << endl << optionNumber << "- ";  
					++optionNumber;
				}
				else
				{
					std::cout << m_menuContent[i]; 
				}    
			}

			std::cout << std::endl << "---------------------------------" << std::endl; 
			std::cout << "0- Exit" << std::endl;  

			int min = 0;
			int max = m_numOfOptions; 
			const char* prompt = "> ";
			selectedOption = ut.getint(min, max, prompt);
			// selectedOption = ut.getint(0, m_numOfOptions, "> ");
		}
		else
		{
			std::cout << "Invalid Menu!" << std::endl;  
			selectedOption = 0;
		}

		return selectedOption;
	}


}  // namespace sdds