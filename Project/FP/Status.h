#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H

namespace sdds
{
    class Status
    {
    private:
        char* m_description = nullptr;
        int m_code;
        void setEmpty();
        void set(const char* desc, int code = 0);

    public:
        Status(const char* desc = nullptr);
        Status(const Status& status);
        Status& operator=(const Status& status);
        virtual ~Status(); 
        Status& operator=(const int code);
        Status& operator=(const char* desc);
        operator int() const;
        operator const char* () const;
        operator bool() const;
        Status& clear();

    };

    // Helper Operator (Insertion operator)
    // Print the Status only if it is in a bad (false) state i e Status has no description
    std::ostream& operator<<(std::ostream& ostr, const Status& status);

}
#endif  // !SSDS_STATUS_H