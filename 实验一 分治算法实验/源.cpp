#include"divide.h"

int main()
{
	vector<int> T;

	 //��ȡ�ļ�
	if (readfile(T))	//��ȡ�ļ�ʧ�ܱ���1
	{
		return 1;
	}

	//�ݹ���ʽ�Ĺ鲢����
	merge_sort(T, 0, T.size() - 1);

	for (auto ch:T)
	{
		cout << ch << endl;
	}
	
	return 0;
}