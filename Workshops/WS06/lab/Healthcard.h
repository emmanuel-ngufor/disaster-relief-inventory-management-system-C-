#pragma once
#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H 
namespace sdds
{
    const int MaxNameLength = 55;

    class HealthCard
    {
    private:
        char* m_name{};
        long long m_number;
        char m_vCode[3];
        char m_sNumber[10];
        // Returns true is the four parts of the ID card are valid
        bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;
        // Sets the HeathCard object to a recognizable empty (invalid) state by setting m_name to nullptr;
        void setEmpty();
        // Allocates and dealloactes the memory
        void allocateAndCopy(const char* name);
        // "peek()" and see if the next character in the keyboard buffer is the same as the ch argument and extracts the next character and ignores ch
        void extractChar(std::istream& istr, char ch) const;
        // Inserts the three parts related to the main card number, version code and stock number of the health card information into the ostr object in a given format
        std::ostream& printIDInfo(std::ostream& ostr)const;
        void set(const char* name, long long number, const char vCode[], const char sNumber[]);

    public:
        // Default Constructor
        HealthCard(const char* name = nullptr, long long number = 0, const char vCode[] = {}, const char sNumber[] = {});
        // If the hc object is valid it will set the values of the current object to those of the incoming argument(hc using assignment to* this).
        HealthCard(const HealthCard& hc);
        HealthCard& operator=(const HealthCard& hc);
        // Deletes the memory pointed by m_name.
        ~HealthCard();
        // Returns true if m_name is not nullptr, else it will return false
        operator bool() const;
        // If the current object is in a valid state it inserts the values of the card information in two different formats based on the value of the toFile argument:
        std::ostream& print(std::ostream& ostr, bool toFile = true) const;
        // Reads the Health Card information 
        std::istream& read(std::istream& istr);
    };

    // If hc is valid it will print it using the print function on the screen and not on File, (i.e. onFile is false). Otherwise, 
    // it will print "Invalid Card Number". In the end, it will return the ostr reference.
    std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc);

    // Returns the read method of the hc argument.
    std::istream& operator>>(std::istream& istr, HealthCard& hc);

}  // namespace sdds

#endif // !SDDS_HealthCard_H




