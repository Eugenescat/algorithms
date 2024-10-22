class Solution {
public:
    // 思路：从右上角开始搜索，如果t>target就向左移动，如果t<target就向下移动
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size() || !matrix[0].size()) return false;

        int n = matrix.size(), m = matrix[0].size();
        // 从右上角开始搜索
        int i = 0, j = m - 1;
        while (i < n && j >= 0)
        {
            int t = matrix[i][j];
            if (t == target) return true;
            else if (t > target) j --;
            else i ++;
        }
        return false;
    }
};