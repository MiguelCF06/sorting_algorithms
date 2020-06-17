#include "sort.h"
/**
 *shell_sort - Sort an array of integers in ascending order using
 *the shell sort algorithm.
 *@array: The array to sort
 *@size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 0, outer, inner;
	int insert;

	while (interval <= size / 3)
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{
		for (outer = interval; outer < size; outer++)
		{
			insert = array[outer];
			inner = outer;
			while (inner > interval - 1 && array[inner - interval]
			       >= insert)
			{
				array[inner] = array[inner - interval];
				inner -= interval;
			}
			array[inner] = insert;
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
