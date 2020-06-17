#include "sort.h"
/**
 *
 *
 */
void radix_sort(int *array, size_t size)
{
	int ary[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int *n_ar = NULL, j, div = 10, num, max = 0;
	size_t i;

	n_ar = malloc(sizeof(int) * size);
	if (!n_ar)
		return;
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	
	for (i = 1; max / 10 != 0; i++)
		max /= 10;
	max = i;
	for (j = 0; j < max; j++)
	{
		for (i = 0; i < size; i++)
		{
			num = (array[i] % div) / (div/10);
			ary[num] += 1;
		}
		for (i = 1; i < 10; i++)
			ary[i] += ary[i - 1];
		for (i = 0; i < size; i++)
		{
			num = (array[size - 1 - i] % div) / (div/10);
			ary[num] -= 1;
			n_ar[ary[num]] = array[size - 1 - i];
		}

		for (i = 0; i < size; i++)
			array[i] = n_ar[i];
		for (i = 0; i < 10; i++)
			ary[i] = 0;
		div *= 10;
		print_array(array, size);
	}
	free(n_ar);
}
