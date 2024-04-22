#include "Population.h"
using namespace sdds;

int main()
{
    char postal_code_prefix[4];
    while (getPostalCode(postal_code_prefix))
    {
        if (load("PCpopulationsComplete.csv", postal_code_prefix)) 
        {
            
            display();
        }
        deallocateMemory();
    }
    return 0;
}