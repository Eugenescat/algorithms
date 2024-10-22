class Solution {
public:
    // 思路：把所有字符串按照sort得到key存入哈希表
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto& str: strs)
        {
            string nstr = str;
            sort(nstr.begin(), nstr.end());
            hash[nstr].push_back(str);
        }
        vector<vector<string>> res;
        for (auto& item: hash) res.push_back(item.second);
        return res;
    }
};