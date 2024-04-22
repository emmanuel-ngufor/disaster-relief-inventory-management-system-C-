#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Graduate.h"

namespace sdds
{

   // Graduate::Graduate() : m_thesisTitle(nullptr), m_supervisor(nullptr) {}

    Graduate::Graduate(const char* name, int age, const char* thesisTitle, const char* supervisor) : Student(name, age) 
    {
        if (thesisTitle != nullptr) 
        {
            m_thesisTitle = new char[strlen(thesisTitle) + 1];
            strcpy(m_thesisTitle, thesisTitle);
        }
        else 
        {
            m_thesisTitle = nullptr;
        }

        if (supervisor != nullptr) 
        {
            m_supervisor = new char[strlen(supervisor) + 1];
            strcpy(m_supervisor, supervisor);
        }
        else 
        {
            m_supervisor = nullptr;
        }
    }

    Graduate::Graduate(const Graduate& other) : Student::Student(other)
    {
        m_supervisor = nullptr;  
        m_thesisTitle = nullptr; 
        *this = other;
    }

    Graduate& Graduate::operator=(const Graduate& other) 
    {
        if (this != &other)
        {
            Student::operator=(other);

            delete[] m_thesisTitle;
            delete[] m_supervisor;

            if (other.m_thesisTitle != nullptr)
            {
                m_thesisTitle = new char[strlen(other.m_thesisTitle) + 1];
                strcpy(m_thesisTitle, other.m_thesisTitle);
            }
            else
            {
                m_thesisTitle = nullptr;
            }

            if (other.m_supervisor != nullptr) 
            {
                m_supervisor = new char[strlen(other.m_supervisor) + 1];
                strcpy(m_supervisor, other.m_supervisor);
            }
            else
            {
                m_supervisor = nullptr;
            }
        }

        return *this;
    }

    Graduate::~Graduate() 
    {
        delete[] m_thesisTitle;
        delete[] m_supervisor;
    }

    void Graduate::display() const 
    {
        Student::display();
        std::cout << "Thesis Title: " << (m_thesisTitle ? m_thesisTitle : "N/A") << std::endl;
        std::cout << "Supervisor: " << (m_supervisor ? m_supervisor : "N/A") << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }

} // namespace sdds