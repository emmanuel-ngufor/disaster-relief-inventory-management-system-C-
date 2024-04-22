#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 
#include "AidMan.h"
#include "Utils.h"

namespace sdds
{
	unsigned int AidMan::menu() const
	{
		int year, month, day;  
		ut.getSystemDate(&year, &month, &day); 
		
		std::cout << "Aid Management System" << std::endl; 
		std::cout << "Date: " << year << "/" << month << "/0" << day << std::endl;
		if (m_filename == nullptr || strcmp(m_filename, "") == 0)   
		{ 
			std::cout << "Data file: No file" << std::endl; 
		}
		else
		{
			std::cout << "Data file: " << m_filename << std::endl; 
		}
		
		std::cout << std::endl;  
	
		return mainMenu.run();    
		
	}

	AidMan::AidMan(const char* fileName) : mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database") 
	{
		if (fileName != nullptr)  
		{
			ut.alocpy(m_filename, fileName);
		}
		else 
		{
			fileName = nullptr;
		}
	}

	AidMan::~AidMan()
	{
		if (m_filename != nullptr) 
		{
			delete[] m_filename;   
			m_filename = nullptr;  
		}
	}

	void AidMan::run()  
	{
		int choice; 

		do
		{
			choice = menu();  
			switch (choice) 
			{
			case 1:
				std::cout << std::endl <<"****List Items****" << std::endl << std::endl; 
				break;
			case 2:
				std::cout << std::endl << "****Add Item****" << std::endl << std::endl;
				break;
			case 3:
				std::cout << std::endl << "****Remove Item****" << std::endl << std::endl; 
				break;
			case 4:
				std::cout << std::endl << "****Update Quantity****" << std::endl << std::endl; 
				break;
			case 5:
				std::cout << std::endl << "****Sort****" << std::endl << std::endl;
				break;
			case 6:
				std::cout << std::endl << "****Ship Items****" << std::endl << std::endl; 
				break;
			case 7:
				std::cout << std::endl << "****New/Open Aid Database****" << std::endl << std::endl; 
				break;
			case 0:
				std::cout << "Exiting Program!" << std::endl;  
				break;
			}


		} while (choice != 0);  
	
	}



} // namespace sdds