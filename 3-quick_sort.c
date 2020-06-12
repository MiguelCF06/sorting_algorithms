#include "sort.h"
/**
 *
 *
 *
 *
 */
void recursive_qs(int *array, size_t piv, size_t ia, size_t size)
{
	int tmp, bol = 0;
	size_t save;

	save = ia;
	if (piv - ia < 3)
		bol++;
	while (piv > ia)
	{
		if (array[ia] < array[piv])
		{
			ia++;
			continue;
		}
		tmp = array[ia];
		array[ia] = array[piv - 1];
		array[piv - 1] = tmp;
		if (array[piv - 1] > array[piv])
		{
			tmp = array[piv];
			array[piv] = array[piv - 1];
			array[piv - 1] = tmp;
			piv--;
		}
		if (array[ia] < array[piv])
			ia++;
	}
	print_array(array, size);
	if (bol == 0)
	{
		if (piv <= save + 1)
			recursive_qs(array, size - 1, piv + 1, size);
		else if (piv > size - 3)
		{
			recursive_qs(array, piv - 1, save, size);
		}
		else
		{
			recursive_qs(array, piv - 1, 0, size);
			recursive_qs(array, size - 1, piv + 1, size);
		}
	}
	print_array(array, size);
	return;
}


/**
 * quick_sort - sort an array of integer using quic sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	recursive_qs(array, size - 1, 0, size);
}
