#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Date.h"  
#include "Utils.h"
using namespace std;

namespace sdds 
{
    bool Date::validate() 
    {
        // Define variables: flag and current year
        bool isvalid = false;
        int currentYear;

        // Get the cuurent present year
        ut.getSystemDate(&currentYear); 

        // Deallocate any existing memory
        status.clear(); 

        if (m_Year < currentYear || m_Year > MAX_YEAR_VALUE)   
        {
            status = "Invalid year in date";
            status = 1; 
        }
        else if (m_Month < 1 || m_Month> 12) 
        {
            status = "Invalid month in date";
            status = 2; 
        }
        else if (m_Day<1 || m_Day > ut.daysOfMon(m_Month, m_Year))
        {
            status = "Invalid day in date";
            status = 3;
        }
        else if (m_Invalid == true)
        {
            status = 0;
            status = "Invalid date value";
        }
        else 
        {
            isvalid = true;
        }

        return isvalid;
    }

    int Date::uniqueDateValue() const
    {
        return m_Year * 372 + m_Month * 31 + m_Day;
    }

    Date::Date()
    {
        m_Formatted = true; 
        m_Invalid = false;
        ut.getSystemDate(&m_Year, &m_Month, &m_Day);
    }

    Date::Date(int year, int month, int day)
    {
        m_Year = year;
        m_Month = month;
        m_Day = day;
        m_Formatted = true; 
        m_Invalid = false; 
        validate();
    }

               // Operator overloads for comaprison
    bool Date::operator==(const Date& other) const
    {
        return this->uniqueDateValue() == other.uniqueDateValue();
    }
    bool Date::operator!=(const Date& other) const
    {
        return this->uniqueDateValue() != other.uniqueDateValue();
    }
    bool Date::operator>=(const Date& other) const
    {
        return this->uniqueDateValue() >= other.uniqueDateValue();
    }
    bool Date::operator<=(const Date& other) const
    {
        return this->uniqueDateValue() <= other.uniqueDateValue();
    }
    bool Date::operator<(const Date& other) const
    {
        return this->uniqueDateValue() < other.uniqueDateValue();
    }
    bool Date::operator>(const Date& other) const
    {
        return this->uniqueDateValue() > other.uniqueDateValue();
    }

    const Status& Date::state()
    {
        return status;
    }

    Date& Date::formatted(bool format)
    {
        if (format == false) 
        {
            m_Formatted = false; 
        }
        return *this;
    }

    Date::operator bool() const
    {
        return status; 
    }

    std::istream& Date::read(std::istream& istr)
    {
        int date; 

        istr >> date;

        if (istr.fail())
        {
            std::cout << "Invalid date value";
        }
        else
        {
            if (date < 10000)
            {
                ut.getSystemDate(&m_Year);
                m_Day = date % 100;
                m_Month = date / 100;
            }
            else
            {
                m_Year = (date / 10000) + 2000;
                m_Day = date % 100;
                m_Month = (date / 100) % 100;
            }

            if (!validate())
            {
                istr.istream::setstate(ios::badbit);
            }
        }

        return istr;

    }

    std::ostream& Date::write(std::ostream& ostr) const 
    {

        if (m_Formatted == true)
        {
            ostr << m_Year; 
            ostr << '/';
            ostr.fill('0');
            ostr.width(2);
            ostr << m_Month;
            ostr << '/';
            ostr.width(2);
            ostr << m_Day;
            ostr.fill(' ');
        }
        else if (m_Formatted == false)
        {
            int year = m_Year - 2000;
            ostr << year;
            ostr.fill('0');
            ostr.width(2);
            ostr << m_Month;
            ostr.width(2);
            ostr << m_Day;
            ostr.fill(' ');
        }
        return ostr;
    }

    // Helper Insertion operator
    std::ostream& operator<<(std::ostream& ostr, const Date& date)
    {
        return date.write(ostr);  
    }

    // Helper Extraction operator
    std::istream& operator>>(std::istream& istr, Date& date)
    {
        return date.read(istr);  
    }


} // namespace sdds