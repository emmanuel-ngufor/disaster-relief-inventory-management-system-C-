/*========================================================================
Name: Emmanuel Sahfor Ngufor
Student Number : 135 801 215
Email : esngufor@myseneca.ca
Section : NEE
Workshop : MS2_Project_Milestone2
Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
==========================================================================
Menu.cpp
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string> 
#include "Menu.h"
#include "Utils.h"
using namespace std;

namespace sdds
{
	void Menu::setEmpty()
	{
		m_menuContent = nullptr; 
		m_numOfOptions = -1;
		m_validMenu = false;
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

			std::cout << std::endl << "-----------------------------------------" << std::endl; 
			std::cout << "0 - Exit" << std::endl;  

			int min(0);
			
			selectedOption = ut.getint(min, MAX_OPTIONS);

		}
		else
		{
			std::cout << "Invalid Menu!" << std::endl;  
			selectedOption = 0;
		}

		return selectedOption;
	}

	



}  // namespace sdds