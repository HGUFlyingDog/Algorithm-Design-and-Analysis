#include"divide.h"

int main()
{
	vector<int> T;

	 //��ȡ�ļ�
	if (readfile(T))	//��ȡ�ļ�ʧ�ܱ���1
	{

		return 1;
	}
	
	
	// ������һ�����֣�����Ҫ������
	// 
	// 
	//�ݹ���ʽ�Ĺ鲢����
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