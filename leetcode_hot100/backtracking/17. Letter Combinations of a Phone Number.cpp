class Solution {
public:
    vector<string> ans;
    vector<char> path;
    string strs[10] = {
        "", "",
        "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return ans;
        dfs(digits, 0); // u表示正在处理字符串中的哪个按键
        return ans;
    }

    void dfs(string& digits, int u) {
        if (u == digits.size()) {
            ans.push_back(string(path.begin(), path.end()));
            return;
        }
        for (auto c: strs[digits[u] - '0']) // 当前按键所有可用字母各自属于一种可能性
        {
            path.push_back(c);
            dfs(digits, u + 1);
            path.pop_back();
        }
    }
};