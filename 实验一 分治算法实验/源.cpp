#include"divide.h"

int main()
{
	vector<int> T;

	 //读取文件
	if (readfile(T))	//读取文件失败报错1
	{
		return 1;
	}

	//递归形式的归并排序
	merge_sort(T, 0, T.size() - 1);

	for (auto ch:T)
	{
		cout << ch << endl;
	}
	
	return 0;
}