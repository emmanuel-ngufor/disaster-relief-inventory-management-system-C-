#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Portfolio.h"

using namespace std;

namespace sdds 
{
    Portfolio::Portfolio() 
    {
       emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }

    Portfolio::Portfolio(double value, const char* stock, char type) 
    {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) 
        {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const
    {
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Value: ";
            cout.width(10);
            cout << double(*this);
            cout << " | ";
            cout << " Type: ";
            cout << char(*this);
    }

    std::ostream& Portfolio::display() const 
    {

        if (~*this)
        {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) 
        {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else
        {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    // Operators and Conversion Overloads

    // Casting to Double
    Portfolio::operator double () const
    {
        
        return this->m_value;                          
    }

    // Casting to C-string
    Portfolio::operator const char* () const
    {
        return this->m_stock;
    }

    // Casting to Char
    Portfolio::operator char() const 
    {
        return this->m_type;   
    }

    // Casting to Bool
    Portfolio::operator bool() const
    {
        return (this->m_type == 'V' || this->m_type == 'G' || this->m_type == 'I');
    }

    // Addition Overload
    Portfolio& Portfolio::operator+= (double value)
    {
        if (*this && value >= 0)
        {
            this->m_value += value;
        }

        return *this;
    }

    // Subtraction Overload
    Portfolio& Portfolio::operator-= (double value) 
    {
        if (*this && value >= 0)
        {
            this->m_value -= value; 
        }

        return *this;
    }

    // Negation Operator
    bool Portfolio::operator~ () const
    {
        return (this->m_value < 0);
    }

    // Left Shift Operator
    Portfolio& Portfolio::operator<<(Portfolio& other) 
    {
        if (this != &other && *this && other)       
        {
            this->m_value += other.m_value;
            other.emptyPortfolio();
        }
        return *this;
    }

    // Right Shift Operator
    Portfolio& Portfolio::operator>>(Portfolio& other)
    {
        if (this != &other && *this && other)  
        {
            other.m_value += this->m_value;
            (*this).emptyPortfolio();  
        }
        return *this;
    }

    // Binary Helper Operators

    // Binary Helper + Operator
    double operator+ ( const Portfolio& other1, const Portfolio& other2)
    {
        double value = 0.0;

        if (other1 && other2 ) 
        {
            value = other1.operator double() + other2.operator double(); 
        }
        else
        {
            value = 0;
        }
        return value;
    }

    // Binary Helper += Operator
    double operator+= (double& value, const Portfolio& other)
    {
        
        value += other.operator double();
        return value;
    }


}  // namespace sdds