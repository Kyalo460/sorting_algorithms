#include "sort.h"

/**
 * selection_sort - sorts an array of intergers using selection sort algorithm
 * @array: the array of integers to sort
 * @size: the number of elements in the array
*/
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t index1 = 0, index2, smallest;

	if (size < 2)
		return;

	while (index1 < size)
	{
		smallest = index1;
		for (index2 = index1 + 1; index2 < size; index2++)
		{
			if (array[smallest] > array[index2])
				smallest = index2;
		}
		if (smallest != index1)
		{
			temp = array[index1];
			array[index1] = array[smallest];
			array[smallest] = temp;
			print_array(array, size);
		}
		index1++;
	}
}
