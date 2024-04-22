#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Status.h"
#include "Utils.h"

namespace sdds 
{
    Status::Status(const char* description)
    {
        m_Code = 0;
        if (description != nullptr)
        {
            ut.alocpy(m_Description, description); 
        }
    }

    void Status::setEmpty()
    {
        delete[] m_Description;
        m_Description = nullptr;
        m_Code = 0;
    }

    Status::Status(const Status& status) 
    {
        if (status.m_Description != nullptr)
        {
            ut.alocpy(m_Description, status.m_Description); 
            m_Code = status.m_Code; 
        }
        else
        {
            setEmpty();
        }
    }

    Status::~Status()
    {
        if (m_Description != nullptr)
        {
            delete[] m_Description;
            m_Description = nullptr;
        }
    } 

    Status& Status::operator=(int code)
    {
        m_Code = code;
        return *this;

    }
    Status& Status::operator=(const char* description)
    {
        if (description != nullptr)
        {
            ut.alocpy(m_Description, description);
        }
        return *this;
    }

    Status::operator bool() const
    {
        return m_Description == nullptr;
    }

    Status::operator int() const
    {
        return m_Code;
    }

    Status::operator const char*() const
    {
        return m_Description; 
    }

    Status& Status::clear()
    {
        if (m_Description != nullptr) 
        {
            setEmpty();
        }
        return *this;
    }

    std::ostream& Status::print(std::ostream& ostr) const
    {
        if (m_Code == 0)
        {
            ostr << m_Description;
        }
        else
        {
            ostr << "ERR#" << m_Code << ": ";
            ostr << m_Description; 
        }
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Status& status)  
    {
        if (status)
        {
            // do nothing
        }
        else
        {
            status.print(ostr); 
        }
        return ostr;
    }

}  // namespace sdds