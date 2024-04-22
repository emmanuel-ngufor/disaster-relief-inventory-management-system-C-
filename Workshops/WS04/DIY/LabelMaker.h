#pragma once
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"

namespace sdds
{
	
	class LabelMaker
	{
	private:

		Label* labelArray;
		int numLabels;

	public:

		// creates a dynamic array of Labels to the size of noOfLabels
		LabelMaker(int noOfLabels);

		// Deallocates the memory when LabelMaker goes out of scope.
		void readLabels();

		// Gets the contents of the Labels
		void printLabels();

		// Prints the Labels
		~LabelMaker();


	};


}

#endif // !SDDS_LABELMAKER_H

