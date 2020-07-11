// Dijkstra.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#include "util.hpp"

using namespace std;

const int NIL = -1;

const int INF = INT_MAX / 2;

// 图节点声明
struct Vertex 
{
	int idx;	// 记录自己的索引
	int d;		// 记录该节点的最短路径
	int pi;		// 记录最短路径里该节点的前驱
	bool friend operator > (Vertex a, Vertex b)  //重载运算符，以便使用优先队列
	{
		return a.d > b.d;
	}
};

void InitializeSingleSource(vector<Vertex>& G, Vertex& s)  //初始化，参考课本P377
{
	for (int v = 0; v < 5; v++)
	{
		G[v].idx = v;
		G[v].d = INF;
		G[v].pi = NIL;
	}
}

void Relax(Vertex& u, Vertex& v, vector<vector<int>>& w)  //松弛操作，参考课本P377
{
	if (v.d > u.d + w[u.idx][v.idx])
	{
		v.d = u.d + w[u.idx][v.idx];
		v.pi = u.idx;
	}
}

void Dijkstra(vector<Vertex>& G, vector<vector<int>>& w, Vertex& s)
{
	//参考课本P383的伪代码思想
	//不一定要使用extract-min，可自行遍历找到每轮的最小路径节点。
	InitializeSingleSource(G, s);
	s.d = 0;
	int visit[5] = {0, 0, 0, 0, 0};  //登记5个顶点是否已找到最小路径

	for (int n = 0; n < G.size(); n++) //将优先队列的初始化放入循环内部多次初始化，是因为优先队列在元素被修改后不会更新排序，从而弹出错误的最小元素
	{
		priority_queue<Vertex, vector<Vertex>, greater<Vertex>> Q;  //集合Q存放还未被找到最短路径的结点
		for (int i = 0; i < G.size(); i++)
		{
			if (visit[i] == 0)
				Q.push(G[i]);
		}
			
		Vertex u = Q.top();  //从Q中选出结点d值最小(离source最近)的
		visit[u.idx] = 1;
		Q.pop();
		for (int i = 0; i < G.size(); i++)  //查找所有顶点，对与u相连的边进行松弛
		{
			Vertex v1 = G[i];
			Vertex* v = &G[i];  //由于Relax操作需要Vertex*类型的参数，而v1.idx需要v1是Vertex类型的，所以定义了两个v
			if (w[u.idx][v1.idx] != INF)
				Relax(u, *v, w);  //由于Relax函数中没有修改v结点的数据，所以传入Vertex类型的参数也没有关系
		}
	}
}


int main() 
{
	vector<vector<int>> w = 
	{
		{ 0, 10, 5, INF, INF },
		{ INF, 0, 2, 1, INF },
		{ INF, 3, 0, INF, 2 },
		{ INF, INF, INF, 0, 4 },
		{ INF, INF, INF, 6, 0 }
	};

	vector<Vertex> G(w.size());
	Vertex& s = G[0];
	Dijkstra(G, w, s);

	for (auto& v : G) 
	{
		printf("shortest path of (%d, %d)=%d\n", s.idx, v.idx, v.d);
	}

	/*
	shortest path of (0, 0)=0
	shortest path of (0, 1)=8
	shortest path of (0, 2)=5
	shortest path of (0, 3)=9
	shortest path of (0, 4)=7
	*/
	Pause();  	// 按任意键继续
	return 0;
}
