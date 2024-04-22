#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds
{
   FILE* fptr;
   bool openFile(const char filename[]) 
   {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   void closeFile()
   {
      if (fptr) fclose(fptr);
   }

}