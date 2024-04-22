#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Status.h"
#include "Utils.h"

namespace sdds
{
    void Status::setEmpty()
    {
        delete[] m_description;
        m_description = nullptr;
        m_code = 0;
    }

    void Status::set(const char* desc, int code)
    {
        m_code = code; // defaults to 0

        if (desc != nullptr)
        {
            ut.alocpy(m_description, desc);
        }
        else
        {
            setEmpty();
        }

    }

    Status::Status(const char* desc) { set(desc); }

    Status::Status(const Status& status) { set(status.m_description, status.m_code); }

    Status& Status::operator=(const Status& status)
    {
        if (this != &status)
        {
            set(status.m_description, status.m_code);
        }

        return *this;
    }

    Status::~Status() { setEmpty(); }

    Status& Status::operator=(const int code)
    {
        m_code = code;
        return *this;
    }

    Status& Status::operator=(const char* desc)
    {
        ut.alocpy(m_description, desc);
        return *this;
    }

    Status::operator int() const { return m_code; }

    Status::operator const char* () const { return m_description; }

    // no description is valid state
    Status::operator bool() const { return m_description == nullptr; }

    Status& Status::clear()
    {
        // deallocates the description and sets the code to zero
        setEmpty();
        return *this;
    }

    std::ostream& operator<<(std::ostream& ostr, const Status& status)
    {
        // if invalid state
        if (!status)
        {
            // print the code only if it is not zero
            if (int(status) != 0)
                ostr << "ERR#" << int(status) << ": ";
            ostr << (const char*)(status);
        }
        return ostr;
    }

}  // namespace sdds
