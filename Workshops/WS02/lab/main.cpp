#define _CRT_SECURE_NO_WARNINGS 
#include "Employee.h"
using namespace sdds;
int main()
{
   if(load()) 
   {
      display();
   }
   deallocateMemory();
   return 0;
}