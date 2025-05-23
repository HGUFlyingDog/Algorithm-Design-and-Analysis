#include "resource_alloc.h"
#include <algorithm> 

namespace ResourceAlloc {
    Result solve(int total_resources, const std::vector<std::vector<int>>& profit_table) {
        int N = profit_table.size(); // ��Ŀ����
        int M = total_resources;     // ����Դ��

        // ������̬�滮��dp[i][j] ��ʾǰi����Ŀ����j����Դ���������
        std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M + 1, 0));

        // ·����¼����¼ÿ��״̬�����ŷ���
        std::vector<std::vector<int>> path(N + 1, std::vector<int>(M + 1, 0));

        // ���dp��
        for (int i = 1; i <= N; ++i) { // ����ÿ����Ŀ
            for (int j = 0; j <= M; ++j) { // ������ǰ������Դ
                dp[i][j] = dp[i - 1][j]; // ��ʼ��Ϊ��������Դ����ǰ��Ŀ
                path[i][j] = 0;        // Ĭ�Ϸ���0��

                // ���Է���k����Դ����i����Ŀ
                for (int k = 1; k <= j; ++k) {
                    if (k >= profit_table[i - 1].size()) break; // ��ֹԽ��
                    int profit = profit_table[i - 1][k] + dp[i - 1][j - k];
                    if (profit > dp[i][j]) {
                        dp[i][j] = profit;
                        path[i][j] = k; // ��¼���ŷ�����
                    }
                }
            }
        }

        // �����ҵ����ŷ��䷽��
        std::vector<int> alloc(N, 0);
        int remaining = M;
        for (int i = N; i >= 1; --i) {
            alloc[i - 1] = path[i][remaining]; // ��i����Ŀ�������Դ
            remaining -= alloc[i - 1];        // ʣ����Դ����
        }

        return { dp[N][M], alloc };
    }
}