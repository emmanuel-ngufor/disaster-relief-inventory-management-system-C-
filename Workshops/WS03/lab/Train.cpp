#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Train.h"
#include <cstring>

using namespace std;

namespace sdds
{
	Train::Train()
	{
		initialize(); 
	}

	Train::~Train()
	{
		finalize();
	}

	//  Initializes the Train object to an invalid state by setting the name pointer to nullptr and other attributes to -1.
	void Train::initialize() 
	{
		 trainName = nullptr;    
		 noOfPeople = -1;
		 departureTime = -1;
	}

	// Returns true if the value is between the minimum and maximum acceptable values and if the two right digits are less than or equal to 59.
	bool Train::validTime(int value) const
	{
		return value > MIN_TIME && value < MAX_TIME && value % 100 <= 59 ? true : false;
		// return value > MIN_TIME && value < MAX_TIME && value % 100 <= 59;
	}

	// Returns true if the number of passengers is positive and less than the maximum number of passengers allowed on a train.
	bool Train::validNoOfPassengers(int value)const
	{
		return value > 0 && value < MAX_NO_OF_PASSENGERS ? true : false;
		//return value > 0 && value < MAX_NO_OF_PASSENGERS;
	}

	// Sets the name of the Train dynamically
	void Train::set(const char* name) 
	{
		finalize();
		
		if (name != nullptr && strlen(name) != 0)
		{
			trainName = new char[strlen(name) + 1];  
			strcpy(trainName, name); 
		}

	}

	//  sets the two attributes for the number of passengers and departure time to the incomming values if the are valid. If not both will be set to -1 to mark them as invalid.
	void Train::set(int noOfPassengers, int departure)
	{
		if (validNoOfPassengers(noOfPassengers) && validTime(departure))
		{
			noOfPeople = noOfPassengers;
			departureTime = departure;
		}
		else
		{
			noOfPeople = -1;
			departureTime = -1;
		}
	}

	// sets the name, the number of passengers and the departure time to incomming arguments using the same logic of the other two set functions.
	void Train::set(const char* name, int noOfPassengers, int departure)
	{
		set(name);
		set(noOfPassengers, departure);
	}

	// Finalizes the use of the Train object by deleting the memory pointed by the name attribute pointer.
	void Train::finalize()
	{
		if (trainName != nullptr)
		{
			delete[] trainName;   
			trainName = nullptr; 
		}
	}

	// returns true if any of the attributes are set to their invalid state.
	bool Train::isInvalid()const
	{

		return trainName == nullptr || noOfPeople == -1 || departureTime == -1 ? true : false;
	}


	// This query returns the number of people on a train.
	int Train::noOfPassengers() const 
	{
		return noOfPeople; 
	}


	// This query returns the name of a train.
	const char* Train::getName() const
	{
		return trainName; 
	}

	// This query returns the time of departure.
	int Train::getDepartureTime() const
	{
		return departureTime; 
	}

	// This member function sends the information about a Train to the standard output in the following format if the object holds valid data values.
	void Train::display() const
	{
		if (isInvalid()) 
		{
			cout << "Train in an invalid State!" << endl;
		}
		else
		{
			cout << "NAME OF THE TRAIN:    " << trainName << endl; 
		    cout << "NUMBER OF PASSENGERS: " << noOfPeople << endl;
		    cout << "DEPARTURE TIME:       " << departureTime << endl;
	    }
	

	}

}  // namespace