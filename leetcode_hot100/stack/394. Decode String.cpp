class Solution {
public:
    // 时间复杂度O(n)
    string decodeString(string s) {
        int u = 0;
        return dfs(s, u);
    }

    string dfs(string& s, int& u) {
        string res; // 当前k[ab]组解码后的字符串
        // 只要 u 没到字符串结尾，且 s[u] 不是 ]，就一直解析
        while (u < s.size() && s[u] != ']') {
            // 先把直接是字母的加入res
            if ((s[u] >= 'a' && s[u] <= 'z' ) || (s[u] >= 'A' && s[u] <= 'Z')) {
                res += s[u];
                u++;
            }
            // 如果[ab]内部还有k[ab]
            // k可能不止一位数
            else if (s[u] >= '0' && s[u] <= '9') {
                int i = u;
                while (s[i] >= '0' && s[i] <= '9') i++; // 此时i指向k随后的'['
                int k = stoi(s.substr(u, i - u)); // k的真实值（注意不需要+1，因为现在i指向k右边的第一个符号）
                u = i + 1; // 跳过k随后的'['
                string y = dfs(s, u); // 递归返回到相应']'为止的子串
                u ++; // 过滤掉']'
                while (k--) res += y; // 一共有k个ab
            }
        }
        return res;
    }
};