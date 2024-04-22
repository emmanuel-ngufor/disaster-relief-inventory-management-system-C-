#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <string>
#include "Item.h"
#include "Utils.h"

namespace sdds
{
	// Default Constructor
	Item::Item()
	{
		m_price = 0;
		m_qtyOnHand = 0;
		m_neededQty = 0; 
		m_sku = 0;
		m_Description = nullptr;
		m_linear = false;
		state = false;
	}

	// Protected Query
	int Item::linear() { return m_linear; } 

	// Rule of three
	Item::~Item()
	{
		if (m_Description != nullptr)
		{
			delete[] m_Description;
			m_Description = nullptr;
		}
	}

	Item::Item(const Item& item)
	{
		*this = item;
	}

	Item& Item::operator=(const Item& item)
	{
		if (this != &item) 
		{ 
			m_price = item.m_price;  
			m_qtyOnHand = item.m_qtyOnHand;
			m_neededQty = item.m_neededQty;
			ut.alocpy(m_Description, item.m_Description);
			state = item.state; 
			m_sku = item.m_sku; 
		}
		return *this;
	}

	// virtual public query iProduct overrides
	int Item::qtyNeeded()const { return m_neededQty; }
	int Item::qty()const { return m_qtyOnHand; }
	Item::operator double()const { return m_price; }
	Item::operator bool()const { return state; } 
	
	// virtual public modifier iProduct overrides
	int Item::operator-=(int qty) { return m_qtyOnHand -= qty; }
	int Item::operator+=(int qty) { return m_qtyOnHand += qty; }
	void Item::linear(bool isLinear) { m_linear = isLinear;  }

	// public modifier
	void Item::clear()
	{
		m_price = 0.0;
		m_qtyOnHand = 0;
		m_neededQty = 0;
		delete[] m_Description;
		m_Description = nullptr;
		m_linear = false;
		state = nullptr;
		m_sku = 0; 
	}

	// virtual operator== iProduct overrides
	bool Item::operator==(int SKU) const { return m_sku == SKU; }
	bool Item::operator==(const char* description) const { return strstr(m_Description, description); }

	// virtual Input/Output method iProduct overrides
	std::ofstream& Item::save(std::ofstream& ofstr) const
	{
		ofstr << m_sku << '\t' << m_Description << '\t' << m_qtyOnHand << '\t' << m_neededQty << '\t' << std::fixed << std::setprecision(2) << m_price << std::endl;  
		return ofstr;
	}

	std::ifstream& Item::load(std::ifstream& ifstr)
	{
		delete[] m_Description;
		m_Description = nullptr; 

		std::string desc; 
		ifstr >> m_sku; 
		ifstr.ignore(10000, '\t');
		std::getline(ifstr, desc, '\t');  
		ifstr >> m_qtyOnHand; 
		ifstr.ignore(10000, '\t');
		ifstr >> m_neededQty;
		ifstr.ignore(10000, '\t');
		ifstr >> m_price; 
		ifstr.ignore();

		if (ifstr.bad()) 
		{
			state = "Input file stream read failed!";  
		}

		ut.alocpy(m_Description, desc.c_str());  

		return ifstr;
	}

	std::ostream& Item::display(std::ostream& ostr)const
	{
		if (!state) 
		{
			ostr << state;
		}
		else
		{
			if (m_linear) 
			{
				ostr.width(5);
				ostr << m_sku << " | ";
				int i;
				for (i = 0; i < 35; i++) 
				{
					if (m_Description[i] == '\0') 
					{
						break;
					}
					else 
					{
						ostr << m_Description[i]; 
					}
				}

				while (i < 35)
				{
					ostr << " "; 
					i++;
				}

				ostr << " | ";
				ostr.setf(std::ios::right); 
				ostr.width(4);
				ostr << m_qtyOnHand << " | ";
				ostr.unsetf(std::ios::right); 
				ostr.setf(std::ios::right); 
				ostr.width(4);
				ostr << m_neededQty << " | "; 
				ostr.unsetf(std::ios::right); 
				ostr.setf(std::ios::right); 
				ostr.width(7);
				ostr << std::fixed << std::setprecision(2) << m_price << " |"; 
			}
			else 
			{
				ostr << "AMA Item:" << std::endl; 
				ostr << m_sku << ": " << m_Description << std::endl; 
				ostr << "Quantity Needed: " << m_neededQty << std::endl; 
				ostr << "Quantity Available: " << m_qtyOnHand << std::endl; 
				ostr << "Unit Price: $" << m_price << std::endl; 
				ostr << "Needed Purchase Fund: $" << m_price * (m_neededQty - m_qtyOnHand) << std::endl;  
			}
		}
		return ostr;
	}

	int Item::readSku(std::istream& istr)
	{
		int sku; 
		sku = ut.getint(40000, 99999, "SKU: "); 
		m_sku = sku; 

		return sku; 
	}

	std::istream& Item::read(std::istream& istr)
	{
		std::string desc; 
		std::cout << "AMA Item:" << std::endl; 
		std::cout << "SKU: " << m_sku << std::endl; 
		std::cout << "Description: "; 
		istr >> desc;
		m_neededQty = ut.getint(1, 9999, "Quantity Needed: ");
		m_qtyOnHand = ut.getint(0, m_neededQty, "Quantity On Hand: "); 
		m_price = ut.getdouble(0.00, 9999.00, "Unit Price: $"); 
		if (!istr) 
		{
			state = "Console entry failed!";
		}
		ut.alocpy(m_Description, desc.c_str());
		return istr;
	}

}  // namespace sdds