class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1);
        dp[0] = true; // 0长度的字符一定满足空背包
        // i=1~size()
        for (int i = 1; i <= s.size(); i ++) {
            for (int j = 0; j <= i; j ++) {
                string word = s.substr(j, i-j); // 左闭右开，不含当前j
                if (wordSet.count(word) && dp[j]) dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};