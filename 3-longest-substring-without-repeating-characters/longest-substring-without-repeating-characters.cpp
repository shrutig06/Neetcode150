class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==1) return 1;
        vector<int> charCount(256, 0);
        int l = 0, r = 0, maxLen = 0;
        while (r < s.length()) {
            charCount[s[r]]++;
            if (charCount[s[r]] > 1) {
                while (charCount[s[r]]>1) {
                    charCount[s[l]]--;
                    l = l + 1;
                }
            } else{
                 maxLen = max(maxLen, r - l+1);
            }
            r++;
        }

        return maxLen;
    }
};