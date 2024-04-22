#ifndef SDDS_SELECTION_H
#define SDDS_SELECTION_H
#include <cstring>

namespace sdds
{
    /// <summary>
    /// Iterates through the array to find occurrences of the specified key.
    /// Stores the indices of these occurrences in a dynamically allocated array, with a terminator - 1 at the end.
    /// Properly manages memory to avoid leaks by dynamically allocating the array.
    /// </summary>
    /// <typeparam name="arrayType"></typeparam>
    /// <typeparam name="keyType"></typeparam>
    /// <param name="array"></param>
    /// <param name="key"></param>
    /// <param name="size"></param>
    /// <returns> A pointer to a new dynamically allocated array</returns>
    // Function template to select indices where key is found in the array
    template <typename arrayType, typename keyType>
    int* select(const arrayType array[], const keyType& key, size_t size) 
    {
        // Allocate space for indices and one extra element for the terminator -1
        int* indices = new int[size + 1];
        int count = 0;  // Count of occurrences

        // Iterate through the array to find occurrences of the key
        for (size_t i = 0; i < size; ++i) 
        {
            if (array[i] == key) // Check if key equals ith element in array
            {
                indices[count++] = static_cast<int>(i);  // Store the index
            }
        }

        indices[count] = -1;  // Terminator

        return indices;
    }

    

    /// <summary>
    /// Checks if the indices array is not null and not empty.
    /// If not empty, iterates through the indices array and displays the corresponding elements from the original array.
    /// Formats the output as a comma - separated list.
    /// If the indices array is empty, displays "Empty Selection."
    /// </summary>
    /// <typeparam name="arrayType"></typeparam>
    /// <param name="title"></param>
    /// <param name="array"></param>
    /// <param name="indices"></param>
     /// <returns> void </returns>
    // Function template to display elements at specified indices as a comma-separated list
    template <typename arrayType>
    void csvDisplaySelection(const char* title, const arrayType array[], const int* indices)
    {
        std::cout << title << std::endl;

        // Check if indices is not null and not empty
        if (indices && indices[0] != -1)
        {
            // Iterate through indices and display corresponding elements
            for (int i = 0; indices[i] != -1; ++i)
            {
                std::cout << array[static_cast<size_t>(indices[i])];

                if (indices[i + 1] != -1)
                {
                    std::cout << ", ";  // Add comma if not the last element
                }
            }
        }
        else
        {
            std::cout << "Empty Selection";
        }

        std::cout << std::endl;
    }

}  // namespace sdds

#endif // !SDDS_SELECTION_H
