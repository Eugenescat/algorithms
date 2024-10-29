class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> f; // 表示杨辉三角
        for (int i = 0; i < numRows; i ++) {
            vector<int> line(i + 1); // 当前行
            line[0] = line[i] = 1; // 填充两侧
            // 处理中间段
            for (int j = 1; j < i; j ++) {
                line[j] = f[i-1][j-1] + f[i-1][j];
            }
            f.push_back(line);
        }
        return f;
    }
};