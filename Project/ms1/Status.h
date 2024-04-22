#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H

namespace sdds 
{
    class Status
    {
    private:
        char* m_Description{};
        int m_Code;

    public:
        // Default Constructor to create a Status object with or without a C-String as a description
        Status(const char* description = nullptr);
        // Sets the Status object to an Empty state
        void setEmpty(); 
        // Rule of three: Deep Copy constructor -> shallow copies non-resource instance variables and deep copies resource instance variables
        Status(const Status& status);  
        // Rule of three: Destructor for memory dealloaction and leak prevention
        virtual ~Status(); 
        // Casting a Status object to an interger returns the code
        Status& operator= (int code);
        // Casting a Status object to a constant character pointer returns the description
        Status& operator= (const char* description);
        // Casting a Status object to a boolean returns true if description is null and false otherwise.
        operator bool() const;
        // Query to get code
        operator int() const;
        // Query to get the description
        operator const char* () const;
        // Safely deallocates the description and sets the code to zero and returns a reference of the current object
        Status& clear();
        // Displays a Status object -> Localizes the logic for the helper function
        std::ostream& print(std::ostream& ostr) const;
      
    };
    
    // Helper Operator (Insertion operator)
    // Print the Status only if it is in a bad (false) state i e Status has no description
    std::ostream& operator<<(std::ostream& ostr, const Status& status);

}
#endif  // !SSDS_STATUS_H
