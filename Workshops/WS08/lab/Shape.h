#pragma once
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

namespace sdds
{
	class Shape
	{
    private:
		// An interface that is an Abstract class with only pure virtual functions has no data members

	public:
		// Returns void and receives a reference to ostream as an argument. This pure virtual function can not modify the current object.
		virtual void draw(std::ostream& ostr) const = 0; 
		// Returns void and receives a reference to istream as an argument.
		virtual void getSpecs(std::istream& istr) = 0; 
		// Destructor
		virtual ~Shape();
	};

	// Helper Extraction(Left-shift) and Insertion(Right-shift) Operators respectively
	std::ostream& operator<<(std::ostream& ostr, const Shape& shape);
	std::istream& operator>>(std::istream& istr, Shape& shape);
	
}  // namespace sdds

#endif // !SDDS_SHAPE_H