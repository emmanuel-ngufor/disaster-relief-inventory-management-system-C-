#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include "Status.h"  

namespace sdds
{
    // Constant Variable
    const int MAX_YEAR_VALUE = 2030;

    class Date
    {
        int m_year;
        int m_month;
        int m_day;
        Status m_state;
        bool m_formatted = true;
        // Private Methods
        bool validate();
        int uniqueDateValue() const;
        void set(int year, int month, int day);

    public:
        // Constructors
        Date(int year = 0, int month = 0, int day = 0);

        // Operator overloads for comparison using uniqueDateValue() -> six ==, !=, <, >, <=, >=
        bool operator== (const Date& other) const;
        bool operator!= (const Date& other) const;
        bool operator>= (const Date& other) const;
        bool operator<= (const Date& other) const;
        bool operator<  (const Date& other) const;
        bool operator>  (const Date& other) const;

        // State Accessor
        const Status& state() const;
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