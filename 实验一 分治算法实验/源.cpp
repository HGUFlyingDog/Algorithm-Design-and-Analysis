#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<fstream>
#include<Windows.h>
#include <algorithm>

//设置颜色部分
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
		cerr << "读取失败，请保证1.txt和本文件在同一个目录" << endl;
		return 1;
	}

	T.reserve(1000000);//提前开辟出空间 提高性能
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

		// 处理剩下的元素
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

//由于这些数字都是完全有序排列的，所以第k小的数字的数值等于k
void search(vector<int>& T, int head, int tail, int k)
{
	if (head == tail)
	{
		return;
	}

	// 快排的思路-霍尔
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

	// 递归过程

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
	return selectKth(T, 0, T.size() - 1, k - 1); // 将k转换为0-based索引
}

int selectKth(vector<int>& T, int left, int right, int k) {
	// 当元素数量小于等于5时直接排序返回
	if (right - left + 1 <= 5) {
		sort(T.begin() + left, T.begin() + right + 1);
		return T[left + k];
	}

	// 分组并收集各组中位数
	int numGroups = (right - left + 1 + 4) / 5;
	vector<int> medians;
	for (int i = 0; i < numGroups; ++i) {
		int groupLeft = left + i * 5;
		int groupRight = min(groupLeft + 4, right);
		sort(T.begin() + groupLeft, T.begin() + groupRight + 1);
		int medianPos = groupLeft + (groupRight - groupLeft) / 2;
		medians.push_back(T[medianPos]);
	}

	// 递归找到中位数的中位数作为pivot
	int pivot = selectKth(medians, 0, medians.size() - 1, medians.size() / 2);

	// 三路分区操作
	int less = left;    // 小于区域的右边界
	int equal = left;   // 等于区域的右边界
	int greater = right;// 大于区域的左边界

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

	// 计算各区域长度
	int leftLength = less - left;
	int middleLength = equal - less;

	// 根据k的位置决定递归方向
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
	cout << "请输入整数序列（空格分隔，回车结束）: ";

	int num;
	while (cin >> num) {
		arr.push_back(num);
		if (cin.get() == '\n') break;
	}
	return arr;
}

//菜单
void showMenu() {
	cout << BOLD << MAGENTA << "\n╔══════════════════════════╗" << RESET << endl;
	cout << BOLD << MAGENTA << "║" << GREEN << "       分治算法菜单       " << MAGENTA << "║" << RESET << endl;
	cout << BOLD << MAGENTA << "╠══════════════════════════╣" << RESET << endl;
	cout << BOLD << MAGENTA << "║ " << YELLOW << "1. " << CYAN << "合并排序" << string(14, ' ') << MAGENTA << "║" << RESET << endl;
	cout << BOLD << MAGENTA << "║ " << YELLOW << "2. " << CYAN << "查找第k小元素" << string(9, ' ') << MAGENTA << "║" << RESET << endl;
	cout << BOLD << MAGENTA << "║ " << YELLOW << "3. " << CYAN << "计算最大子段和" << string(8, ' ') << MAGENTA << "║" << RESET << endl;
	cout << BOLD << MAGENTA << "║ " << YELLOW << "0. " << RED << "退出" << string(18, ' ') << MAGENTA << "║" << RESET << endl;
	cout << BOLD << MAGENTA << "╚══════════════════════════╝" << RESET << endl;
	cout << BOLD << BLUE << "请选择功能: " << RESET;
}

// 辅助函数求三个数最大值
int max3(int a, int b, int c) {
	return max(a, max(b, c));
}

// 递归求解最大子段和
int maxSubArray(vector<int>& nums, int left, int right) {
	// 递归终止条件
	if (left == right) return nums[left];

	int mid = left + (right - left) / 2;

	// 递归求解左右区间
	int leftMax = maxSubArray(nums, left, mid);
	int rightMax = maxSubArray(nums, mid + 1, right);

	// 计算跨越中间的最大子段和
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

	// 返回三者中的最大值
	return max3(leftMax, rightMax, leftBorder + rightBorder);
}

// 暂停函数（按任意键继续）
void pressAnyKey()  {
	char tem;
	scanf("%c", &tem);
	cout << BOLD << CYAN << "\n请按回车继续..." << RESET;
	scanf("%c", &tem);

	system("cls");
}

int main()
{
	vector<int> T;

	//读取文件
	if (readfile(T)) 	//读取文件失败报错1
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
			cout << "查看结果请按1，不想查看按0\n";
			cin >> choice1;
			if (choice1 == 1)
			{
				cout << "排序结果: ";
				for (int num : T) cout << num << " "; //范围for循环
				cout << endl;
			}
			pressAnyKey();
			break;
		}
		case 2: {
			int k;
			cout << "请输入k值: ";
			cin >> k;
			int ret = selectKth(T1, 0, T.size() - 1, k - 1); //方便数组下标的计数 这样保证第1小的数字是1
			cout << "第" << k << "小的数字是" << ret << endl;
			pressAnyKey();
			break;
		}
		case 3: {
			vector<int> arr = inputArray();
			int result = maxSubArray(arr, 0, arr.size() - 1);
			cout << "最大子段和为: " << result ;
			pressAnyKey();
			break;
		}
		case 0:
			cout << "程序已退出，感谢测试！" << endl;
			break;
		default:
			cout << "无效输入，请重新选择！" << endl;
			pressAnyKey();
		}
	} while (choice != 0);

	return 0;
}