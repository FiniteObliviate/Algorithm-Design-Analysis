// 3SUM.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

// 内有一个随机数生成函数
#include "gen_rnd.h"
// 计时器
#include "timer.h"
#include "util.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <stack>
#include <map>
#include <string>

using namespace std;
//同实验三中的性能比较函数，可用与比较不同算法的性能
void PerformanceComparsion();

int BinarySearch(vector<int> nums, int target)
{
	int pivot, left = 0, right = nums.size() - 1;
	while (left <= right)
	{
		pivot = left + (right - left) / 2;
		if (nums[pivot] == target)
			return 1;
		if (target < nums[pivot])
			right = pivot - 1;
		else
			left = pivot + 1;
	}
	return 0;
}

int BinarySearchP(vector<int> nums, int target)
{
	int pivot, left = 0, right = nums.size() - 1;
	while (left <= right)
	{
		pivot = left + (right - left) / 2;
		if (nums[pivot] == target)
			return pivot;
		if (target < nums[pivot])
			right = pivot - 1;
		else
			left = pivot + 1;
	}
	return NULL;
}

vector<vector<int>> ThreeSum(vector<int> A, vector<int> B, vector<int> C)
{
	vector<vector<int>> result;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	vector<int> sum;
	for (int j = 0; j < B.size(); j++)
	{
		for (int i = 0; i < A.size(); i++)
		{
			sum.push_back(A[i] + B[j]);
			//sum[i + j] = A[i] + B[j];
		}
	}
	for (int k = 0; k < C.size(); k++)
	{
		//if (BinarySearch(sum, C[k]))  //通过二分查找来看b是否存在于B中
		//{
		//	int p = BinarySearchP(sum, C[k]);
		//	int j = p / B.size();
		//	int i = p - j * B.size();
		//	vector<int> temp = { A[i], B[j], C[k] };
		//	result.push_back(temp);
		//}
		for (int p = 0; p < sum.size(); p++)
		{
			if (sum[p] == C[k])
			{
				int j = p / B.size();
				int i = p - j * B.size();
				vector<int> temp = { A[i], B[j], C[k] };
				result.push_back(temp);
			}
		}
	}
	return result;
}

//vector<vector<int>> ThreeSum(vector<int> A, vector<int> B, vector<int> C)
//{
//	vector<vector<int>> result;
//	sort(B.begin(), B.end());
//	for (int k = 0; k < C.size(); k++)
//	{
//		for (int i = 0; i < A.size(); i++)
//		{
//			//确定了和C[k]、一个加数A[i]后，则另一个加数应为b
//			int b = C[k] - A[i];
//			if (BinarySearch(B, b))  //通过二分查找来看b是否存在于B中
//			{
//				vector<int> temp = { A[i], b, C[k] };
//				result.push_back(temp);
//			}
//		}
//	}
//	return result;
//}


//输入三个向量，首先将求得的答案存入一个向量中，再将所有答案存入一个结果向量中
//vector<vector<int>> ThreeSum(vector<int> A, vector<int> B, vector<int> C)
//{
//	//定义一个结果向量，其中存放的是三个数为一组答案的多个向量（可以理解为二维数组）
//	vector<vector<int>> result;
//	sort(A.begin(), A.end());
//	sort(B.begin(), B.end());
//	for (int k = 0; k < C.size(); k++)
//	{
//		int i = 0, j = B.size() - 1;  //A从前往后，B从后往前进行遍历寻找
//		while (i < A.size() && j >= 0)
//		{
//			if (A[i] + B[j] == C[k])  //正确组合，存入结果向量result
//			{
//				vector<int> temp = { A[i], B[j], C[k] };
//				result.push_back(temp);
//				i++;  //可能还有别的组合的和为C[k]，需继续遍历
//			}
//			else if (A[i] + B[j] > C[k])  //如果A[i] + B[j] > C[k]，说明当前和太小，应该往使和增大的方向移动
//				j--;
//			else  //此时A[i] + B[j] < C[k]，说明当前和太大，应该往使和减小的方向移动
//				i++;
//		}
//	}
//	return result;
//}

//3SUM的普通求法，可用于比较性能
vector<vector<int>> ThreeSumBruteForce(vector<int> A, vector<int> B, vector<int> C)
{
	vector<vector<int>> result;
	for (int k = 0; k < C.size(); k++)
	{
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 0; j < B.size(); j++)
			{
				if (A[i] + B[j] == C[k])
				{
					vector<int> temp = { A[i], B[j], C[k] };
					result.push_back(temp);
				}
			}
		}
	}
	return result;
}

int main()
{
	//3SUM简单测试
	cout << "A simple test of three sum:" << endl;
	vector<int>	A = { 1 ,2, 5, -3, 8 };
	vector<int> B = { 7, 9, 4, -2, 5 };
	vector<int> C = { 0, 6, 15, 22, 17 };

	vector<vector<int>> result1 = ThreeSum(A, B, C);
	cout << "Result of my algorithm:" << endl;
	OutputThreeSumResult(result1);
	vector<vector<int>> result2 = ThreeSumBruteForce(A, B, C);
	cout << "Result of brute force:" << endl;
	OutputThreeSumResult(result2);

	//测试3SUM函数是否正确
	cout << "Test of three sum:" << endl;
	if (TestThreeSum(ThreeSum))
	{
		PerformanceComparsion();
	}
	// 按任意键继续
	Pause();
	return 0;
}


void PerformanceComparsion()
{
	// 比较3sum函数的性能？。
	Timer timer; //计时器
	// 生成三组随机数
	const size_t n = 100;      // 自行定义n的大小
	vector<int>	A = GenUniqueRand(n, 0, n); // 生成n个随机数， 数据范围为[0, n]
	vector<int> B = GenUniqueRand(n, 0, n);
	vector<int> C = GenUniqueRand(n, 0, 33 * n);

	timer.Start();
	ThreeSumBruteForce(A, B, C);
	timer.Stop();

	double time = timer.GetElapsedMilliseconds();
	cout << "3SUM(brute force) for " << n << " numbers takes " << time << " ms" << endl;
	// 睡眠1000ms， 等待cpu清空缓存
	Sleep(1000);

	timer.Start();
	ThreeSum(A, B, C);
	timer.Stop();
	time = timer.GetElapsedMilliseconds();

	cout << "3SUM(my algorithm) for " << n << " numbers takes " << time << " ms" << endl;
}

