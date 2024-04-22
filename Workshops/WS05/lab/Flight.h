#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds 
{

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;
   
   const int MinFuelPerPassenger = 600;

   class Flight
   {

      int m_passengers = 0;
      double m_fuel = 0;
      char m_title[16];
      void emptyPlane();

   public:
      Flight();
      Flight(int passengers, double fuel, const char* title);
      std::ostream& display()const;
      
      // Type Conversion Operators
      // bool operator
      operator bool() const; 
      // int operator
      operator int() const;
      // operator double
      operator double() const;
      // operator const char*
      operator const char* () const;
      
      // Unary Member Operator
      // **bool operator ~**
      bool operator ~()  const; 
      
      // Binary Member Operators
      // Assignment operators
      // Set a Flight to another Flight object
      Flight& operator= (Flight& other);   
      // Flight can be set to an integer value
      Flight& operator= (int passengers);
      // Flight can be set to a double value
      Flight& operator= (double fuel); 
      // Add a double fuel value/amount
      Flight& operator+= (double fuel); 
      // Adding more passengers to a Flight
      Flight& operator+= (int passengers); 
      // Reducing the Flight fuel by a double value
      Flight& operator-= (double fuel);
      // Reducing the Flight passengers by interger
      Flight& operator-= (int passengers);
      // Left shift operator to move passengers from the right Flight to the left
      Flight& operator << (Flight& other); 
      // Right shift operator to move passengers from the left Flight to the right
      Flight& operator >> (Flight& other);
      // Binary member + operator that accepts a constant Flight reference and returns a int value.
      int operator+ (const Flight& other) const;

   };

   // Binary Helper Operator
   int operator+= (int& ref, const Flight& other); 

}
#endif // SDDS_FLIGHT_H