#include <iostream>
#include "LCS.h"
#include "resource_alloc.h"
using namespace std;

void testLCS()
{
	cout << "测试最长公共子序列" << endl;
	std::string A = "zxyxyz", B = "xyyzx";
	cout << "A" << A << "    B:" << B << endl;
	auto lcs_result = LCS::solve(A, B);
	std::cout << "最长公共子序列的长度: " << lcs_result.length << "\n";
	std::cout << "最长公共子序列为:\n";
	for (auto& s : lcs_result.sequences)
	{
		std::cout << s << std::endl;
	}
}
void resource()
{
	std::cout << endl << endl << "资源分配问题:" << std::endl;
	std::vector<std::vector<int>> profit_table = {
		{0, 3, 7, 9, 12, 13},  // 项目0的利润表（分配0~5份）
		{0, 5, 10, 11, 11, 11}, // 项目1的利润表
		{0, 4, 6, 6, 11, 12,12}  // 项目2的利润表
	};

	auto result = ResourceAlloc::solve(5, profit_table);

	// 输出结果
	std::cout << "最大利润: " << result.max_profit << std::endl;
	std::cout << "分配方案: ";
	for (int num : result.allocation) {
		std::cout << num << " ";
	}
}

void Rob(vector<int>& nums) {
	int prev = 0, curr = 0;
	for (int num : nums) {
		int temp = curr;               
		curr = max(curr, prev + num);   // 更新当前最大金额
		prev = temp;                   
	}
	cout << curr;
}

void testRob()
{
	vector<int> rob = { 2, 7, 9, 3, 1 };
	cout << endl << endl << "打家劫舍:" << endl ;
	for (auto ch :rob)
	{
		cout << ch << " ";
	}
	cout << endl<<"最终结果：";
	Rob(rob);
}

int main()
{
	testLCS();

	resource();

	testRob();

	return 0;
}