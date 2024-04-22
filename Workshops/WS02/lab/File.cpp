#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <string.h>
#include "File.h"

namespace sdds 
{
   FILE* fptr;
   bool openFile(const char filename[]) 
   {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() 
   {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) 
      {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() 
   {
      if (fptr) fclose(fptr);
   }


   // TODO: read functions go here    
   // Reads the name of the employee | Receives as a parameter a pointer to an array of characters
   bool read(char*& name) 
   {
       // Create a local area to store the name
       char buffer[128];

       // Attempt to read the name from the file
       if (fscanf(fptr, "%127[^\n]\n", buffer) == 1)   
       {
           // Calculate the length of the scanned name
           int length = strlen(buffer);  

           // Allocate dynamic memory for the name using new[] 
           name = new char[length + 1];    
           
           // Copy the name to the dynamically allocated memory
           strcpy(name, buffer); 
           return true; // Successfully read the name
       }
       else
       {
           return false;  // Reading Failed 
       }

     
   }

   // Recieves a reference to an interger in its parameter and reads an employee number
   bool read(int& empNum)
   {
       if (fscanf(fptr, "%d,", &empNum) == 1)
       {
           return true;
       }
       else
       {
           return false;
       }

   }



   // Recieves a reference to a double precision number as a parameter and reads the employee salary
   bool read(double& salary)
   {
       if (fscanf(fptr, "%lf,", &salary) == 1) 
       {
           return true;
       }
       else
       {
           return false;
       }

   }


  
}