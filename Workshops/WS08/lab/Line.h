#pragma once
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"

namespace sdds
{
	class Line : public LblShape
	{
	private:
		int m_length;                                          //  Holds the length of the Line in characters.

	public:
		// Sets the m_length member variable to zero, and invokes the default constructor of the base class(lblSahpe)
		Line();                                        
		/* Receives a Cstring and a value for the length of the line.
		Passes the Cstring to the constructor of the base class and sets the m_length member variable to the value of the second argument. */
		Line(const char* cString, const int lenght);
		/*
		Reads comma-separated specs of the Line from istream.
        This function overrides the getSpecs function of the base class as follows.
        First, it will call the getSpecs function of the base class then it will read the value of the m_length attribute
		from the istream argument, and then it will ignore The rest of the characters up to and including the newline character '\n'. */
		void getSpecs(std::istream& istr);
		/*This function overrides the draw function of the base class.
		If the m_length member variable is greater than zero and the label() is not null, 
		this function will first print the label() and then go to the new line.Afterwards it keeps 
		printing the '=' (assignment character) to the value of the m_length member variable.
		Otherwise, it will take no action.*/
		void draw(std::ostream& ostr) const;
	};

}  // namespace sdds

#endif // !SDDS_LINE_H