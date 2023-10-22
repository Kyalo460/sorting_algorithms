#include "sort.h"
#include "stdio.h"
#include "stdbool.h"
/**
 * quick_sort - a quick sort algorithm that sorts integers in ascending order
 * @array: the integert array to sort
 * @size: the number of elements in the array
*/
void quick_sort(int *array, size_t size)
{
	size_t hold = 0, iterate = 0, pivot = size - 1, index;
	int temp;
	bool check = false, swap = false;

	pivot = size - 1;

	for (index = 0; index < size && pivot > 0; index++)
	{
		swap = false;
		check = false;
		for (iterate = 0; iterate < pivot; iterate++)
		{
			if (array[iterate] > array[pivot])
			{
				if (check == false)
				{
					hold = iterate;
					check = true;
				}
			}
			if (array[iterate] < array[pivot] && check)
			{
				temp = array[hold];
				array[hold] = array[iterate];
				array[iterate] = temp;
				hold = iterate;
				print_array(array, size);
			}
			if (iterate == pivot - 1 && check)
			{
				temp = array[pivot];
				array[pivot] = array[hold];
				array[hold] = temp;
				swap = true;
				print_array(array, size);
			}
		}
		if (swap == false)
			pivot--;
	}
}
