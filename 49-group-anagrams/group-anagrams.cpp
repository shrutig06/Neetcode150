class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;

        for (auto str : strs) {
            vector<int> freq(26, 0);
            for (auto c : str) {
                freq[c - 'a']++;
            }

            string key;
            for (auto x : freq) {
                key += to_string(x);
                key += "#";
            }

            mp[key].push_back(str);
        }

        for (auto &it : mp) {
            res.push_back(it.second);
        }
        return res;
    }
};