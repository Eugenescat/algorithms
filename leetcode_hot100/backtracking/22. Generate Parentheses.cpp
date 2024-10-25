class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, ""); // 参数包括左括号数量和右括号数量
        return res;
    }

    void dfs(int n, int lc, int rc, string seq) {
        if (lc == n && rc == n) res.push_back(seq);
        else {
            if (lc < n) dfs (n, lc + 1, rc, seq + '(');
            if (rc < n && lc > rc) dfs(n, lc, rc + 1, seq + ')');
        }
    }
};