#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort()
    {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (employees[j].m_empNo > employees[j + 1].m_empNo)
                {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument return the combined success result of the three read functions. These read 
    // functions should set the properties of the reference argument of the load function
    bool load(Employee& employee)
    {
        bool ok = false;

         // Upon succesful reading of the employee number, salary and name
        if (read(employee.m_empNo) && read(employee.m_salary) && read(employee.m_name)) 
        {
            
            ok = true;
        }
        return ok;
    }



 // TODO: Finish the implementation of the 0 arg load function 
    bool load()
    {
        bool ok = false;
        int i = 0;

        if (openFile(DATAFILE))
        {
            // Determine the number of employees in the file and store it in 'noOfEmployees'.
            noOfEmployees = noOfRecords();

            // Create a dynamic array of employees and assign it to the global pointer 'employees'.
            // The size of the array matches the 'noOfEmployees'.
            employees = new Employee[noOfEmployees];

            // Use a loop to read employee records from the file and load them into the dynamic array.
            for (int j = 0; j < noOfEmployees; j++)
            {
                // Increment 'i' to keep track of successful file reads
                i += load(employees[j]);
            }

            // If 'i' does not match 'noOfEmployees', there may be a data corruption issue. print message
            if (i != noOfEmployees)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else
            {
                ok = true; // Loading successful.
            }

            closeFile();
        }
        else
        {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }

    // TODO: Implementation for the display functions go here
    void display(const Employee& emp)
    {
        cout << emp.m_empNo << ": " << emp.m_name << ", $" << emp.m_salary << endl; 
    }

    void display()
    {
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;

        sort();

        for (int i = 0; i < noOfEmployees; i++)
        {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }


    // TODO: Implementation for the deallocateMemory function goes here

    // Function that first will deallocate all the names in the employee elements
    // then it will deallocate the employee array 
    void deallocateMemory()
    {
        for (int i = 0; i < noOfEmployees; i++)
        {
            // Deleting dynamically allocated memory for employee names
            delete[] employees[i].m_name;
        }

        // Delete struct for employees
        delete[] employees;
        employees = nullptr;
    }

}
