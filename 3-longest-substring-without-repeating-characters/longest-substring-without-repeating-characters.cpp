class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==1) return 1;
        vector<int> charCount(256, 0);
        int l = 0, r = 0, maxLen = 0;
        while (r < s.length()) {
            charCount[(unsigned char)s[r]]++;
            if (charCount[(unsigned char)s[r]] > 1) {
                while (l<s.length() && charCount[(unsigned char)s[r]]>1) {
                    charCount[(unsigned char)s[l]]--;
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