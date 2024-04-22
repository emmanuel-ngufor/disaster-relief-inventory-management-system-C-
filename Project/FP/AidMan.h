#pragma once
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"
#include "iProduct.h"

namespace sdds
{
	const int sdds_max_num_items = 100;

	class AidMan
	{
	private:
		char* m_filename = nullptr;
		Menu m_mainMenu; 
		unsigned int menu() const;
		iProduct* m_iProducts[sdds_max_num_items] = {};  // Array of iProduct pointers 
		int m_numOfiProducts;  // Number of iProduct items 
		void setEmpty(); 
		void set(const char* fileName = nullptr); 

		void save() const; 
		void deallocate(); 
		int search(int sku) const; 
		void remove(int index); 


		int list(const char* sub_desc = nullptr); // Menu Item 1 (List Items)
		void add();                               // Menu Item 2 (Add Item)
		void remove();                            // Menu Item 3 (Remove Item)
		void update();                            // Menu Item 4 (Update Quantity)
		void sort();                              // Menu Item 5 (Sort)
		void ship();                              // Menu Item 6 (Ship Items) 
		bool load();                              // Menu item 7 (New/Open Aid Database)
		void exit();                              // Menu Item 0 (Exit)


	public:
		AidMan();
		AidMan(const AidMan& aidman);
		AidMan& operator=(const AidMan& aidman);
		virtual ~AidMan();
		void run();


	};

} // namespace sdds

#endif // !SDDS_AIDMAN_H