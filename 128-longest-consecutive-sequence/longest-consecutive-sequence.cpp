class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int cnt = 0;
        int maxCnt = 0;
        for (auto x:s) {
            if (!s.count(x - 1)) {
                int curr = x;
                cnt = 1;
                curr++;
                while (s.count(curr)) {
                    cnt++;
                    curr++;
                }
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};