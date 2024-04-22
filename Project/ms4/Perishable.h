#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include "Item.h"
#include "Date.h"

namespace sdds
{
   
	class Perishable : public Item
	{
	private:
		Date m_expiry;
		char* m_handlingInstructions{};
		void setEmpty();
		void set(Date expiry = 0, const char* handling = nullptr);

	public:
		// Default Constructor
		Perishable();
		// Rule of three
		Perishable(const Perishable& perishable);
		Perishable& operator=(const Perishable& perishable);
		~Perishable();
		// Query
		const Date& expiry() const;
		// Virtual Overrides
		int readSku(std::istream& istr);
		std::ofstream& save(std::ofstream& ofstr) const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};

}
#endif  // !SSDS_PERISHABLE_H