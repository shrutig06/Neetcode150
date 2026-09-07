class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen=0;
        unordered_map<char,int> umap;
        int i=0;
        for(int j=0;j<s.length();j++){
            umap[s[j]]++;
            while(umap[s[j]]>1){
                umap[s[i]]--;
                if(umap[s[i]]==0) umap.erase(s[i]);
                i++;
            }
            maxLen=max(maxLen, j-i+1);
        }

        return maxLen;
    }
};