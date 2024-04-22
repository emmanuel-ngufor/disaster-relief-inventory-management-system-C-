#pragma once
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"

namespace sdds
{
	class AidMan
	{
	private:
		char* m_filename{}; 
		Menu mainMenu; 
		unsigned int menu() const;

	public:
		AidMan(const char* filename); 
		AidMan(const AidMan& aidman) = delete;               // Copies Prohibited
		AidMan& operator=(const AidMan& aidman) = delete;    // Assignment Prohibited  
		virtual ~AidMan();
		void run();

	};

} // namespace sdds

#endif // !SDDS_AIDMAN_H