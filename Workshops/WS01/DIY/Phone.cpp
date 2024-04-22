#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Phone.h"
#include "cStrTools.h"

using namespace std;
namespace sdds
{

									// Functions
	
	
	//This functions displays the program Title.
	//It recieves a character string array which is the program title and displays it in a message

	void displayTitle(const char* programTitle)
	{
		cout << "" << programTitle << " phone directory search" << endl;
		cout << "-------------------------------------------------------" << endl;
	}

	// This functions displays the exit message of the program
	// It recieves a character string array which is the program title and displays it in a message

	void exitMessage(const char* programTitle)
	{
		cout << "Thank you for using " << programTitle << " directory." << endl;
	}

	// This function recieves two strings. A word and a name to compare and returns a bool value
	// It uses the toLowercaseAndCopy function to convert the two strings to lowercase letters
	// and copies them into newly defined character strings. 
	// It compares the new strings using the strStr function and returns true if identical or false otherwise.

	bool matchData(char* word, char* name)
	{
		char word_to_Lower[NAME_LEN], name_to_Lower[NAME_LEN];

		toLowerCaseAndCopy(word_to_Lower, word);
		toLowerCaseAndCopy(name_to_Lower, name);

		if (strStr(name_to_Lower, word_to_Lower) != nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	// Runs the phone directory application
	void phoneDir(const char *programTitle, const char* filename) 
	{

		// Declaring Variables
		int found = 1;
		char inputData[NAME_LEN + 1];

		char name[NAME_LEN + 1]; 
		char areaCode[PHONE_NUM_LEN + 1];
		char prefix[PHONE_NUM_LEN + 1];
		char number[PHONE_NUM_LEN + 1];



		displayTitle(programTitle); 


		FILE* fptr = NULL; 
		fptr = fopen(filename, "r"); 

		if (fptr != NULL)
		{
			do
			{
				cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
				cout << "> ";
				cin >> inputData;
				
				if (0 == strCmp(inputData, "!"))
				{
					found = 0;
				}
				else
				{

					while (fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n", name, areaCode, prefix, number) != EOF)
					{
						if (matchData(inputData, name)) 
						{
							cout << name << ": (" << areaCode << ") " << prefix << "-" << number << endl;
						}
					}
					rewind(fptr);

				}


			} while (found);


			fclose(fptr); 


		}
		else
		{
			cout << "" << filename << " file not found!" << endl;
		}

		exitMessage(programTitle);
	
	}


}
