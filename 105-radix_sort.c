#include "sort.h"
/**
 * radix_sort - sort arrays with radix algorithm
 * @array: array
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int ary[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int *n_ar = NULL, div = 10, num, max = 0;
	size_t i;

	if (size == 0 || size == 1)
		return;
	n_ar = malloc(sizeof(int) * size);
	if (!n_ar)
		return;
	do {
		for (i = 0; i < size; i++)
		{
			if (div == 10)
			{
				if (array[i] > max)
					max = array[i];
			}
			num = (array[i] % div) / (div / 10);
			ary[num] += 1;
		}
		for (i = 1; i < 10; i++)
			ary[i] += ary[i - 1];
		for (i = 0; i < size; i++)
		{
			num = (array[size - 1 - i] % div) / (div / 10);
			ary[num] -= 1;
			n_ar[ary[num]] = array[size - 1 - i];
		}

		for (i = 0; i < size; i++)
			array[i] = n_ar[i];
		for (i = 0; i < 10; i++)
			ary[i] = 0;
		max /= 10, div *= 10;
		print_array(array, size);
	} while (max != 0);
	free(n_ar);
}
