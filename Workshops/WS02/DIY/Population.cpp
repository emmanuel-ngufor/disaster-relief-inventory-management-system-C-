#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <algorithm>
#include "Population.h"

using namespace std;

namespace sdds
{

    // Global Variables
    Population* pop = nullptr;
    int noOfPostalCodes = 0; 



    bool startsWith(const char* cstring, const char* subString)
    {
        return std::strstr(cstring, subString) == cstring;
    }


    // Receives a user entry for a partial postal code prefix into the postal_code_prefix address. 
   // If the user enters ! it returns false, otherwise it will return true.
    bool getPostalCode(char* postal_code_prefix) 
    {
        cout << "Population Report" << endl << "-----------------" << endl << "Enter postal code:" << endl << "> ";
        cin.getline(postal_code_prefix, 4);

        // Check if all is entered and read all postal cpdes setting the null terminator at index 0
        if (0 == strcmp(postal_code_prefix, "all"))
        {
            postal_code_prefix[0] = '\0';  
        }

        return strcmp(postal_code_prefix, "!") != 0 ? true : false; 
    }


    // Loads all the records with the postal code that starts with partial_postal_code_prefix into a dynamically allocated array of Population. 
    // The size of the dynamic array must be equal to the number of matches.
    bool load(const char* filename, const char* partial_postal_code_prefix) 
    {
        ifstream datafile(filename); 
        if (!datafile.is_open()) 
        {
            cout << "Error: Unable to open file " << filename << endl;
            return false;
        }

        // Determining the number of records
        noOfPostalCodes = 0; 
        string buffer;
        while (getline(datafile, buffer)) 
        {
            if (startsWith(buffer.c_str(), partial_postal_code_prefix))
            { 
                noOfPostalCodes++; 
            }
        }

        // Dynamic Memory Allocation sized to the number of records (postal codes)
        pop = new Population[noOfPostalCodes]; 

        // Set the record pointer to the beginning of the file
        datafile.clear(); 
        datafile.seekg(0, ios::beg);  
        int i = 0;
        while (getline(datafile, buffer))
        {
            if (startsWith(buffer.c_str(), partial_postal_code_prefix))  
            { 
                sscanf(buffer.c_str(), "%3s,%d", pop[i].postalCode, &pop[i].population);   
                i++;
            }
        }

      // Sort the postal codes by insertion sort
        sort();

        return true;
    }


    // This function is an insertion sorting technique to select the key data in each iteration and place them in the rightful location
    void sort()
    {
        int i, k;
        Population keyValue; 
        for (i = 1; i < noOfPostalCodes; i++) 
        {
            keyValue = pop[i];
            for (k = i - 1; k >= 0 && pop[k].population > keyValue.population; k--)
            {
                pop[k + 1] = pop[k];
            }

            pop[k + 1] = keyValue; 
        }
    }


    // A function with no parameters that returns nothing and prints the report - Derived from Part 1
    void display() {
        cout << "Postal Code: population" << endl << "-------------------------" << endl; 
        int totalPopulation = 0;
        for (int i = 0; i < noOfPostalCodes; i++) 
        {
            cout << i + 1 << "- " << pop[i].postalCode[0] << pop[i].postalCode[1] << pop[i].postalCode[2] << ":  " << pop[i].population << std::endl; 
            totalPopulation += pop[i].population;
        }
        cout << "-------------------------" << endl << "Population of the listed areas: " << totalPopulation << endl << endl;  
    }


    // Function to deallocate the dynamic memory allocated by new - Derived from part 1
    void deallocateMemory()
    {
        // Deallocating Memory
        delete[] pop;

        // Optional but good programming practice
        pop = nullptr; 
    }
}