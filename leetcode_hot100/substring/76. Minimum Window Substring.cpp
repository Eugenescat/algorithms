class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mt, ms;
        // for (int i = 0; i < t.size(); t++) mt[t[i]] ++;
        for (auto x : t) mt[x] ++;

        string res;

        int cnt = 0; // 匹配的字符总数（注意这次不是match了）
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            ms[s[i]] ++;
            if (ms[s[i]] <= mt[s[i]]) cnt ++; // 实施了一个有效增加

            while (ms[s[j]] > mt[s[j]]) // 把多余的j排挤出去
            {
                ms[s[j]] --;
                j ++;
            }
            
            // 如果满足条件且窗口更小，更新答案
            if (cnt == t.size() && (!res.size() || i - j + 1 < res.size())) res = s.substr(j, i - j + 1); 
        }
        return res;
    }
};