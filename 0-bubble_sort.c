#include "sort.h"
#include <stdbool.h>
/**
 * bubble_sort - sorts an array of integers using bubble sort algorithm
 * @array: the array of integers
 * @size: the size of the array
*/
void bubble_sort(int *array, size_t size)
{
    bool changes = true;
    size_t index;
    int temp;
    size_t end_index = size - 1;

    if (size <= 1)
        return;

    while (changes)
    {
        changes = false;
        for (index = 0; index < end_index; index++)
        {
            if (array[index] > array[index + 1])
            {
                changes = true;
                temp = array[index + 1];
                array[index + 1] = array[index];
                array[index] = temp;
                print_array(array, size);
            }
        }
        end_index--;
    }
}
