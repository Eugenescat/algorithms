class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        // 到第一级和到第二级的方法数
        int a = 1, b = 2;
        for (int i = 0; i < n - 2; i ++)
        {
            int c = a + b;
            a = b, b = c;
        }
        return b;
    }
};