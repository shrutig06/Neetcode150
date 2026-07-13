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

            string s;
            for (auto x : freq) {
                s += to_string(x);
                s += "#";
            }

            mp[s].push_back(str);
        }

        for (auto it : mp) {
            vector<string> v = it.second;
            res.push_back(v);
        }
        return res;
    }
};