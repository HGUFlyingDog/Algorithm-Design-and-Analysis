#include "resource_alloc.h"
#include <algorithm> 

namespace ResourceAlloc {
    Result solve(int total_resources, const std::vector<std::vector<int>>& profit_table) {
        int N = profit_table.size(); // 项目数量
        int M = total_resources;     // 总资源量

        // 创建动态规划表：dp[i][j] 表示前i个项目分配j份资源的最大利润
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M + 1, 0));

        // 路径记录表：记录每个状态的最优分配
        std::vector<std::vector<int>> path(N + 1, std::vector<int>(M + 1, 0));

        // 填充dp表
        for (int i = 1; i <= N; ++i) { // 遍历每个项目
            for (int j = 0; j <= M; ++j) { // 遍历当前可用资源
                dp[i][j] = dp[i - 1][j]; // 初始化为不分配资源给当前项目
                path[i][j] = 0;        // 默认分配0份

                // 尝试分配k份资源给第i个项目
                for (int k = 1; k <= j; ++k) {
                    if (k >= profit_table[i - 1].size()) break; // 防止越界
                    int profit = profit_table[i - 1][k] + dp[i - 1][j - k];
                    if (profit > dp[i][j]) {
                        dp[i][j] = profit;
                        path[i][j] = k; // 记录最优分配量
                    }
                }
            }
        }

        // 回溯找到最优分配方案
        std::vector<int> alloc(N, 0);
        int remaining = M;
        for (int i = N; i >= 1; --i) {
            alloc[i - 1] = path[i][remaining]; // 第i个项目分配的资源
            remaining -= alloc[i - 1];        // 剩余资源减少
        }

        return { dp[N][M], alloc };
    }
}