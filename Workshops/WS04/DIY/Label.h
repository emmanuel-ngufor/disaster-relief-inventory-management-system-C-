#pragma once
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H


namespace sdds
{
	const int CONTENT_LENGTH = 70;

	class Label
	{
	private:
		char* m_frame;  
		char* m_content;

	public: 
		// Creates an empty label and defaults the frame to "+-+|+-+|"
		Label();

		// Creates an empty label and sets the frame to the frameArg argument. If the frameArg is nullptr, the default frame will be used instead.
	    Label(const char* frameArg); 

		// Sets the frame argument to default if frameArg is a nullptr
		void setFrame(const char* frameArg);

		// Creates a Label with the frame set to frameArg and the content of the Label set to the corresponding argument. Note that you must keep the content dynamically even though it should never be more than 70 characters.
		Label(const char* frameArg, const char* content);

		// Makes sure there is no memory leak when the label goes out of scope.
		~Label();

		// Reads the content of the label from the console up to 70 characters and stores it in the Label as shown below and then returns the cin.
		std::istream& readLabel(); 

		// Prints the label by drawing the frame around the content as shown below. Note that no newline is printed after the last line and cout is returned at the end.
		std::ostream& printLabel()const; 

		// Sets the content of the Label (up to 70 characters) dynamically and then returns the reference of the current object.
		Label& text(const char* content);
		
	};


} // namespace


#endif // !SDDS_LABEL_H