#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds
{

    struct Population
    {
        char postalCode[4];
        int population;
    };
   // returns true of the cstring starts with subString
   bool startsWith(const char* cString, const char* subString);
   // Receives a user entry for a partial postal code prefix into the postal_code_prefix address. 
   // If the user enters ! it returns false, otherwise it will return true.
   bool getPostalCode(char* postal_code_prefix);
   // Loads all the records with the postal code that starts with partial_postal_code_prefix into a dynamically allocated array of Population. 
   // The size of the dynamic array must be equal to the number of matches.
   bool load(const char* filename, const char* partial_postal_code_prefix);
   // This function is an insertion sorting technique to select the key data in each iteration and place them in the rightful location
   void sort();
   // A function with no parameters that returns nothing and prints the report - Derived from Part 1
   void display();
   // Function to deallocate the dynamic memory allocated by new - Derived from part 1
   void deallocateMemory();
 

}
#endif // SDDS_POPULATION_H_