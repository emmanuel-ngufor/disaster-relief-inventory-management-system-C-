#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h"

namespace sdds 
{

   // Student::Student() : m_name(nullptr), m_age(0) {}

    Student::Student(const char* name, int age) : m_age(age) 
    {
        if (name != nullptr)
        {
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name); 
        }
        else
        {
            m_name = nullptr;
        }
    }

    Student::Student(const Student& other)
    {
        m_name = nullptr; // Direct call of the copy constructor. Set all resources instance variables to nullptr and call the assignment operator
        *this = other;
    }

    Student& Student::operator=(const Student& other)
    {
        if (this != &other)    // Check for self Asignment
        {
            // Shallow copy non-resource instance variables
            m_age = other.m_age;

            // // deallocate previously allocated dynamic memory
            delete[] m_name;

            if (other.m_name != nullptr) 
            {
                // allocate new dynamic memory
                m_name = new char[strlen(other.m_name) + 1];
                // copy the resource data
                strcpy(m_name, other.m_name);
            }
            else 
            {
                m_name = nullptr;
            }
      
        }

        return *this;
    }

    Student::~Student() 
    {
        delete[] m_name;
    }

    const char* Student::getName() const 
    {
        return m_name ? m_name : "";
    }

    int Student::getAge() const 
    {
        return m_age;
    }

    void Student::display() const 
    {
        std::cout << "Name: " << getName() << std::endl;
        std::cout << "Age: " << getAge() << std::endl;
    }

} // namespace sdds