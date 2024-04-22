#pragma once
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"

namespace sdds
{
	class LblShape : public Shape
	{
	private:
		char* m_label = nullptr;                                  // if initialized to nullptr, then no need to create a default constructor 

	protected:
		const char* label() const;                                // Query

	public:
		LblShape();                                               // Optional
		LblShape(const char* cString);                            // One argument constructor
		virtual ~LblShape();                                      // Destructor: Memory leak prevention
		LblShape(const LblShape& shape) = delete;                 // Copies prohibited
		LblShape& operator=(const LblShape& shape) = delete;      // Assignments prohibited
		void getSpecs(std::istream& istr);                        // Overides the Shape::getSpecs() pure virtual function of the base class(Shape)

	};

}  // namespace sdds

#endif // !SDDS_LBLSHAPE_H