#include "LCS.h"
#include <algorithm>

namespace LCS {
    // �����������������п��ܵ� LCS
    void backtrack(
        const std::string& A, const std::string& B,
        const std::vector<std::vector<int>>& dp,
        int i, int j, std::string current,
        std::vector<std::string>& result
    ) {
        if (i == 0 || j == 0) {
            std::reverse(current.begin(), current.end());
            if (!current.empty()) {
                // �ֶ�ȥ�أ������ǰ�ַ������ڽ���������
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

        // ���� LCS ����
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

        // �ռ����� LCS ����
        std::vector<std::string> sequences;
        backtrack(A, B, dp, m, n, "", sequences);

        return { dp[m][n], sequences };
    }
}