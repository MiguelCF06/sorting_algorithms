#include "sort.h"
/**
 * divide - split array to sort
 * @array: array to sort
 * @l_value: index of lower value
 * @h_value: index of higher value
 * @size: size of array
 * Return: index of partition
 */
int divide(int *array, int l_value, int h_value, size_t size)
{
	int pivot = array[h_value];
	int i = l_value, j, tmp;

	for (j = l_value; j < h_value; j++)
	{
		if (array[j] < pivot)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	tmp = array[i];
	array[i] = array[h_value];
	array[h_value] = tmp;
	if (i != h_value)
		print_array(array, size);
	return (i);
}
/**
 * recu_quick - recursive function to sort array
 * @array: array to sort
 * @l_value: index of lower value
 * @h_value: index of higher value
 * @size: size of array
 */
void recu_quick(int *array, int l_value, int h_value, size_t size)
{
	int resul;

	if (l_value < h_value)
	{
		resul = divide(array, l_value, h_value, size);
		recu_quick(array, l_value, resul - 1, size);
		recu_quick(array, resul + 1, h_value, size);
	}
}


/**
 * quick_sort - sort an array of integer using quic sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size > 1)
		recu_quick(array, 0, size - 1, size);
}
