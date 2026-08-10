class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       vector<int> freq1(26,0), freq2(26,0);
        int k = s1.length(); // window size
        int l=0, r=0;
        for (auto x : s1)
            freq1[x-'a']++;

        while (r < s2.length()) {
            freq2[s2[r]-'a']++;
            while (r - l + 1 > k) {
                freq2[s2[l]-'a']--;
                l++;
            }
            if(r-l+1==k && freq2==freq1) return true;
            r++;
        }
        return false;
    }
};