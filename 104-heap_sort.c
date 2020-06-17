#include "sort.h"

/**
 *siftDown - The sift down routine
 *@array: Array to sort
 *@root: The root of the pile or heap
 *@end: The end of the pile
 *@size: Size of the array
 */
void siftDown(int *array, size_t root, size_t end, size_t size)
{
	size_t swap, right, left;
	int tmp;

	while ((left = (2 * root) + 1) <= end)
	{
		swap = root;
		right = left + 1;
		if (array[swap] < array[left])
			swap = left;
		if (right <= end && array[swap] < array[right])
			swap = right;
		if (swap == root)
			return;
		tmp = array[root];
		array[root] = array[swap];
		array[swap] = tmp;
		print_array(array, size);
		root = swap;
	}
}

/**
 *makeAPile - Makes like a pile or heap from the unsorted array
 *@array: Array to sort
 *@size: Size of the array
 */
void makeAPile(int *array, size_t size)
{
	size_t prnt;

	for (prnt = ((size - 1) - 1) / 2; 1; prnt--)
	{
		siftDown(array, prnt, size - 1, size);
		if (prnt == 0)
			break;
	}
}

/**
 *heap_sort - Sort an array of integers using the Heap Sort
 *algorithm
 *@array: Array to sort
 *@size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t final;
	int tmp;

	if (array == NULL || size < 2)
		return;

	makeAPile(array, size);
	final = size - 1;
	while (final > 0)
	{
		tmp = array[final];
		array[final] = array[0];
		array[0] = tmp;
		print_array(array, size);
		final--;
		siftDown(array, 0, final, size);
	}
}
