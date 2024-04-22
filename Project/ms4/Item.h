#pragma once
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include "iProduct.h"
#include "Status.h"

namespace sdds
{
	class Item : public iProduct
	{
	private:
		double m_price;
		int m_qty;
		int m_qtyNeeded;
		char* m_description = nullptr;
		bool m_linear;
		void setEmpty();
		void set(double price = 0, int qty = 0, int qtyNeeded = 0, const char* description = nullptr, bool linear = false, Status state = 0, int sku = 0);

	protected:
		Status m_state; // a Status object to hold the state of the Item object
		int m_sku;
		bool linear() const;
		

	public:
		Item();
		// rule of three
		virtual ~Item();
		Item(const Item& item);
		Item& operator=(const Item& item);
		// virtual public query iProduct overrides
		int qtyNeeded()const;
		int qty()const;
		operator double()const;
		operator bool()const;
		// virtual public modifier iProduct overrides
		int operator-=(int qty);
		int operator+=(int qty);
		void linear(bool isLinear);
		// public modifier
		Status clear(); 
		// virtual operator== iProduct overrides
		bool operator==(int sku) const; 
		bool operator==(const char* description) const;
		// virtual Input/Output method iProduct overrides
		std::ofstream& save(std::ofstream& ofstr) const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr)const;
		int readSku(std::istream& istr);
		std::istream& read(std::istream& istr);

	};

}  // namespace sdds

#endif  // !SDDS_ITEM_H