#ifndef SDDS_PACK_H 
#define SDDS_PACK_H
#include "Container.h"

namespace sdds
{
	class Pack : public Container 
	{
	private:
		int m_UnitSize;
		int m_Size;
		int m_NumOfUnits;

	public:
		// Constructor
		Pack(const char* content_Desc, int size, int unitSize = 330, int numberOfUnits = 0);
		// Operations
		int operator+=(int units);
		int operator-=(int units);
		// Queries
		int unit();
		int noOfUnits();
		int size();
		// Methods
		void clear(int packSize, int unitSize, const char* content_Desc);
		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};

	// Helper Extraction(Left-shift) and Insertion(Right-shift) Operators respectively
	std::ostream& operator<<(std::ostream& ostr, const Pack& pack);  
	std::istream& operator>>(std::istream& istr, Pack& pack); 



}  // namespace sdds

#endif   // !SDDS_PACK_H