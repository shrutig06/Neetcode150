class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0, maxLen=0;
        unordered_map<char, int> mp;
        int maxFreq=0;
        while(r<s.length()){
            mp[s[r]]++;
            maxFreq=max(maxFreq, mp[s[r]]);
            while(r-l+1-maxFreq>k){
                mp[s[l]]--;
                // maxFreq=max(maxFreq, mp[s[l]]);
                l++;
            }
            maxLen=max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};