#pragma once
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds
{
	const auto MAX_OPTIONS = 15;  

	class Menu 
	{
	private:
		char* m_menuContent{};
		unsigned int m_numOfOptions;
		bool m_validMenu; 

	public:
	    // Sets a Menu object to an Empty (Invalid) state
		Menu& setEmpty(); 
		// Rule of three
		Menu(const char* content);                           // Construction
	    Menu(const Menu& menu) = delete;                     // Copies Prohibited
		Menu& operator=(const Menu& menu) = delete;          // Assignment Prohibited
		virtual ~Menu();                                     // Destructor: Memory Leak Prevention
		// Methods
		unsigned int run() const; 

	};


} // namespace sdds

#endif // !SDDS_MENU_H