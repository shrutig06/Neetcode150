class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charCount(256,0);
        int l=0, r=0, maxLen=0;

        while(r<s.length()){
            charCount[s[r]]++;
            while(charCount[s[r]]>1){
                charCount[s[l]]--;
                l++;
            }
            maxLen=max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};