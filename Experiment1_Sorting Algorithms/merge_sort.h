#ifndef SORT_MERGESORT_H
#define SORT_MERGESORT_H

#include <vector>
#include <algorithm>

// Here you can fill with your function definition instead of mine!
void Merge(std::vector<int>& nums, std::vector<int>& m1, std::vector<int>& m2)
{
	int s1 = m1.size();
	int s2 = m2.size();
	int i1 = 0, i2 = 0;
	while (i1 < s1 || i2 < s2)
	{
		if (i1 >= s1)
			nums.push_back(m2[i2++]);
		else if (i2 >= s2)
			nums.push_back(m1[i1++]);
		else if (m1[i1] < m2[i2])
			nums.push_back(m1[i1++]);
		else
			nums.push_back(m2[i2++]);
	}
}

void MergeSort(std::vector<int>& nums) 
{  
	int s = nums.size();
    if (s <= 1)
		return;
	std::vector<int> v1;
    std::vector<int> v2;
    for (int i = 0; i < s; i++)
    {
		if (i < s / 2)                     
			v1.push_back(nums[i]);    
		else                      
			v2.push_back(nums[i]);      
	}         
	MergeSort(v1);
	MergeSort(v2);
	nums.clear();
	Merge(nums, v1, v2);
	//sort(nums.begin(), nums.end());
}


// recursion
void MergeSortAux(std::vector<int>& nums, std::vector<int>& tmp, int left, int right)
{

	// TODO
}

#endif