#include"divide.h"
#pragma once

using namespace std;

bool readfile(vector<int>& T)
{
	ifstream fin("1.txt");
	if (!fin) {
		cerr << "�޷����ļ�" << endl;
		return 1;
	}
	int number;
	while (fin >> number) {
		T.push_back(number);
	}
	fin.close();
	// �����ȡ����������
	std::cout << "�ɹ���ȡ�� " << T.size() << " ������" << std::endl;

	return 0;
}

//void merge_sort(vector<int>& T, int head, int tail)
//{
//	if (head < tail)
//	{
//		int mid = (head + tail) / 2;
//		merge_sort(T, head, mid);
//		merge_sort(T, mid + 1, tail);
//		merge(T, head, tail);
//	}
//}
//
//void merge(vector<int>& T, int head, int tail)
//{
//	vector<int>A, B;
//	int mid = (head + tail) / 2;
//	for (int i = head; i <= mid; i++)
//	{
//		A.push_back(T[i]);
//	}
//	for (int i = mid + 1; i <= tail; i++)
//	{
//		B.push_back(T[i]);
//	}
//
//	int a = 0;
//	int b = 0;
//
//	for (int i = head; i <= tail; ) {
//		if (A[a] <= B[b]) {
//			T[i++] = A[a++];
//		}
//		else {
//			T[i++] = B[b++];
//		}
//
//		// ����ʣ��Ԫ��ʱ��������� i
//		if (a == A.size()) {
//			while (b < B.size()) {
//				T[i++] = B[b++]; // �������� i++
//			}
//			break;
//		}
//
//		if (b == B.size()) {
//			while (a < A.size()) {
//				T[i++] = A[a++]; // �������� i++
//			}
//			break;
//		}
//	}
//
//
//}

// ������Щ���ֶ�����ȫ�������еģ����Ե�kС�����ֵ���ֵ����k
void search(vector<int>& T, int head, int tail, int k)
{
	int key = T[0];// ����keyֵ�����е����ֶ�Ҫ������Ƚ�

	//auto head = T.begin() + 1;
	//auto tail = T.end();
	head++;

	while (head < tail)
	{
		while (T[head] < key && head < tail)
		{
			head++;
		}

		while (T[tail] > key && head < tail)
		{
			tail--;
		}

		if (head < tail)
		{
			swap(T[head], T[tail]);
		}
		

	}
	swap(T[0], T[head]);


}