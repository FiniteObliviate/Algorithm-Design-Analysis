#ifndef SORT_HEAPSORT_H
#define SORT_HEAPSORT_H

#include <vector>

// index starts from 0
inline int Left(int i) { return 2 * i + 1; }

inline int Right(int i) { return 2 * i + 2; }

inline int Parent(int i) { return (i - 1) / 2; }

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void MaxHeapify(std::vector<int>& nums, int i, int heap_size)
{
	int L = Left(i), R = Right(i);
	int largest_index = i;
	if (L <= heap_size && nums[i] < nums[L])
		largest_index = L;
	if (R <= heap_size && nums[largest_index] < nums[R])
		largest_index = R;

	if (largest_index != i)
	{
		Swap(&nums[largest_index], &nums[i]);
		MaxHeapify(nums, largest_index, heap_size);
	}
}

void BuildHeap(std::vector<int>& nums)
{
	int s = nums.size();
	for (int i = s / 2 ; i >= 0; i--)  //必须自底向上，否则不满足循环不变式
		MaxHeapify(nums, i, s - 1);
}

void HeapSort(std::vector<int>& nums)
{
	int s = nums.size() - 1;
	BuildHeap(nums);
	for (int i = s; i >= 0; i--)
	{
		Swap(&nums[i], &nums[0]);
		s--;
		MaxHeapify(nums, 0, s);
	}
}


#endif