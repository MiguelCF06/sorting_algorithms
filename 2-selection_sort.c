#include "sort.h"
/**
 * selection_sort - sort an array of integer using selection sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			for (j = 0; j < size; j++)
			{
				if (j != size - 1)
					printf("%i, ", array[j]);
				else
					printf("%i\n", array[j]);
			}
		}
	}
}
