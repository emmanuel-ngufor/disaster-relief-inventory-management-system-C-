#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip> 
#include <cstring>
#include "CarInventory.h"


using namespace std;

namespace sdds
{

	CarInventory::CarInventory()
	{
		resetInfo();
	}

	CarInventory::~CarInventory()
	{
		if (this->m_model != nullptr)
		{
			delete[] this->m_model;
			this->m_model = nullptr;
		}

		if (this->m_brand != nullptr)
		{
			delete[] this->m_brand;
			this->m_brand = nullptr;
		}

		if (this->m_type != nullptr)
		{
			delete[] this->m_type;
			this->m_type = nullptr;
		}

	}


	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		resetInfo(); 
		this->m_type = new char[strlen(type) + 1];
		strcpy(m_type, type);
		this->m_brand = new char[strlen(brand) + 1];
		strcpy(m_brand, brand);
		this->m_model = new char[strlen(model) + 1];
		strcpy(m_model, model);

		
		if (year >= 1990 && (code >= 100 && code <= 999) && price > 0)
		{
			this->m_year = year;
			this->m_code = code;
			this->m_price = price;
			// Possible errors
		}		

	}

	
	CarInventory& CarInventory::resetInfo()
	{
		this->m_type = this->m_brand = this->m_model = nullptr;
		this->m_year = this->m_code = 0;
		this->m_price = 0.0;

		return *this;

	}


	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		delete[] this->m_type;
		delete[] this->m_brand;
		delete[] this->m_model;  
		// delete[] this->m_type, this->m_brand, this->m_model;     // Possible error

		resetInfo(); 
		this->m_type = new char[strlen(type) + 1]; 
		strcpy(m_type, type); 
		this->m_brand = new char[strlen(brand) + 1]; 
		strcpy(m_brand, brand); 
		this->m_model = new char[strlen(model) + 1]; 
		strcpy(m_model, model); 

		if (year >= 1990 && (code >= 100 && code <= 999) && price > 0)
		{
			this->m_year = year; 
			this->m_code = code; 
			this->m_price = price; 
			// Possible errors
		}

		return *this;
	}

	void CarInventory::printInfo() const
	{
		cout << left << "| ";
		cout << setw(10) << this->m_type  << " | ";
		cout << setw(16) << this->m_brand << " | ";
		cout << setw(16) << this->m_model << " | ";
		cout << setw(4)  << this->m_year  << " | "; 
		cout << right << setw(4) << this->m_code << " | "; 
		cout << right << setw(9) << fixed << setprecision(2) << this->m_price << " |" << endl;
	}


	bool CarInventory::isValid() const
	{
		return (this->m_type != nullptr && this->m_brand != nullptr && this->m_model != nullptr && this->m_year >= 1990 && 
			   (this->m_code >= 100 && this->m_code <= 999) && this->m_price > 0) ? true : false;
	}


	bool CarInventory::isSimilarTo(const CarInventory& car) const
	{
		if (this->m_type == nullptr || this->m_brand == nullptr || this->m_model == nullptr ||
			  car.m_type == nullptr || car.m_brand == nullptr || car.m_model == nullptr)
		{
			return false; // At least one of the cars object has missing data, not similar.   
		}

		return (strcmp(this->m_type, car.m_type) == 0 &&
			strcmp(this->m_brand, car.m_brand) == 0 &&
			strcmp(this->m_model, car.m_model) == 0 &&
			this->m_year == car.m_year);
	}



	int find_similar(CarInventory car[], const int num_cars)
	{
	
	
		for (int i = 0; i < num_cars; i++) 
		{
			for (int j = i + 1; j < num_cars; j++) 
			{
				if (car[i].isSimilarTo(car[j])) 
				{
					return i; 
					// match is found
				}
			}

		}
		return -1;  // no match found  

	}




} // namespace


