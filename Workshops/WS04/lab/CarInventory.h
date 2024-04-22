#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#ifndef CARINVENTORY_H
#define CARINVENTORY_H

namespace sdds
{

	class CarInventory
	{
	private:

		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;

		// This method resets the values for all member variables by setting type, brand, and model to nullptr and setting the year, code, and price to 0.
		CarInventory& resetInfo();
		
	public:

		// The default constructor will initialize the member variables by calling the resetInfo() method in the Private Member section.
		CarInventory();

		// Destructor to dynamically allocate the memory that was set for m_type, m_brand and m_model.
		~CarInventory();

		// This constructor will first reset the data and then dynamically keep the values of the C-string argument in their corresponding attributes
		//  and set the rest of the attributes the corresponding argument values if they pass validation.
		CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1.0);

		// This method will first deallocate all the allocated memory and then set the attributes to the corresponding arguments exactly like the 6-argument constructor.
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);  

		// This method prints the values of all the member variables on the screen in the following format. Order:TYPE, BRAND, MODEL, YEAR, CODE, PRICE
		void printInfo() const;

		// This method returns whether all member variables have valid values or not based on the criteria stated in the Private Member Variables.
		bool isValid() const;

		// This function is to check whether the type, make, brand and year of an object of CarInventory are equal to another object of this class.
		// The function will return true only if all those values match. if any of the values are nullptr, the function will return false;
		bool isSimilarTo(const CarInventory& car) const;

	};

	// Global namespace function
	// It returns the index of the first match, if it finds two CarInventory objects that have similar information in the car array.
	int find_similar(CarInventory car[], const int num_cars);


}  // namespace


#endif // !CARINVENTORY_H