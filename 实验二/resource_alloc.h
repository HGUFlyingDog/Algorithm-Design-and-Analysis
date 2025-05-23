#pragma once

#include <vector>

namespace ResourceAlloc {
    struct Result {
        int max_profit; // 最大利润
        std::vector<int> allocation; // 每个项目分配的资源数（长度=N）
    };

    // 输入：total_resources 总资源量，profit_table 利润表（profit_table[i][j]表示项目i分配j份资源的利润）
    Result solve(int total_resources, const std::vector<std::vector<int>>& profit_table);
}
