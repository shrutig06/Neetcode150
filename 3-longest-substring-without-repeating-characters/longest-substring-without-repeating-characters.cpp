class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        vector<bool> vis(100, false);
        int maxCnt = 0;
        while (right < s.length()) {
            if (!vis[s[right]]) {
                vis[s[right]] = true;
                maxCnt = max(maxCnt, right - left + 1);
                right++;
            } else if (vis[s[right]]) {
                while (left < right) {
                    if (vis[s[left]]) {
                        vis[s[left]] = false;
                        left++;
                        break;
                    } else {
                        vis[s[left]] = false;
                        left++;
                    }
                }
            }
        }

        return maxCnt;
    }
};