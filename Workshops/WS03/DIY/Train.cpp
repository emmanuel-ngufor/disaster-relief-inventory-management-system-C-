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
			cout << "NAME OF THE TRAIN:    " << getName() << endl;
			cout << "NUMBER OF PASSENGERS: " << noOfPeople << endl;
			cout << "DEPARTURE TIME:       " << departureTime << endl;
		}
	}

	// Load returns a boolean and has at least one integer reference argument.
	bool Train::load(int& notBoarded) 
	{
		int numPassengers;
		cout << "Enter number of passengers boarding:" << endl;
		cout << "> ";
		cin >> numPassengers;

		if (numPassengers <= 0) 
		{
			cout << "Invalid number of passengers." << endl;
			noOfPeople = -1;
			notBoarded = 0;
			return false;
		}

		if (noOfPeople + numPassengers <= MAX_NO_OF_PASSENGERS) 
		{
			noOfPeople += numPassengers;
			notBoarded = 0;
			return true;
		}
		else 
		{
			notBoarded = (noOfPeople + numPassengers) - MAX_NO_OF_PASSENGERS;
			noOfPeople = MAX_NO_OF_PASSENGERS;
			return false;
		}
	}



	// Updates the departure time. Returns a boolean value to indicate the action was succesful or not
	bool Train:: updateDepartureTime()
	{
		// getDepartureTime();
		int newDeparturetime;
		cout << "Enter new departure time:" << endl << "> ";
		cin >> newDeparturetime; 
		if (validTime(newDeparturetime))
		{
			departureTime = newDeparturetime; 
			return true;
		}
		else
		{
			departureTime = -1;
			return false;
		}
		
	}

	// Transfers the passengers of a Train to the current Train. Returns a boolean and receives a constant Train reference as an argument.
	bool Train::transfer(const Train& other)
	{
		if (!isInvalid() && !other.isInvalid())
		{
			char* combinedName = new char[strlen(trainName) + strlen(other.trainName) + 3];
			strcpy(combinedName, trainName);
			strcat(combinedName, ", ");
			strcat(combinedName, other.trainName);

			delete[] trainName;
			trainName = combinedName;

			int notBoarded = 0;
			if (noOfPeople + other.noOfPeople <= MAX_NO_OF_PASSENGERS)
			{
				noOfPeople += other.noOfPeople;
			}
			else
			{
				notBoarded = (noOfPeople + other.noOfPeople) - MAX_NO_OF_PASSENGERS;
				noOfPeople = MAX_NO_OF_PASSENGERS;
			}


			if (notBoarded > 0) 
			{
				cout << "Train is full; " << notBoarded << " passengers of " << other.getName() << " could not be boarded!" << endl;
			}

			return true;
		}
		else
		{
			return false;
		}
	
	}


}  // namespace


