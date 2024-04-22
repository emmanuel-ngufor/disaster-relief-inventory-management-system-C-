#pragma once
#ifndef TRAIN_H 
#define TRAIN_H

namespace sdds
{

	const int MIN_TIME = 700;
	const int MAX_TIME = 2300;
	const int MAX_NO_OF_PASSENGERS = 1000;

	class Train
	{
	private:
		char* trainName;
		int noOfPeople;
		int departureTime;
	public:
		// Constructor
		Train();
		// Destructor
		~Train();
		//  Initializes the Train object to an invalid state by setting the name pointer to nullptr and other attributes to -1.
		void initialize();
		// Returns true if the value is between the minimum and maximum acceptable values and if the two right digits are less than or equal to 59.
		bool validTime(int value)const;
		// Returns true if the number of passengers is positive and less than the maximum number of passengers allowed on a train.
		bool validNoOfPassengers(int value)const;
		// Sets the name of the Train dynamically
		void set(const char* name);
		// sets the two attributes for the number of passengers and departure time to the incomming values if the are valid. If not both will be set to -1 to mark them as invalid.
		void set(int noOfPassengers, int departure);
		//  sets the name, the number of passengers and the departure time to incomming arguments using the same logic of the other two set functions.
		void set(const char* name, int noOfPassengers, int departure);
		// Finalizes the use of the Train object by deleting the memory pointed by the name attribute pointer.
		void finalize();
		// returns true if any of the attributes are set to their invalid state.
		bool isInvalid()const;
		// This query returns the number of people on a train.
		int noOfPassengers() const;
		// This query returns the name of a train.
		const char* getName() const;
		// This query returns the time of departure.
		int getDepartureTime() const;
		// This member function sends the information about a Train to the standard output in the following format if the object holds valid data values.
		void display() const;
		// Load returns a boolean and has at least one integer reference argument.
		bool load(int& arg);
		// Updates the departure time. Returns a boolean value to indicate the action was succesful or not
		bool updateDepartureTime();
		// Transfers the passengers of a Train to the current Train. Returns a boolean and receives a constant Train reference as an argument.
		bool transfer(const Train& otherTrain);

	};            


}  // namespace

#endif // !TRAIN_H


