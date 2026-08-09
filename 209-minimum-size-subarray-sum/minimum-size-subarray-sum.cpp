class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, end = 0, sum = 0, minLen = INT_MAX;

        while (end < nums.size()) {
            sum += nums[end];
            while (sum >= target) {
                minLen = min(minLen, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};