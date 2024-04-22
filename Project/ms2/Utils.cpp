/***********************************************************************
// Final project Milestone 1
// Module: Utils
// File: Utils.h
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <ctime>
#include "Utils.h"

namespace sdds
{
    // The ut object of type Utils that is accessible to any file including "Utils.h" to call the Utils methods
    Utils ut;

    void Utils::testMode(bool testmode)
    {
        m_testMode = testmode;
    }

    void Utils::getSystemDate(int* year, int* mon, int* day)
    {
        if (m_testMode)
        {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else
        {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }

    int Utils::daysOfMon(int month, int year)const
    {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

    void Utils::alocpy(char*& destination, const char* source)
    {
        delete[] destination;
        destination = nullptr;
        if (source != NULL)
        {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
    }

    int Utils::Utils::getint(const char* prompt)
    {
        int value{};
        bool done{};
        bool promptPrinted = false;

        if (prompt != nullptr)
        {
            promptPrinted = true;
            do
            {
                if (!promptPrinted)
                {
                    std::cout << prompt;
                    promptPrinted = true;
                }

                done = false;
                std::cin >> value;

                if (std::cin)   // if(!cin.fail()){ 
                {
                    if (std::cin.get() != '\n')  // if the next char after int is not newline 
                    {
                        std::cout << "Only an integer please, retry: ";
                    }
                    else
                    {
                        done = true;
                    }
                }
                else
                {
                    std::cin.clear(); // clear the fail state 
                    std::cout << "Invalid Integer, retry: ";
                }
                //if (!done) cin.ignore(10000, '\n');
                (!done) && std::cin.ignore(10000, '\n'); // same but quicker 
            } while (!done);
        }
        return value;
    }


    int Utils::getint(int min, int max, const char* prompt, const char* errMes) {
        int value{};
        bool promptPrinted = false;
        // if (prompt) std::cout << prompt;
        do
        {
            if (!promptPrinted)
            {
                std::cout << prompt;
                promptPrinted = true;
            }

            value = getint(prompt);

        } while ((value < min || value > max) && std::cout << "Value out of range [" << min << "<=val<=" << max << "]: ");
        return value;

    }

}  // namespacs sdds