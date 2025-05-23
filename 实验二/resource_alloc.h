#pragma once

#include <vector>

namespace ResourceAlloc {
    struct Result {
        int max_profit; // �������
        std::vector<int> allocation; // ÿ����Ŀ�������Դ��������=N��
    };

    // ���룺total_resources ����Դ����profit_table �����profit_table[i][j]��ʾ��Ŀi����j����Դ������
    Result solve(int total_resources, const std::vector<std::vector<int>>& profit_table);
}
