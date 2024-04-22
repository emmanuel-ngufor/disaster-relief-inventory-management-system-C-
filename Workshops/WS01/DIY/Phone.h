#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H

namespace sdds
{

	// Constant Values
	const int NAME_LEN = 50;
	// const int PHONE_NUM_LEN[3] = {3, 3, 4 };
	const int PHONE_NUM_LEN = 10;

	// Functions
	
	// Display the Program Title the a pointer variable and displays it
	void displayTitle(const char* programTitle);
	// Displays the exit message
	void exitMessage(const char* programTitle);
	// Compares the input data to find a match
	bool matchData(char* word, char* name);
	// Runs the phone directory
	void phoneDir(const char* programTitle, const char* filename);
	
}
#endif
