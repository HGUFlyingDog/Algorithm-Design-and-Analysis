#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<fstream>
#include<Windows.h>
#include <algorithm>

//������ɫ����
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

using namespace std;

bool readfile(vector<int>& T);
void merge_sort(vector<int>& T, int head, int tail);
void merge(vector<int>& T, int head, int tail);
void search(vector<int>& T, int head, int tail, int k);
int selectKth(vector<int>& T, int left, int right, int k);

bool readfile(vector<int>& T)
{
	ifstream fin("1.txt");
	if (!fin) {
		cerr << "��ȡʧ�ܣ��뱣֤1.txt�ͱ��ļ���ͬһ��Ŀ¼" << endl;
		return 1;
	}

	T.reserve(1000000);//��ǰ���ٳ��ռ� �������
	int number;
	while (fin >> number) {
		T.push_back(number);
	}
	fin.close();
	// �����ȡ����������
	std::cout << "�ɹ���ȡ�� " << T.size() << " ������" << std::endl;

	return 0;
}

void merge_sort(vector<int>& T, int head, int tail)
{
	if (head < tail)
	{
		int mid = (head + tail) / 2;
		merge_sort(T, head, mid);
		merge_sort(T, mid + 1, tail);
		merge(T, head, tail);
	}
}

void merge(vector<int>& T, int head, int tail)
{
	vector<int>A, B;
	int mid = (head + tail) / 2;
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

	for (int i = head; i <= tail; ) {
		if (A[a] <= B[b]) {
			T[i++] = A[a++];
		}
		else {
			T[i++] = B[b++];
		}

		// ����ʣ�µ�Ԫ��
		if (a == A.size()) {
			while (b < B.size()) {
				T[i++] = B[b++];
			}
			break;
		}

		if (b == B.size()) {
			while (a < A.size()) {
				T[i++] = A[a++];
			}
			break;
		}
	}
}

//������Щ���ֶ�����ȫ�������еģ����Ե�kС�����ֵ���ֵ����k
void search(vector<int>& T, int head, int tail, int k)
{
	if (head == tail)
	{
		return;
	}

	// ���ŵ�˼·-����
	int key = T[0];
	int head1 = head;
	int tail1 = tail;

	while (head < tail)
	{
		while (head < tail && T[tail] >= key)
		{
			tail--;
		}
		while (head < tail && T[head] <= key)
		{
			head++;
		}
		swap(T[head], T[tail]);
	}

	swap(T[0], T[tail]);

	// �ݹ����

	if (k == key)
	{
		cout << "find" << key << endl;
		return;
	}
	else if (k < key)
	{
		search(T, head1, tail, k);
	}
	else
	{
		search(T, head, tail1, k);
	}
}

int findKthSmallest(vector<int>& T, int k) {
	return selectKth(T, 0, T.size() - 1, k - 1); // ��kת��Ϊ0-based����
}

int selectKth(vector<int>& T, int left, int right, int k) {
	// ��Ԫ������С�ڵ���5ʱֱ�����򷵻�
	if (right - left + 1 <= 5) {
		sort(T.begin() + left, T.begin() + right + 1);
		return T[left + k];
	}

	// ���鲢�ռ�������λ��
	int numGroups = (right - left + 1 + 4) / 5;
	vector<int> medians;
	for (int i = 0; i < numGroups; ++i) {
		int groupLeft = left + i * 5;
		int groupRight = min(groupLeft + 4, right);
		sort(T.begin() + groupLeft, T.begin() + groupRight + 1);
		int medianPos = groupLeft + (groupRight - groupLeft) / 2;
		medians.push_back(T[medianPos]);
	}

	// �ݹ��ҵ���λ������λ����Ϊpivot
	int pivot = selectKth(medians, 0, medians.size() - 1, medians.size() / 2);

	// ��·��������
	int less = left;    // С��������ұ߽�
	int equal = left;   // ����������ұ߽�
	int greater = right;// �����������߽�

	while (equal <= greater) {
		if (T[equal] < pivot) {
			swap(T[less], T[equal]);
			++less;
			++equal;
		}
		else if (T[equal] == pivot) {
			++equal;
		}
		else {
			swap(T[equal], T[greater]);
			--greater;
		}
	}

	// ��������򳤶�
	int leftLength = less - left;
	int middleLength = equal - less;

	// ����k��λ�þ����ݹ鷽��
	if (k < leftLength) {
		return selectKth(T, left, less - 1, k);
	}
	else if (k < leftLength + middleLength) {
		return pivot;
	}
	else {
		return selectKth(T, equal, right, k - (leftLength + middleLength));
	}
}

vector<int> inputArray() {
	vector<int> arr;
	cout << "�������������У��ո�ָ����س�������: ";

	int num;
	while (cin >> num) {
		arr.push_back(num);
		if (cin.get() == '\n') break;
	}
	return arr;
}

//�˵�
void showMenu() {
	cout << BOLD << MAGENTA << "\n�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << RESET << endl;
	cout << BOLD << MAGENTA << "�U" << GREEN << "       �����㷨�˵�       " << MAGENTA << "�U" << RESET << endl;
	cout << BOLD << MAGENTA << "�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g" << RESET << endl;
	cout << BOLD << MAGENTA << "�U " << YELLOW << "1. " << CYAN << "�ϲ�����" << string(14, ' ') << MAGENTA << "�U" << RESET << endl;
	cout << BOLD << MAGENTA << "�U " << YELLOW << "2. " << CYAN << "���ҵ�kСԪ��" << string(9, ' ') << MAGENTA << "�U" << RESET << endl;
	cout << BOLD << MAGENTA << "�U " << YELLOW << "3. " << CYAN << "��������Ӷκ�" << string(8, ' ') << MAGENTA << "�U" << RESET << endl;
	cout << BOLD << MAGENTA << "�U " << YELLOW << "0. " << RED << "�˳�" << string(18, ' ') << MAGENTA << "�U" << RESET << endl;
	cout << BOLD << MAGENTA << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << RESET << endl;
	cout << BOLD << BLUE << "��ѡ����: " << RESET;
}

// �������������������ֵ
int max3(int a, int b, int c) {
	return max(a, max(b, c));
}

// �ݹ��������Ӷκ�
int maxSubArray(vector<int>& nums, int left, int right) {
	// �ݹ���ֹ����
	if (left == right) return nums[left];

	int mid = left + (right - left) / 2;

	// �ݹ������������
	int leftMax = maxSubArray(nums, left, mid);
	int rightMax = maxSubArray(nums, mid + 1, right);

	// �����Խ�м������Ӷκ�
	int leftSum = 0, leftBorder = INT_MIN;
	for (int i = mid; i >= left; --i) {
		leftSum += nums[i];
		leftBorder = max(leftBorder, leftSum);
	}

	int rightSum = 0, rightBorder = INT_MIN;
	for (int i = mid + 1; i <= right; ++i) {
		rightSum += nums[i];
		rightBorder = max(rightBorder, rightSum);
	}

	// ���������е����ֵ
	return max3(leftMax, rightMax, leftBorder + rightBorder);
}

// ��ͣ�������������������
void pressAnyKey()  {
	char tem;
	scanf("%c", &tem);
	cout << BOLD << CYAN << "\n�밴�س�����..." << RESET;
	scanf("%c", &tem);

	system("cls");
}

int main()
{
	vector<int> T;

	//��ȡ�ļ�
	if (readfile(T)) 	//��ȡ�ļ�ʧ�ܱ���1
	{
		return 1;
	}
	vector<int> T1 = T;

	int choice, choice1;
	do {
		showMenu();
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			merge_sort(T, 0, T.size() - 1);
			cout << "�鿴����밴1������鿴��0\n";
			cin >> choice1;
			if (choice1 == 1)
			{
				cout << "������: ";
				for (int num : T) cout << num << " "; //��Χforѭ��
				cout << endl;
			}
			pressAnyKey();
			break;
		}
		case 2: {
			int k;
			cout << "������kֵ: ";
			cin >> k;
			int ret = selectKth(T1, 0, T.size() - 1, k - 1); //���������±�ļ��� ������֤��1С��������1
			cout << "��" << k << "С��������" << ret << endl;
			pressAnyKey();
			break;
		}
		case 3: {
			vector<int> arr = inputArray();
			int result = maxSubArray(arr, 0, arr.size() - 1);
			cout << "����Ӷκ�Ϊ: " << result ;
			pressAnyKey();
			break;
		}
		case 0:
			cout << "�������˳�����л���ԣ�" << endl;
			break;
		default:
			cout << "��Ч���룬������ѡ��" << endl;
			pressAnyKey();
		}
	} while (choice != 0);

	return 0;
}