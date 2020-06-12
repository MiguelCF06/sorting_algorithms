#include "sort.h"
/**
 * bubble_sort - sort array using bubble sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, k = 0;
	int tmp = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				for (k = 0; k < size; k++)
				{
					if (k == size - 1)
						printf("%i\n", array[k]);
					else
						printf("%i ,", array[k]);
				}
			}
		}
	}
}
