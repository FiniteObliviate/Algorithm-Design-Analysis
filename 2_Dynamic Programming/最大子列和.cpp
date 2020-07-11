// 最大子列和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<vector>
#include"util.hpp"

using namespace std;

int MaxElement(vector<int> A)
{
	int N = A.size();
	int max = INT_MIN;
	for (int i = 0; i < N; i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

int MaxSubsequenceSum(vector<int> A) 
{
	//求最长连续子列和
	int N = A.size();
	int i = 0, MAX = 0, sum = 0;
	//for (i = 0; i < N; i++)
	//{
	//	if (A[i] < 0)
	//		count++;
	//}
	//if (count == N)
	//{
	//	MAX = INT_MIN;
	//	for (i = 0; i < N; i++)
	//	{
	//		if (A[i] > MAX)
	//			MAX = A[i];
	//	}
	//}
	//else
	//{
	//	for (i = 0; i < N; i++)
	//	{
	//		sum = sum + A[i];
	//		if (sum > MAX)
	//			MAX = sum;
	//		else if (sum < 0)
	//			sum = 0;
	//	}
	//}
	for (; i < N; i++)  //遍历所有元素
	{
		sum = sum + A[i];  //依次向后累加
		if (sum > MAX)  //如果当前子列和大于历史最大值，则更新MAX
			MAX = sum;
		else if (sum < 0)  //如果当前子列和为负，则将sum重置为0
			sum = 0;
	}
	if (MAX == 0)  //如果MAX为0，意味着数组A中没有正数
		MAX = MaxElement(A); //这时返回数组中A中的最大值
	return MAX;

}

int main() {
	//简单测试
	vector<int> A = { -2, 11, -4, 13, -5, -2 };
	cout << MaxSubsequenceSum(A) << endl;
	//测试
	TestMaxSubsequenceSum(MaxSubsequenceSum);
	Pause();
	return 0;
}
