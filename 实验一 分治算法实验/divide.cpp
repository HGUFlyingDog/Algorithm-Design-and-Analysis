#include"divide.h"
#pragma once
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

bool readfile(vector<int>& T)
{
	ifstream fin("1.txt");
	if (!fin) {
		std::cerr << "无法打开文件" << std::endl;
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
		merge_sort(T, mid+1, tail);
		merge(T, head,mid, tail);
	}
}

void merge(vector<int>& T, int head,int mid ,int tail)
{
	vector<int>A ,B;
	for (int i = head; i < mid; i++)
	{

	}


}