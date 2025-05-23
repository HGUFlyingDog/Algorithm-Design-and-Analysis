#include <iostream>
#include "LCS.h"
#include "resource_alloc.h"
using namespace std;

void testLCS()
{
	cout << "���������������" << endl;
	std::string A = "zxyxyz", B = "xyyzx";
	cout << "A" << A << "    B:" << B << endl;
	auto lcs_result = LCS::solve(A, B);
	std::cout << "����������еĳ���: " << lcs_result.length << "\n";
	std::cout << "�����������Ϊ:\n";
	for (auto& s : lcs_result.sequences)
	{
		std::cout << s << std::endl;
	}
}
void resource()
{
	std::cout << endl << endl << "��Դ��������:" << std::endl;
	std::vector<std::vector<int>> profit_table = {
		{0, 3, 7, 9, 12, 13},  // ��Ŀ0�����������0~5�ݣ�
		{0, 5, 10, 11, 11, 11}, // ��Ŀ1�������
		{0, 4, 6, 6, 11, 12,12}  // ��Ŀ2�������
	};

	auto result = ResourceAlloc::solve(5, profit_table);

	// ������
	std::cout << "�������: " << result.max_profit << std::endl;
	std::cout << "���䷽��: ";
	for (int num : result.allocation) {
		std::cout << num << " ";
	}
}

void Rob(vector<int>& nums) {
	int prev = 0, curr = 0;
	for (int num : nums) {
		int temp = curr;               
		curr = max(curr, prev + num);   // ���µ�ǰ�����
		prev = temp;                   
	}
	cout << curr;
}

void testRob()
{
	vector<int> rob = { 2, 7, 9, 3, 1 };
	cout << endl << endl << "��ҽ���:" << endl ;
	for (auto ch :rob)
	{
		cout << ch << " ";
	}
	cout << endl<<"���ս����";
	Rob(rob);
}

int main()
{
	testLCS();

	resource();

	testRob();

	return 0;
}