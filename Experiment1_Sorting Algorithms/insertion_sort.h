#ifndef SORT_INSERTIONSORT_H
#define SORT_INSERTIONSORT_H

#include <algorithm>
#include <vector>


void InsertionSort(std::vector<int>& nums) 
{
	int s = nums.size();
	for (int i = 1; i < s; i++)
	{
		int j = i - 1;
		int t = nums[i];
		if (nums[j] > nums[i])
		{
			//int j = i - 1;
			int t = nums[i];
			while (j > -1 && t < nums[j])
			{
				nums[j + 1] = nums[j];
				j--;
			}
			nums[j + 1] = t;
		}
	}
}

#endif