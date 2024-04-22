#pragma once
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds
{
	const auto MAX_OPTIONS = 15;

	class Menu
	{
	private:
		char* m_menuContent = nullptr;
		unsigned int m_numOfOptions;
		void setEmpty();
		void set(unsigned int numOpt, const char* content);  

	public:
		Menu(unsigned int numOpt, const char* content); 
		Menu(const Menu& menu);
		Menu& operator=(const Menu& menu);
		virtual ~Menu(); 
		unsigned int run() const;

	};


} // namespace sdds

#endif // !SDDS_MENU_H