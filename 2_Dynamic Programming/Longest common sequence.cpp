// 最长公共子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"util.hpp"
using namespace std;


void LCS(const string X, const string Y, vector<vector<int>>& c, vector<vector<char>>& b) 
{
	//同教材224页LCS-LENGTH函数
	//c和b在函数外定义，通过引用方式传入，不需要返回值
	int m = X.length(), n = Y.length();
	//将二维数组的第一行、第一列填为0，让后面b和c的表项填写代码是普遍的
	for (int i = 0; i <= m; i++)
		c[i][0] = 0;
	for (int j = 1; j <= n; j++)
		c[0][j] = 0;
	//计算表项，分别将公共子序列长度和追踪该子序列的路线填写在c和b中
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (X[i - 1] == Y[j - 1])  //是公共元素
			{
				c[i][j] = c[i - 1][j - 1] + 1;  //长度加一
				b[i][j] = 'C';  //向左上方追踪
			}
			//非公共元素，将左方和上方所记长度中的较大者记录在当前格子中
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 'U';  //向上方追踪
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 'L';  //向左方追踪
			}
		}
	}
}

void PrintLCS(vector<vector<char>>& b, string X, int i, int j)
{
	//同教材225页PRINT-LCS函数
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 'C')
	{
		PrintLCS(b, X, i - 1, j - 1);
		cout << X[i - 1];
	}
	else if (b[i][j] == 'U')
		PrintLCS(b, X, i - 1, j);
	else
		PrintLCS(b, X, i, j - 1);
}

void PrintTable(vector<vector<int>>& a) 
{
	//输出表c或b,可用于调试
	for (size_t i = 0; i < a.size(); i++) 
	{
		for (size_t j = 0; j < a[0].size(); j++) 
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() 
{
	//用于测试的数据，可以通过X[0]的方式访问X的第一个元素
	string X = "AGCTAG";
	string Y = "ACTCC";

	int m = X.length() + 1;
	int n = Y.length() + 1;

	//定义c和b，使用方法同二维数组
	vector<vector<int>> c(m, vector<int>(n));
	vector<vector<char>> b(m, vector<char>(n));

	//求最长公共子序列
	LCS(X, Y, c, b);

	PrintTable(c);

	//输出最长公共子序列
	cout << "Length of LCS: " << c[X.length()][Y.length()] << endl;
	PrintLCS(b, X, X.length(), Y.length());
	cout << endl;

	//测试
	TestLCS(LCS);
	Pause();
	return 0;
}
