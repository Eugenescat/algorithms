class Solution {
public:
    // 时间复杂度指数级别
    string decodeString(string s) {
        int u = 0;
        return dfs(s, u);
    }

    string dfs(string& s, int& u) {
        string res;
        while (u < s.size() && s[u] != ']') {
            if ((s[u] >= 'a' && s[u] <= 'z' ) || (s[u] >= 'A' && s[u] <= 'Z')) res += s[u++];
            // 找到k的大小
            else if (s[u] >= '0' && s[u] <= '9') {
                int i = u;
                while (s[i] >= '0' && s[i] <= '9') i++; // 现在i指向k右边的第一个符号
                int x = stoi(s.substr(u, i - u)); //k的真实值（注意不需要+1，因为现在i指向k右边的第一个符号）
                u = i + 1; // 跳过k右边的第一个'['
                string y = dfs(s, u); // 递归返回到相应']'为止的子串
                u ++; // 过滤掉']'
                while (x--) res += y;
            }
        }
        return res;
    }
};