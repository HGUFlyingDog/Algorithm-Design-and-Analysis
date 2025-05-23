#include "LCS.h"
#include <algorithm>

namespace LCS {
    // 辅助函数：回溯所有可能的 LCS
    void backtrack(
        const std::string& A, const std::string& B,
        const std::vector<std::vector<int>>& dp,
        int i, int j, std::string current,
        std::vector<std::string>& result
    ) {
        if (i == 0 || j == 0) {
            std::reverse(current.begin(), current.end());
            if (!current.empty()) {
                // 手动去重：如果当前字符串不在结果中则添加
                bool exists = false;
                for (const std::string& s : result) {
                    if (s == current) {
                        exists = true;
                        break;
                    }
                }
                if (!exists) result.push_back(current);
            }
            return;
        }

        if (A[i - 1] == B[j - 1]) {
            backtrack(A, B, dp, i - 1, j - 1, current + A[i - 1], result);
        }
        else {
            if (dp[i - 1][j] == dp[i][j]) backtrack(A, B, dp, i - 1, j, current, result);
            if (dp[i][j - 1] == dp[i][j]) backtrack(A, B, dp, i, j - 1, current, result);
        }
    }

    Result solve(const std::string& A, const std::string& B) {
        int m = A.size(), n = B.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        // 计算 LCS 长度
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // 收集所有 LCS 序列
        std::vector<std::string> sequences;
        backtrack(A, B, dp, m, n, "", sequences);

        return { dp[m][n], sequences };
    }
}