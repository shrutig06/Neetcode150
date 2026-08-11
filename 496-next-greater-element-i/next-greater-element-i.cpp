class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<pair<int,int>> st;
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top().first<=nums2[i]){
              st.pop();
            }
            if(st.empty()){
                mp.insert({nums2[i], -1});
                st.push({nums2[i],-1});
            }else{
                mp.insert({nums2[i], st.top().first});
                st.push({nums2[i],st.top().first});
            }
        }

        // for(auto x:mp){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        for(int i=0;i<nums1.size();i++){
           ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};