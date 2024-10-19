class Solution {
public:
    // 单独开一个标记行和标记列，将时间降为n^2
    void setZeroes(vector<vector<int>>& matrix) {
        if (!matrix.size() || !matrix[0].size()) return;
        int n = matrix.size();
        int m = matrix[0].size();
        int r0 = 1, c0 = 1;

        // 记录第一列
        for (int i = 0; i < n; i++)
            if (!matrix[i][0]) c0 = 0;
        // 记录第一行
        for (int j = 0; j < m; j++)
            if (!matrix[0][j]) r0 = 0;

        // 将剩下部分记录在第一行第一列中
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
            {
                if (!matrix[i][j])
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        
        // 开始根据记录刷格子
        for (int i = 1; i < n; i++)
            if (matrix[i][0] == 0)
                for (int j = 1; j < m; j++) matrix[i][j] = 0;
        for (int j = 1; j < m; j++)
            if (matrix[0][j] == 0)
                for (int i = 1; i < n; i++) matrix[i][j] = 0;
        
        // 处理第一行第一列
        if (!c0)
            for (int i = 0; i < n; i++) matrix[i][0] = 0;
        if (!r0)
            for (int j = 0; j < m; j++) matrix[0][j] = 0;
    }
};