// 实验2_最大子列和.cpp : 分治法求最长连续子列和

#include<iostream>
#include<vector>
#include"util.hpp"
using namespace std;

int Max(int A, int B, int C)
{ 
	return A > B ? A > C ? A : C : B > C ? B : C;
}

int MaxSubsequenceSum(vector<int> A)
{
	int MAX = INT_MIN;
	int s = A.size();
	//cout << "present vector size" << s << endl;
	if (s == 1)  //递归终止条件：vector A只含一个数
	//{
		//if (A[0] > 0)
			return A[0];
		//else
			//return 0;
	//}

	int center = s / 2;  //中点
	std::vector<int> L;
	std::vector<int> R;
	for (int i = 0; i < s; i++) 
	{
		if (i < center)
			L.push_back(A[i]);  //左子列
		else
			R.push_back(A[i]);  //右子列
	}

	//递归求得左右子列的最大和
	int MaxL = MaxSubsequenceSum(L);
	int MaxR = MaxSubsequenceSum(R);

	int sl = L.size();
	int sr = R.size();
	//求跨分界线的最大子列和
	int MaxLB = INT_MIN;  //左边界最大子列和
	int LB = 0;
	for (int i = sl - 1; i >= 0; i--)
	{
		LB += L[i];
		if (LB > MaxLB)
			MaxLB = LB;
	}

	int MaxRB = INT_MIN;  //右边界最大子列和
	int RightBorderSum = 0;
	for (int i = 0; i < sr; i++)
	{
		RightBorderSum += R[i];
		if (RightBorderSum > MaxRB)
			MaxRB = RightBorderSum;
	}

	MAX = Max(MaxL, MaxR, MaxLB + MaxRB);
	return MAX;
}

int main() 
{
	//简单测试
	vector<int> A = { -2, 11, -4, 13, -5, -2 };
	cout << MaxSubsequenceSum(A) << endl;
	//测试
	TestMaxSubsequenceSum(MaxSubsequenceSum);
	Pause();
	return 0;
}
