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
		int m_qtyOnHand;
		int m_neededQty;
		char* m_Description;
		bool m_linear;

	protected:
		Status state;
		int m_sku;
		int linear();

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
		void clear();
		// virtual operator== iProduct overrides
		bool operator==(int SKU) const;
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