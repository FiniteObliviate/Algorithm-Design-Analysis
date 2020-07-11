// Huffman编码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "util.hpp"

#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct TreeNode
{
	char symbol;       // 编码的字母
	double freq;       // 对应的频率
	TreeNode *left;    // 左孩子
	TreeNode *right;   // 右孩子
	// 构造函数
	TreeNode()
		: symbol('\0'), freq(0), left(NULL), right(NULL) {}
	// 用symbol和freq构造
	TreeNode(char symbol_, double freq_)
		: symbol(symbol_), freq(freq_), left(NULL), right(NULL) {}
	// 比较哪个节点的频率更高
	bool operator()(const TreeNode* lhs, const TreeNode* rhs)
	{
		return lhs->freq > rhs->freq;
	}
};

// 销毁树

TreeNode* Huffman(vector<TreeNode*>& C) 
{
	//for (int i = 0; i < n; i++)
	//{
	//	cout << C[i]->freq << "  ";
	//}
	//cout << endl << endl;
	int n = C.size();
	TreeNode *x, *y, *z;
	priority_queue<TreeNode*, vector<TreeNode*>, TreeNode> Q;
	for (int i = 0; i < n; i++) 	// 把C放入Q中
	{
		Q.push(C[i]);
	}
	// 请完成huffman编码的程序
	for (int i = 1; i < n; i++)
	{
		z = (TreeNode*) malloc (sizeof(TreeNode));
		x = Q.top();  //当前Q中最小点
		Q.pop(); //删除
		z->left = x;
		y = Q.top();
		Q.pop();
		z->right = y;
		z->freq = x->freq + y->freq;

		Q.push(z);  //将节点插入Huffman树
	}
	return Q.top();
}

//供传入字母与频率的函数接口
TreeNode* Huffman(string symbols, vector<double> freqs) 
{
	vector<TreeNode *> C;
	for (size_t i = 0; i < freqs.size(); i++) 
	{
		C.push_back(new TreeNode(symbols[i], freqs[i]));
	}
	return Huffman(C);
}

//销毁Huffman树
void Destory(TreeNode* root)
{
	if (root == NULL)
		return;
	Destory(root->left);
	Destory(root->right);
	delete root;
}

 //输出Huffman编码
void OutputAllSymbolCode(TreeNode* root, string code = "")
{
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL)
	{
		cout << root->symbol << ":" << code << endl;
	}
	if (root->left != NULL)
	{
		OutputAllSymbolCode(root->left, code + '0');  // 左节点编码加0
	}
	if (root->right != NULL)
	{
		OutputAllSymbolCode(root->right, code + '1'); // 右节点编码加1
	}
}


int main() 
{
	string symbols = "garohtmil";
	vector<double> freqs = { 32, 16, 21, 12, 13, 3, 7, 8, 9};
	// string symbols = "fecbda";
	// vector<double> freqs = {5, 9, 12, 13, 16, 45};

	TreeNode *root = Huffman(symbols, freqs);

	OutputAllSymbolCode(root);
	Destory(root);
	Pause();
	return 0;
}
