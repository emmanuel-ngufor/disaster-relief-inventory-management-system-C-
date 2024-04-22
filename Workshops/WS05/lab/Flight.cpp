#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds 
{

    void Flight::emptyPlane() 
    {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title , "EmptyPlane");
    }

    // New Flight
    Flight::Flight() 
    {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title)
    {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) 
        {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title,title);
        }
    }
    std::ostream& Flight::display() const 
    {

        if (*this)
        {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) 
        {
            cout << " Flight  |  Empty Plane    ";
        }
        else 
        {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }


    // Type Conversion Operators
    Flight::operator bool() const
    {
        return ((this->m_passengers > 0) && (this->m_fuel >= this->m_passengers * MinFuelPerPassenger));
    }


    Flight::operator int() const
    {
        return this->m_passengers;
    }


    Flight::operator double() const 
    {
        return this->m_fuel;
    }


    Flight::operator const char* () const
    {
        return this->m_title;
    }


    // Unary operator
    bool Flight::operator ~()  const
    {
        return this->m_passengers == 0;
    }


    // Binary member operators
    Flight& Flight::operator= (Flight& other)
    {
        if (this != &other)
        {
            this->m_passengers = other.m_passengers;
            this->m_fuel = other.m_fuel;
            strcpy(this->m_title, other.m_title);
            other.emptyPlane();   
        }
        // other.emptyPlane();

        return *this;
    }


    Flight& Flight::operator=(int passengers)
    {
        if (passengers > 0 && passengers <= Boen747Capacity)
        {
            this->m_passengers = passengers; 
        }
        return *this;
    }


    Flight& Flight::operator=(double fuel) 
    {
        if (fuel >= 0 && fuel <= FuelTankCapacity) 
        {
            this->m_fuel = fuel; 
        }
        return *this;
    }


    Flight& Flight::operator+=(double fuel) 
    {
        if (fuel > 0)
        {
            this->m_fuel += fuel;

            if (this->m_fuel > FuelTankCapacity) 
            {
                this->m_fuel = FuelTankCapacity; 
            }
        }
        return *this;
    }


    Flight& Flight::operator+=(int passengers)
    {
        if (passengers > 0)
        {
            this->m_passengers += passengers;

            if (this->m_passengers > Boen747Capacity) 
            {
                this->m_passengers = Boen747Capacity;  
            }
        }
        return *this;
    }


    Flight& Flight::operator-=(double fuel)
    {
        if (fuel > 0) 
        {
            this->m_fuel -= fuel;

            if (this->m_fuel < 0) 
            {
                this->m_fuel = 0;  
            }
        }
        return *this;
    }


    Flight& Flight::operator-=(int passengers) 
    {
        if (passengers > 0)
        {
            this->m_passengers -= passengers;

            if (this->m_passengers < 0) 
            {
                this->m_passengers = 0; 
            }
        }
        return *this;
    }


    Flight& Flight::operator<<(Flight& right)
    {
        if (*this && right && &right != this)       // bool operator is called ==(equivalent) bool(*this) && bool(other)
        {
            int spaceAvailable = Boen747Capacity - this->m_passengers; 
            if (spaceAvailable > 0)
            {
                int passengersToMove = min(spaceAvailable, right.m_passengers);
                this->m_passengers += passengersToMove;
                right.m_passengers -= passengersToMove;
            }
        }
        return *this;
    }


    Flight& Flight::operator >> (Flight& right) 
    {
        if (*this && right)       // bool operator is called ==(equivalent) bool(*this) && bool(other)
        {
            int spaceAvailable = Boen747Capacity - right.m_passengers;
            if (spaceAvailable > 0)
            {
                int passengersToMove = min(spaceAvailable, this->m_passengers); 
                right.m_passengers += passengersToMove;
                this->m_passengers -= passengersToMove;
            }
        }
        return *this;
    }


    int Flight::operator+ (const Flight& other) const
    {
        int sum = 0;
        if (*this && other)    // bool operator is called ==(equivalent) bool(*this) && bool(other)
        {
            sum = other.m_passengers + this->m_passengers;
        }
        else
        {
            sum = 0;
        }

        return sum;
    }


    // Binary Helper Operator
    int operator+= (int& total, const Flight& other)
    {
        total += other.operator int();
 
        return total;
    }



} // namespace sdds