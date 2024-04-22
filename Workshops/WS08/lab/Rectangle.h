#pragma once
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"

namespace sdds
{
	class Rectangle : public LblShape
	{
	private:
		int m_width;
		int m_height;
		
	public:
		Rectangle();
		Rectangle(const char* cString, const int width, const int height);
		/* Reads comma-separated specs of the Rectangle from istream.
		This function overrides the getSpecs function of the base class as follows.
		First, it will call the getSpecs function of the base class, then it will 
		read two comma - separated values from istream for m_width and m_height and 
		then ignores the rest of the characters up to and including the newline character('\n').*/
		void getSpecs(std::istream& istr);
		/* This function overrides the draw function of the base class.
        If the Rectangle is not in an empty state, this function will draw a rectangle with a label inside, 
		otherwise, it will do nothing:*/
		void draw(std::ostream& ostr) const;
	};

}  // namespace sdds

#endif // !SDDS_RECTANGLE_H