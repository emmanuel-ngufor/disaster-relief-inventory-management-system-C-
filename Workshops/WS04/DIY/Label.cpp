#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>
#include <string>
#include "Label.h"

using namespace std;

namespace sdds
{

	Label::Label()
	{
		this->m_frame = new char[strlen("+-+|+-+|") + 1];
		strcpy(this->m_frame, "+-+|+-+|");
		this->m_content = nullptr;

	}

	Label::Label(const char* frameArg)
	{
		setFrame(frameArg);
		this->m_content = nullptr;
	}

	void Label::setFrame(const char* frameArg)
	{
		if (frameArg == nullptr)
		{
			this->m_frame = new char[strlen("+-+|+-+|") + 1];
			strcpy(this->m_frame, "+-+|+-+|");
		}
		else
		{
			this->m_frame = new char[strlen(frameArg) + 1];
			strcpy(this->m_frame, frameArg);
		}
	}

	Label::Label(const char* frameArg, const char* content)
	{
		setFrame(frameArg);
		if (content != nullptr && strlen(content) <= CONTENT_LENGTH) 
		{
			this->m_content = new char[strlen(content) + 1];
			strcpy(this->m_content, content);
		}
		else
		{
			this->m_content = nullptr;
		}
	}

	Label::~Label()
	{
		if (this->m_frame != nullptr)
		{
			delete[] this->m_frame;
			this->m_frame = nullptr;
		}
		if (this->m_content != nullptr)
		{
			delete[] this->m_content;
			this->m_content = nullptr;
		}
	}

	istream& Label::readLabel()
	{
		// Read up to 70 characters, including the null terminator 
		cin.getline(this->m_content, CONTENT_LENGTH + 1);
		return cin;

	}

	std::ostream& Label::printLabel() const
	{
		// Check if m_content is nullptr before printing
		if (this->m_content != nullptr)
		{
			int width = (int)strlen(this->m_content) + 2;
			cout << this->m_frame[0];
			for (int i = 0; i < width; ++i)
			{
				cout << this->m_frame[1];
			}
			cout << this->m_frame[2] << endl;

			cout << "| ";
			for (int i = 0; i < width - 2; ++i)
			{
				cout << " ";
			}
			cout << " |" << endl;

			cout << "| ";
			cout << this->m_content << " |" << endl;


			cout << "| ";
			for (int i = 0; i < width - 2; ++i)
			{
				cout << " ";
			}
			cout << " |" << endl;


			cout << this->m_frame[2];
			for (int i = 0; i < width; ++i)
			{
				cout << this->m_frame[1];
			}
			cout << this->m_frame[4];
		}
		return cout;
	}


	Label& Label::text(const char* content)
	{
		// Delete existing content if any
		if (this->m_content != nullptr)
		{
			delete[] this->m_content;
			this->m_content = nullptr;
		}

		// Allocate new memory for content and copy
		if (content != nullptr)
		{
			this->m_content = new char[strlen(content) + 1];
			strcpy(this->m_content, content);
		}
		return *this;
	}


}   // namespace