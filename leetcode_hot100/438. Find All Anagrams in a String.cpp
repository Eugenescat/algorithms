class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 思路：双指针维护一个子串的哈希表，如何快速判断当前维护的哈希表和题给的短串一致
        // 额外需要维护一个数保存哈希表里一共成功存了多少“种”字符
        unordered_map<char, int> map;
        vector<int> res;
        for (auto c : p) map[c] ++; // 把子串存入哈希表
        int tot = map.size();
        int match = 0;
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            map[s[i]] --; // 杀掉一个
            if (map[s[i]] == 0) match ++;
            if (i - j + 1 > p.size())
            {
                if (map[s[j]] == 0) match --;
                map[s[j]] ++; // 起死回生
                j ++;
            }
            if (match == tot) res.push_back(j);
        }
        return res;
    }
};