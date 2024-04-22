#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include "Status.h"   // Ask professor how to fix this

namespace sdds
{
    // Constant Variable
    const int MAX_YEAR_VALUE = 2030;

    class Date
    {
        Status status; 
        int m_Year;
        int m_Month;
        int m_Day;
        bool m_Formatted;
        bool m_Invalid;
        // Private Methods
        bool validate();
        int uniqueDateValue() const;

    public:
        // Constructors
        Date();
        Date(int year, int month, int day);

        // Operator overloads for comparison using uniqueDateValue() -> six ==, !=, <, >, <=, >=
        bool operator== (const Date& other) const;
        bool operator!= (const Date& other) const;
        bool operator>= (const Date& other) const;
        bool operator<= (const Date& other) const;
        bool operator<  (const Date& other) const;
        bool operator>  (const Date& other) const;

        // State Accessor
        const Status& state();
        // Formatted Modifier
        Date& formatted(bool format);
        // bool conversion overload
        operator bool() const;
        // Write Menthod
        std::ostream& write(std::ostream& ostr) const; 
        // Read Methodc
        std::istream& read(std::istream& istr);
       
    };

    // Helper Insertion and Extraction operators
    std::ostream& operator<<(std::ostream& ostr, const Date& date);
    std::istream& operator>>(std::istream& istr, Date& date);

} // namespace sdds


#endif // !SDDS_DATE_H