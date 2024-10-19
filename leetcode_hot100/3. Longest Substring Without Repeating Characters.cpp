class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 思路：以i为右顶点，维护一个没有重复字符的哈希表
        unordered_map<char, int> map;
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            map[s[i]] ++;
            // 如果加入了一个重复的字符，j向右移动，直到删除这个重复字符第一次出现的位置
            while (map[s[i]] > 1)
            {
                map[s[j]] --;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};