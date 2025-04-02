#include"divide.h"

int main()
{
	vector<int> T;

	 //读取文件
	if (readfile(T))	//读取文件失败报错1
	{

		return 1;
	}
	
	
	// 随便加了一点数字，正常要报错但是
	// 
	// 
	//递归形式的归并排序
	//merge_sort(T, 0, T.size() - 1);
	//merge(T, 0, T.size()-1);

	////if (T[0] != 1)
	//{
	//	cout << "ERRROR" << endl;
	//	return 2;
	//}

	search(T, 0, T.size() - 1,3);

	for (auto ch:T)
	{
		cout << ch << endl;
	}
	
	return 0;
}