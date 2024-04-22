#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>
#include "LabelMaker.h"
#include "Label.h"

using namespace std;

namespace sdds
{

	LabelMaker::LabelMaker(int noOfLabels)
	{
		this->labelArray = new Label[noOfLabels];
		this->numLabels = noOfLabels;
	}

	void LabelMaker::readLabels()
	{
		cout << "Enter " << this->numLabels << " labels:" << endl;

		for (int i = 0; i < this->numLabels; i++)
		{
			cout << "Enter label number " << i + 1 << endl << "> ";
			char content[71];
			cin.getline(content, CONTENT_LENGTH + 1); 
			labelArray[i].text(content);
		}
	}


	void LabelMaker::printLabels()
	{
		for (int i = 0; i < numLabels; ++i)
		{
			labelArray[i].printLabel();
			cout << endl;
		}
	}


	LabelMaker::~LabelMaker()
	{
		if (this->labelArray != nullptr)
		{
			delete[] this->labelArray;
			this->labelArray = nullptr;
		}
	}


}   // namespace