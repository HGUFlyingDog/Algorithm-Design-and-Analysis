#include"divide.h"
#pragma once

using namespace std;

bool readfile(vector<int>& T)
{
	ifstream fin("1.txt");
	if (!fin) {
		cerr << "无法打开文件" << endl;
		return 1;
	}
	int number;
	while (fin >> number) {
		T.push_back(number);
	}
	fin.close();
	// 输出读取的数字数量
	std::cout << "成功读取了 " << T.size() << " 个数字" << std::endl;

	return 0;
}

void merge_sort(vector<int>& T, int head, int tail)
{
	if (head < tail)
	{
		int mid = (head + tail) / 2;
		merge_sort(T, head, mid);
		merge_sort(T, mid + 1, tail);
		merge(T, head, mid, tail);
	}
}

void merge(vector<int>& T, int head, int mid, int tail)
{
	vector<int>A, B;
	for (int i = head; i <= mid; i++)
	{
		A.push_back(T[i]);
	}
	for (int i = mid + 1; i <= tail; i++)
	{
		B.push_back(T[i]);
	}

	int a = 0;
	int b = 0;

	for (int i = 0; i <= tail; )
	{
		if (A[a] <= B[b])
		{
			T[i++] = A[a++];
		}
		else
		{
			T[i++] = B[b++];
		}

		if (a == A.size())
		{
			while (b < B.size())
			{
				T[i]=B[b++];
			}
			break;
		}

		if (b == B.size())
		{
			while (a < A.size())
			{
				T[i] = (A[a++]);
			}
			break;
		}
	}
}