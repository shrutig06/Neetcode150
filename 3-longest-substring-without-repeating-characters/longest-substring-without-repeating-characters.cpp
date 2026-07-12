class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        vector<bool> vis(100, false);
        int maxCnt = 0;
        while (right < s.length()) {
            while(vis[s[right]]){
                vis[s[left]]=false;
                left++;
            }

            vis[s[right]]=true;
            maxCnt=max(maxCnt, right-left+1);
            right++;
        }

        return maxCnt;
    }
};