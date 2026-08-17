class Solution
{
public:
    int maxSubstrings(string word)
    {

        int n = word.size();
        vector<vector<int>> locations(26);
        vector<int> dp(n + 1, 0); // 0 ~ n

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            char cur = word[i - 1];
            auto &loc = locations[cur - 'a'];
            dp[i] = dp[i - 1]; // 继承

            // 从后往前遍历，只考虑最近一次字母出现的合法位置
            for (int idx = loc.size() - 1; idx >= 0; idx--)
            {
                int j = loc[idx];
                if ((i - j + 1) >= 4)
                {
                    dp[i] = max(dp[i], dp[j - 1] + 1);
                    break;
                }
            }

            ans = max(ans, dp[i]);
            locations[cur - 'a'].push_back(i);
        }

        return ans;
    }
};