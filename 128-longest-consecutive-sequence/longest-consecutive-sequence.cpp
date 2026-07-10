class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int cnt = 0;
        int maxCnt = 0;
        for (auto x : s) {
            if (s.find(x - 1) == s.end()) {
                cnt = 1;
                while (s.find(x + 1) != s.end()) {
                    cnt++;
                    x++;
                }
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};