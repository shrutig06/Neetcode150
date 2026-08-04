class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> maxHeap;
        for(int i=0;i<nums.size();i++){
            maxHeap.push(nums[i]);
        }
        int ans;
        for(int i=1;i<=k;i++){
            ans=maxHeap.top();
            maxHeap.pop();
            if(i==k) return ans;
        }
        return 0;
    }
};